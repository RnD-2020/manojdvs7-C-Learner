/*
Given an array of integers, return the two numbers such that they add up to a specific target.

You may assume that each input will have exactly one solution. Return NULL for invalid inputs

Given nums = [1, 20, 2, 4], target = 24,

Because nums[1] + nums[3] = 20 + 4 = 24,
return [4, 20]. (Always the first number should be less in final answer)

If target is 5 ,Return [1,4]
If target is 22 ,return [2,20]

Note :
Return_Array[0] should always be less than/equal to Return_Array[1]

Constraints :
len <100000
-100000< nums[i] <100000

Question Source Link : https://leetcode.com/problems/two-sum/
We Picked this standard problem from Online , as its a very famous one and you will get habituated on solving on
Leetcode .

You need to solve this question in 3 ways.And measure time for each way.

Observations: (Write down what you observed here):

Way 1 :The brute force method is the naive method which takes O(n*n) time.

Way 2 :This needs a sorted array to find the two numbers which sum up to a target.This also reduces computations as the array is sorted. 

Way 3:Even though this method uses an extra array,this method is really efficient.We use hashing in this method.The number of computations are even more less because we use hash array to search for a number and we check till the target index in hash table.

Conclusion :It is really efficient to use hashing for searching an element in an array.
*/
#include <stdio.h>
#include <stdlib.h>
#include<algorithm>
using namespace std;
/*
Take each element, Sum with all other elements.
Repeat it with all elements.

What is the complexity of this method ? ____O(n*n)______
*/
void swapNumbers(int *num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
int* sumoftwoBF(int *nums, int target, int len){
	if (nums == NULL)
		return NULL;
	if (len <= 0)
		return NULL;
	int* result = (int *)calloc(2, sizeof(int));
	for (int i = 0; i < len-1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if ((nums[i] + nums[j]) == target)
			{
				result[0] = nums[i];
				result[1] = nums[j];
			}
		}
	}
	if (result[0] > result[1])
	{
		swapNumbers(&result[0], &result[1]);
	}
	return result;
}

/*
Sort the array first. Preferably using quicksort/mergesort. (nlogn)

Now the array is sorted, Can you do improve the above method.

Hint: 
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11. 

Lets say we added 3+12 first, whats the sum, Its 15 right ? Its greater than 11.So should we next add 
so that total sum will become less. 

What is the complexity of this method ? ____O(n)(exluding the sort() function)______
*/
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int *Left = (int*)calloc(n1, sizeof(int));
	int *Right = (int*)calloc(n1, sizeof(int));

	for (i = 0; i < n1; i++)
		Left[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		Right[j] = arr[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l;  
	while (i < n1 && j < n2)
	{
		if (Left[i] <= Right[j])
		{
			arr[k] = Left[i];
			i++;
		}
		else
		{
			arr[k] = Right[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = Left[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = Right[j];
		j++;
		k++;
	}
}


void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
int* sumoftwoSortAndSearch(int *nums, int target, int len){
	if (nums == NULL || len <= 0)
		return NULL;
	//Sort the array
	sort(nums, nums + len);
	//Do the task
	int *result = (int *)calloc(2, sizeof(int));
	int i = 0;
	int j = len - 1;
	while (i<j)
	{
		if (nums[i] + nums[j] == target)
		{
			result[0] = nums[i];
			result[1] = nums[j];
			break;
		}
		(nums[i] + nums[j] < target) ? i++ : j--;
	}
	
	return result;
}


/*

Array contains only integers from 1-100; Can you use this range restriction and an extra array to 
find 2Sum even more faster

Hint:
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11.

If we are at 3, What number we need to tell that 3 is in final answer? 8 right (11-3 = 8). So some how we need to find a way
to know whether 8 is already in the array or not.As of now we dont know that, we will store 3 somewhere
(Which can be accesible in O(1)) and move to next element. 4 is there, we need to know whether array has 7 or not.(11-4 =7)
We dont know that yet, we move on ...we will store 4 somewhere now.

We go on till 7(4th element). We reach here we require 4 (11-7 = 4) .We already know 4 is present in array. (With O(1)).
We immediately return the answer. Think and discuss with your friends.

You are expected to solve this method in O(n)
*/
int* sumoftwoExtraArray(int *nums, int target, int len) {
	//Initialise the array
	//Do the task
	if (nums == NULL || len <= 0)
		return NULL;
	int *result = (int *)calloc(2, sizeof(int));
	int max = nums[0];
	for (int i = 1; i < len; i++)
	{
		if (max < nums[i])
			max = nums[i];
	}
	int *hashTable = (int *)calloc(max+1, sizeof(int));
	for (int i = 0; i < len; i++)
	{
		hashTable[nums[i]] = hashTable[nums[i]] + 1;
	}
	for (int i = 0; i < target; i++)
	{
		int diff = target - i;
		if (hashTable[i] > 0)
		{
			if (hashTable[diff] > 0)
			{
				result[0] = i;
				result[1] = diff;
				break;
			}
		}
	}
	return result;
}


