/*
Here you will compare 2 searching algorithms.

LinearSearch and BinarySearch

Question :
Given an Array and its length and a key element, return the index (Where key is found) if key is found in array
or -1 if key is not found.

Sample Input : 
[1,2,3,4,5] Key : 4, Returns 3
[0,49,22] Key : 212, Returns -1

Observations: (Write down what you observed here, Run for various variations):

Linear Search:It takes more time than binary search because we comparing each and every element from first to last.O(n) is worst case complexity.

Binary Search :It takes less time than linear search beacuse we are soring, finding the range of search element in the array and then searching for it.O(logn) is worst case complexity.

Conclusion :
*/

int linearSearch(int *arr, int len, int key) {
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == key)
			return i;
	}

	return -1;
}

int recursiveBS(int *arr,int l,int r,int x)
{
	int mid =  (r + l) / 2;

	if (arr[mid] == x) 
		return mid;
 
	if (arr[mid] > x)
		return recursiveBS(arr, l, mid - 1, x);

	else 
		return recursiveBS(arr, mid + 1, r, x);

	return -1;
}

int binarySearch(int *arr, int len, int key) {
	//Use this function as wrapper function,if you are implementing bs recursively.
	return recursiveBS(arr, 0, len, key);
}