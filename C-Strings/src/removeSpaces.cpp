/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include <stdio.h>
char removeSpaces(char *str) {
	if (str == NULL)
		return '\0';
	int count = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			str[count] = str[i];
			count++;
		}
		i++;
	}
	str[count] = '\0';
}
