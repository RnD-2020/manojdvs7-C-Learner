/*
OVERVIEW: 
1)Write a function which takes a decimal number as input and returns the octal number for decimalToOctal().
E.g.: decimalToOctal(10) returns 12.

2)Write a function which takes a fractional decimal number as input and returns the octal number for decimalToOctalFraction()
until precision two
E.g.: decimalToOctal(6.06) returns 6.03

INPUTS: Single decimal number num;

OUTPUT: Octal value of the Decimal Number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>

int decimalToOctal(int num)
{
	if (num <= 0)
		return 0;
	return decimalToOctal(num / 8)*10+(num%8);
}

float decimalToOctalFraction(float num)
{
	if (num <= 0)
		return 0;
	float dec ;
	int Int = (int) num;
	dec = num-Int;
	
	float oct = decimalToOctal(num);
	int i;
	for (i = 0; i < 3; i++)
	{
		oct = oct + (int)(dec * 8) / 10;
		Int = (int)dec * 8;
		dec = dec * 8 - Int;
	}

	return oct;
}

