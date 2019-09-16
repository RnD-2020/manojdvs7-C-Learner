/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for 
  octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.

2)Write a function which takes a fractional octal number as input and returns the hexadecimal number for 
octalToHexadecimalFraction() until precision two
E.g.: octalToHexadecimal(6.01) returns 6.04

INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>
#include<math.h>
int convertToDec(int num)
{
	int octtemp = num, dec = 0;
	for (int i = 0; octtemp != 0; i++)
	{
		dec += (octtemp % 10)*pow(8, i);
		octtemp /= 10;
	}
	return dec;
}
int octalToHexadecimal(long int num)
{
	if (num <= 0)
	{
		return 0;
	}
	int dec = convertToDec(num);
	int thex=0,hex=0;
	while (dec!=0)
	{
		thex = thex*10 + dec % 16;
		dec = dec / 16;
	}
	while (thex!=0)
	{
		hex = hex * 10 + (thex % 10);
		thex = thex / 10;

	}
	return hex;
	//return  octalToHexadecimal(dec / 16) * 10 + (dec % 16);

}

float octalToHexadecimalFraction(float num)
{
	return 0.0;
}