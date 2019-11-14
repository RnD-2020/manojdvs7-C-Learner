/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
#include <stdlib.h>

int findMaxLen(int *Arr,int len)
{
	int max = Arr[0];
	for (int i = 1; i < len; i++)
	{
		if (max < Arr[i])
			max = Arr[i];
	}
	return max;
}

int removeArrayDuplicates(int *Arr, int len)
{
	if (Arr == NULL || len <= 0)
		return -1;
	int max = findMaxLen(Arr, len);
	int pos = 0;
	int *hashTable = (int *)calloc(max+1, sizeof(int));
	for (int i = 0; i < len; i++)
	{
		if (hashTable[Arr[i]] == 0)
		{
			Arr[pos++] = Arr[i];
			hashTable[Arr[i]] = 1;
		}
	}
	return pos;
}
