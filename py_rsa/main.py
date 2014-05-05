#!/usr/bin/python3

import rsa

# Necessary components
#
# Message
# Private key
# Public key


def main():
	pubkey, privkey = rsa.keygen()
	msg = input("What message should be encrypted: ")

	print ("Public Key:", rsa.key_to_str(pubkey))
	print ("Private key:", rsa.key_to_str(privkey))
	
	cipher = rsa.encode(msg, pubkey)
	print (cipher)

	decrypted = rsa.decode(cipher, privkey)
	print (decrypted)

if __name__ == '__main__':
	main()
