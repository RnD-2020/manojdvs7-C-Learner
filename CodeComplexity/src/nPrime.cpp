/*

Here you will be doing the same ArraysQuestion you did before, but now in multiple ways.

OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7]
INPUTS: An Integer N
OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)
ERROR CASES: Return NULL for invalid inputs
Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}

Observations: (Write down what you observed here):

Way 1 :We are checking if all the numbers <N is prime or not eventhough we know all prime numbers are odd except 2.

Way 2 :We avoided checking for even numbers <N as we know we know all prime numbers are odd except 2.

Way 3:We are checking if a number is divisible by primes less than that number.If it is divisible by any of the primes,it is not a prime number.

Conclusion :
*/

#include <stdio.h>
#include <math.h>
#include<stdlib.h>

/*

Manually loop over every element, Find if its prime or not. Store it in an array.
Write the worst complexity code you can write :D.
*/
int isprime(int n)
{
	int count = 1;
	for (int i = 2; i <= n; i++)
	{
		if (n%i == 0)
			count++;
	}
	if (count == 2)
		return 1;
	return 0;
}

int* nPrimeBruteForce(int N)
{
	int i = 3, j = 0;
	int *prime = (int *)calloc(1, sizeof(int));
	prime[j] = 2;
	j = 1;
	for (i = 3; i <= N; i++)
	{
		if (isprime(i))
		{
			prime = (int *)realloc(prime, (j+1) * sizeof(int));
			prime[j++] = i;

		}
	}
	return prime;
}

/*
Remove even numbers, Run it again.
Just remove even numbers. So it should essentially take half of time for function 1, Did it really happened?

*/
int* nPrimeEvenRemoved(int N)
{

	int i = 3, j = 0;
	int *prime = (int *)calloc(1, sizeof(int));
	prime[j] = 2;
	j = 1;
	for (i = 3; i <= N; i=i+2)
	{
		if (isprime(i))
		{
			prime = (int *)realloc(prime, (j + 1) * sizeof(int));
			prime[j++] = i;

		}
	}
	return prime;
}

/*
Do all optimizations you can think of.

Hint : 
A number can be considered a prime, if its not divisible by any of the primes which are less than it.
ie 100 can be considered as a prime, if no prime number which is less than 100 divides 100 (With remainder as 0).
7 is prime as no prime less than it (2,3,5) can divide it. Think proof for this too.

This heavily reduces the number of divisions you do. If you did correctly you should see some heavy difference in timings.

*/
int isdivisible(int prime[], int i,int len)
{
	int k = 1;
	for (k = 1; k < len; k++)
	{
		if (i%prime[k] == 0)
			return 0;
	}
	return 1;
}
int* nPrimeOptimized(int N)
{
	int i = 3, j = 0 ;
	int *prime = (int *)calloc(1, sizeof(int));
	prime[j++] = 2;
	for (i = 3; i <= N; i = i + 2)
	{
		if (isdivisible(prime,i,j))
		{
			prime = (int *)realloc(prime, (j + 1) * sizeof(int));
			prime[j++] = i;
		}
	}

	return prime;
}