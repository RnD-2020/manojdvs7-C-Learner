/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void swap(char* C1, char* C2)
{
	char temp = *C1;
	*C1 = *C2;
	*C2 = temp;
}
void reverseWords(char* input,int len)
{
	int l = 0, r = len - 1;
	while (l < r)
	{
		swap(&input[l], &input[r]);
		l++;
		r--;
	}
}

void reverseWord(char* input, int l, int r)
{
	while (l < r)
	{
		swap(&input[l], &input[r]);
		l++;
		r--;
	}
}

void reverseEachWord(char* input, int len)
{
	int l = 0, r = 0;
	while (r <= len)
	{
		if (input[r] == ' ' || input[r] == '\0')
		{
			reverseWord(input, l, r-1);
			l = r+1;
		}
		r++;

	}
}
void str_words_in_rev(char *input, int len){
	reverseWords(input, len);
	reverseEachWord(input, len);
}
