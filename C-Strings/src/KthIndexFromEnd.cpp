/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<stdio.h>
int findLen(char *str)
{
	int len = -1;
	int i = 0;
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return len;
}
char KthIndexFromEnd(char *str, int K) {

	if (str == NULL || str == ""|| K<0)
		return '\0';

	int len = findLen(str);

	return str[len - K];
}