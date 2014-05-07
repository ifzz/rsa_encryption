#include "miller-rabin.h"

/**
 * miller-rabin
 * File: miller-rabin.c
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 07 2014
 */

#define true 1
#define false 0


long long mulmod(long long a, long long b , long long c)
{
    long long x=0,y=a%c;
    while(b>0)
    {
        if(b & 1)
        {
            x = (x+y)%c;
        }
        y=(y*2)%c;
        b>>=1;
    }
    return x%c;
}
long long modulo(long long a,long long b,long long c)
{
    long long y=a,x=1;
    while(b>0)
    {
        if(b & 1)
        {
            x = mulmod(x,y,c);
        }
        y = mulmod(y,y,c);
        b>>=1;
    }
    return x%c;
}

int miller(long long p,int iterations)
{
    if(p<2) return false;
    if(p!=2 && p%2==0) return false;
    long long s = p-1;
    while(s%2==0) s /= 2; 
    int i;
    for( i=0; i<iterations; i++)
    {
        long long a = rand()%(p-1)+1,temp=s;
        long long mod = modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1)
        {
            mod = mulmod(mod,mod,p);
            temp*=2; 
        }
        if(mod!=p-1 && temp%2==0) return false;
    }
    return true;
}
