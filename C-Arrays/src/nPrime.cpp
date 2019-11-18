
/*
OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7] 

INPUTS: An Integer N

OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)

ERROR CASES: Return NULL for invalid inputs

Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}
NOTES:

Try to think of a optimized way , and avoid unnecessary comparisons.
*/
#include<stdlib.h>
#include <stdio.h>
int isdivisible(int prime[], int i, int len)
{
	int k = 1;
	for (k = 1; k < len; k++)
	{
		if (i%prime[k] == 0)
			return 0;
	}
	return 1;
}
int* nPrime(int N)
{
	if (N <= 0)
		return NULL;
	int i = 3, j = 0;
	int *prime = (int *)calloc(1, sizeof(int));
	prime[j++] = 2;
	for (i = 3; i <= N; i = i + 2)
	{
		if (isdivisible(prime, i, j))
		{
			prime = (int *)realloc(prime, (j + 1) * sizeof(int));
			prime[j++] = i;
		}
	}

	return prime;
}