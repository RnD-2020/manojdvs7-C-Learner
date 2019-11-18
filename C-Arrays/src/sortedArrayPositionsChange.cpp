/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

Problem Code :SAP
*/

#include <stdio.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr == NULL || len <= 0)
		return NULL;
	int pos1, pos2;
	for (pos1 = 0; pos1 < len-1; pos1++)
	{
		if (Arr[pos1] > Arr[pos1 + 1])
		{
			pos2 = pos1 + 1;
			while (Arr[pos1 + 1] <= Arr[pos2])
				pos2++;
			break;
		}
		
	}
	if (pos1 < len - 1)
		swap(&Arr[pos1], &Arr[pos2]);
}