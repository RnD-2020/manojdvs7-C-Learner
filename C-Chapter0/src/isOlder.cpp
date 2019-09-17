/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int stringComp(char* dob1, char* dob2)
{
	int i;
	for (i = 0; *(dob1 + i) != '\0' && *(dob2 + i) != '\0'; i++)
	{
		if (*(dob1 + i) > *(dob2 + i))
			return 2;
		else if (*(dob1 + i) < *(dob2 + i))
			return 1;
	}

	return 0;
}

bool checkValid(char* dob1,char* dob2)
{
		int yr=0;
		if (*dob1 > '3' || *dob2 > '3')
		{
			return false;
		}
		if (*(dob1 + 2) != '-' || *(dob2 + 2) != '-')
		{
			return false;
		}
		if (*(dob1 + 3) > '1' || *(dob2 + 3) > '1' || *(dob1 + 4) > '9' || *(dob2 + 3) > '9')
		{
			return false;
		}
		if ((*(dob1 + 3) == '1' && *(dob1 + 4) > '2') || (*(dob2 + 3) == '1' && *(dob2 + 4) > '2'))
		{
			return false;
		}

	/*	yr = (int) *(dob1 + 6);
		yr *= 10;
		yr += (int) *(dob1 + 7);
		yr *= 10;
		yr += (int) *(dob1 + 8);
		yr *= 10;
		yr += (int) *(dob1 + 9);
		if (yr > 2019)
		{
			return false;
		}*/
		return true;
}

int isOlder(char *dob1, char *dob2) {
	bool flag = checkValid(dob1, dob2);
	if (flag)
		return stringComp(dob1,dob2);
	else
		return -1;
}