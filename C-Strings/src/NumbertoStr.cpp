/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

int findNumberOfDigits(int n)
{
	int len = 0;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return len;
}

void storeNumber(char* str, int num, int pos)
{
	if (num == 0)
		return;

	storeNumber(str, num / 10, pos - 1);
	str[pos] = (num % 10) + '0';
}

int storeDecimal(float decimal, char* str, int afterdecimal, int pos)
{
	str[pos++] = '.';
	int j = 1;
	str[pos++] = (decimal*pow(10, j)) + '0';
	for (j = 2; j <= afterdecimal; j++)
	{
		int temp1 = decimal*pow(10, j);
		int temp2 = (decimal*pow(10, j - 1));
		temp1 = temp1 - (temp2 * 10);
		str[pos++] = temp1 + '0';
	}
	return pos;
}

void number_to_str(float number, char *str, int afterdecimal) {

	int integer = (int)number;
	float decimal = number - integer;
	int len = findNumberOfDigits(number);
	int pos = len;
	if (number < 0)
	{
		str[0] = '-';
		integer = (-1) * integer;
		decimal = (-1)*decimal;
		pos++;
	}
	if (number > 0)
		storeNumber(str, integer, --len);

	if (number < 0)
		storeNumber(str, integer, len);

	if (afterdecimal > 0)
		pos = storeDecimal(decimal, str, afterdecimal, len + 1);

	str[pos] = '\0';
}
