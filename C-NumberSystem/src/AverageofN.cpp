/*
Overview:
Given an array of N points 
calculate the average and return the value in interger type

don't change the function signature!
for invalid cases return -1
*/
#include<stdlib.h>

int averageOfN(int* arr, int N)
{
	if (arr == NULL || N<=0)
		return -1;
	long long sum=0;
	for (int i = 0; i < N; i++)
		sum = (sum + (*(arr + i)));
	return sum/N;
}