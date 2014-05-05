# Python rsa implementation
#
# Encryption
#
# Components
#
# public key generator
# Private key generator
# encoder
# decoder

from random import randrange
from fractions import gcd
from math import log
from collections import namedtuple
from binascii  import hexlify, unhexlify

# Definig Named tuples
KeyPair = namedtuple('KeyPair', 'public private')
Key = namedtuple('Key', 'exponent modulus')

def is_prime(n, k=30):
	'''Returns true if a number is prime, otherwise returns false
		uses Miller-Rabin_primality_test

		n is the number, k is the accuracy
		'''
	if n <= 3:
		return n == 2 or n == 3

	neg_one = n - 1
	
	# Covert n -1 to 2^s * d
	s, d = 0, neg_one
	while not d & 1:
		s, d = s + 1, d>>1 
	
	assert 2 ** s * d == neg_one and d & 1

	for i in range(k):
		a = randrange(2, neg_one)
		x = pow(a, d, n)
		if x in (1, neg_one):
			continue
		for r in range(1, s):
			x = x**2%n
			if x ==1: return False
			if x == neg_one: break
		else:
			return False
	return True

def rand_prime(n = 10**8):
	'''Generates a random between 0 and n'''
	p = 1
	while not is_prime(p):
		p = randrange(n)
	return p

def get_totient(p, q):
	'''Returns the totient of two prime numbers'''
	return (p-1)*(q-1)

def extended_gcd(a, b):
	'''Finds the extended gcd of two numbers'''
	# Algorithm taken from 
	# http://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
	s = 0
	old_s = 1
	t = 1
	old_t = 0
	r = b
	old_r = a
	while r != 0:
		q = old_r // r
		old_r, r = r, old_r - (q * r)
		old_s, s = s, old_s - (q * s)
		old_t, t = t, old_t - (q * t)
	#print ("Bézout coefficients:", old_s, old_t)
	#print ("Greatest common divisor:", old_r)
	#print ("Quotients by gcd:", t, s)

	if s == 0: 	
		print ("Division by zero")
		return 0
	if s == 1:
		return -t
	elif s > 0: return -t /s
	else: return (t/-s)

def multinv(modulus, value):
	x, lastx = 0, 1
	a, b = modulus, value
	while b:
		a, q, b = b, a // b, a % b
		x, lastx = lastx - q * x, x
	result = (1 - lastx * modulus) // value
	if result < 0:
		result += modulus
	assert 0 <= result < modulus and value * result % modulus == 1
	return result
	


def encode(msg, pubkey, verbose=False):
	'''Encodes a message using the public key'''
	# Alice transmits her public key to bob
	# Bob uses Alice's public key to encode the message
	# Bob then transmits that encoded message to Alice

	# We need to break it into blocks, then salt it

	block_size = int(log(pubkey.modulus, 256)) # A fun algorithm to get the block_length
	out_fmt = '%%0%dx' % ((block_size + 1) * 2, )
	bmsg = msg.encode()
	result = []
	for start in range (0, len(bmsg), block_size):
		block = bmsg[start:start+block_size]
		# This block may not be a full block
		# We need to add some salt to it
		block += b'\x00' * (block_size - len(block))
		plainform_b = hexlify(block)
		plainform = int(plainform_b, 16) # Convert the block to hex and then to integer type
		coded = pow(plainform, *pubkey)
		fmt_coded = (out_fmt % coded).encode()
		bcoded = unhexlify(fmt_coded)
		if verbose:
			print ('Encode:', block_size, block, plainform, coded, bcoded)
		result.append(bcoded)
	return b''.join(result)

def decode(ciphertext, privkey, verbose=False):
	'''Decodes a message using the private key'''
	# Alice recieves an encoded message from Bob
	# Alice uses private key to decode the message

	block_size = int(log(privkey.modulus, 256))
	out_fmt = '%%0%dx' % ((block_size + 1) * 2, )
	result = []
	for start in range (0, len(ciphertext), block_size + 1):
		bcoded = ciphertext[start: start + block_size + 1]
		coded = int(hexlify(bcoded), 16)
		plain = pow(coded, *privkey)
		block = unhexlify((out_fmt % plain).encode())
		if verbose:
			print ('Decode:', block_size, block, plain, coded, bcoded)
		result.append(block)
	return b''.join(result).rstrip(b'\x00').decode('utf-8')


def keygen(N = 2**32, public=True):
	'''Generates a key'''
	p = rand_prime(N)
	q = rand_prime(N)
	n = p * q
	totient = get_totient(p, q)
	if public:
		while True:
			private = randrange(totient)
			if gcd(private, totient) == 1:
				break
		public = multinv(totient, private)

	else:
		private = multinv(totient, public)
	assert public * private % totient == gcd(public, totient) == gcd(private, totient) == 1
	
	return KeyPair(Key(public, n), Key(private, n))

def str_to_key(key_str):
	'''Converts a string to a key'''
	return Key(*(int(number, 16) for number in key_str.split(':')))

def key_to_str(key):
	'''Coverts a key to a string'''
	return ':'.join((('%%0%dx' % ((int(log(number, 256)) + 1) * 2)) % number) for number in key)

