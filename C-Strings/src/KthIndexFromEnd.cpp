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
	int len;
	if (str != NULL)
		len = findLen(str);

	if (str == NULL || str == "" || K < 0 || K > len)
		return '\0';

	return str[len - K];
}
