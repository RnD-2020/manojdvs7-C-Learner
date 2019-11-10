
/*
OVERVIEW: Given an array of integers find the maximum possible sum formed by a positive and the negative
integer in the array.
Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1) 

INPUTS: An Integer array and the length of the array

OUTPUT: Maximum possible sum formed by a positive and the negative integer in the array

ERROR CASES: Return 0 for the invalid inputs

NOTES:
*/

#include <stdio.h>

int maxPosNegSum(int* input,int length)
{
	if(input==NULL || length<0)
		return 0;
	int maxn=input[0], maxp=input[0];
	if (maxn > 0)
	{
		for (int i = 0; i < length; i++)
		{
			if (input[i] < 0)
			{
				maxn = input[i];
				break;
			}

		}
	}
	for (int i = 1; i < length; i++)
	{
		if (input[i] > maxp)
			maxp = input[i];
		if (input[i] < 0)
		{
			if (input[i] > maxn)
				maxn = input[i];
		}

	}
	if (maxn > 0 || maxp < 0)
		return 0;
	return maxn + maxp;
}