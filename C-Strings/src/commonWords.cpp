/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include<string.h>
#include <malloc.h>

#define SIZE 31

char* getWord(char* str,int *pos)
{
	char* word = (char *)calloc(SIZE, sizeof(char));
	int ipos = 0;
	while (str[*pos]!=' ' && str[*pos] != '\0')
	{
		word[ipos++] = str[*pos];
		*pos = *pos + 1;
	}
	return word;
}

char ** commonWords(char *str1, char *str2) {
	int common = 0;
	char** result = NULL;
	int pos1 = 0, pos2 = 0;
	char* word1 = (char *)calloc(SIZE, sizeof(char));
	char* word2 = (char *)calloc(SIZE, sizeof(char));
	if (str1 != NULL && str2 != NULL)
	{
		while (str1[pos1] != '\0')
		{
			word1 = getWord(str1, &pos1);
			pos2 = 0;
			while (str2[pos2] != '\0')
			{
				word2 = getWord(str2, &pos2);
				if (strcmp(word1, word2) == 0)
				{
					common++;
					result = (char**)realloc(result, common * sizeof(char *));
					result[common - 1] = word2;
				}
				pos2++;
			}
			pos1++;
		}
	}
	return result;
}