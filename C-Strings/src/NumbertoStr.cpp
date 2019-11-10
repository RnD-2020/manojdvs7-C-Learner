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

int i = -1;
void storeNumber(char* str, int num)
{
	if (num == 0)
		return;
	storeNumber(str, num / 10);
	str[++i] = (num % 10)+'0';
}

void storeDecimal(float decimal, char* str, int afterdecimal)
{
	str[++i] = '.';
	int j = 1;
	str[++i] = (decimal*pow(10, j))+'0';
	for (j = 2; j <= afterdecimal; j++)
	{
		int temp1 = decimal*pow(10, j);
		int temp2 = (decimal*pow(10, j - 1));
		temp1 = temp1 - (temp2 * 10);
		str[++i] = temp1+'0';
	}
}

void number_to_str(float number, char *str, int afterdecimal) {
	if (number < 0)
	{
		str[++i] = '-';
		number = (-1) * number;
	}
	int integer = (int)number;
	float decimal = number - integer;
	storeNumber(str, integer);
	if (afterdecimal > 0)
		storeDecimal(decimal, str, afterdecimal);
	str[++i] = '\0';
}
