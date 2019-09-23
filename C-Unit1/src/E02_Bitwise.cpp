//
//  E02_Bitwise.cpp
//  Unit1_exercise2_understanding_bitwise
//

/*
 
 Note:
 Implement the functions in this exercise file to make the tests
 pass in E02_BitwiseSpec.cpp file.
 
 Your primary goal is to implement all these functions by using
 bitwise operators only.
 
 */

int andOfEachByte(int n) {
	int result = n & 0xff;
	int i = 3;
	while (i != 0)
	{
		result = result & (n>>(8*i) & 0xff);
		i--;

	}
    return result;
}

//
// Note1:
// implement the function using bitwise operators only
// should not use * and + operators.
int numberFromBits(int bits[32]) {
	long long dec = 0;
	int i = 0, j = 31;
	while (j>=0)
	{
		dec = dec + (bits[j] << i);
		i++;
		j--;
	}

    return dec;
}

//
// Note2:
// implement the function using bitwise operators only
// should not use % and / operators.
void bitsFromNumber(int n, int bits[32]) {
	int i = 31,j = 0;
	while (i >= 0)
	{
		 int k = n >> i;
		 if (k & 1)
			 bits[j] = 1;
		 else
		 {
			 bits[j] = 0;
		 }
		 i--;
		 j++;

	}
}

//
// Note3:
// Refer this to understand how numbers are represented in binary format
// https://www.youtube.com/watch?v=qrUjFtZZWf4
// mainly how negative number are represented.
//
// implement this function by calling above bitsFromNumber function only.
//
int numberOfOnesInBinary(int n) {
	int count = 0, i;
	int bits[32];
	bitsFromNumber(n, bits);
	for (i = 0; i < 32; i++)
	{
		if (bits[i] == 1)
			count++;

	}
    return count;
}

//
// Returns
//  1 - yes
//  0 - no
//
#include<stdlib.h>
int isPalindromeInBase256(unsigned long int n) {
	unsigned long int rev;
	int b = n, i = 0, right, j;
	int len = 0;
	while (b) {
		b >>= 4;
		len++;
		if (len>8)
		{
			len = 8;
			break;
		}
	}
	int *arr = (int*)malloc(sizeof(int)*len);
	b = n;
	for (i = 0; i < len; i++)
	{
		right = (b >> (4 * i)) & 0xf;
		*(arr + i) = right;

	}
	for (i = 0, j = len - 1; i <= j; i++, j--)
	{
		if (*(arr + i) != *(arr + j))
			return 0;
	}
	return 1;
}
