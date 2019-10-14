//
//  E01_Functions.cpp
//  Unit1_exercise1_understanding_functions
//

/*
 
 Note:
 Implement the functions in this exercise file to make the tests
 pass in E01_FunctionsSpec.cpp file.
 
 */


//
// Note:
//  Think of all the edge cases.
//
// returns the mid-point of
// given 2 points on X-axis
//
int midPoint(int x1, int x2) {
	//long long int mid=(x1+x2)/2;
	int mid1, mid2;
	mid1 = x1 / 2;
	mid2 = x2 / 2;
	if(x1%2!=0 && x2%2!=0)
		return mid1 + mid2+1;
	else if(x1 % 2 != 0 || x2 % 2 != 0)
	{
		return mid1 + mid2 + 0.5;
	}
	return mid1 + mid2;
}

//
// sum of most significant digits of non-negative integers.
//
int sumOfMSDs(int num1, int num2) {
	int sd1=0, sd2=0;
	while (num1 != 0 || num2 != 0)
	{
		if (num1 % 10 != 0)
			sd1 = num1 % 10;
		if (num2 % 10 != 0)
			sd2 = num2 % 10;
		num1 = num1 / 10;
		num2 = num2 / 10;
	}
    return sd1+sd2;
}

//
// sum of two 100 digit positive numbers
//
void sumOf100DigitNumbers(int num1[100], int num2[100], int sum[101]) {
	int carry = 0,i,sum1=0,j=100;
	for (i = 99,j=100; i >= 0 ; i--,j--)
	{
		 sum1 = num1[i] + num2[i] + carry;
		 if (sum1 >= 10)
		 {
			 sum[j] = sum1 % 10;
			 carry = sum1 / 10;
		 }
		 else
		 {
			 sum[j] = sum1;
			 carry = 0;
		 }
	}
	sum[0] = carry;
}

//
// product of two 100 digit positive numbers
//
void productOf100DigitNumbers(int num1[100], int num2[100], int prod[200]) {

	int carry = 0, i, j, col = 199, prod1, count = 0, sum1 = 0, row = 0;
	int sum[100][200] = { 0 };
	for (i = 99; i >= 0; i--)
	{
		count = 99 - i;
		carry = 0;
		col = 199;
		while (count != 0)
		{
			//sum[i][k] = 0;
			count--;
			col--;
		}
		for (j = 99; j >= 0; j--, col--)
		{
			prod1 = (num1[j] * num2[i]) + carry;

			if (prod1 >= 10)
			{
				sum[row][col] = prod1 % 10;
				carry = prod1 / 10;
			}
			else
			{
				sum[row][col] = prod1;
				carry = 0;
			}
		}
		sum[row][col] = carry;
		row++;

	}
	int k = 199, l = 99;
	carry = 0;
	for (i = 199; i >= 0; i--)
	{
		sum1 = 0;
		for (j = 99; j >= 0; j--)
		{
			sum1 = sum1 + sum[j][i];
		}
		sum1 = sum1 + carry;
		if (sum1 >= 10)
		{
			prod[k] = sum1 % 10;
			carry = sum1 / 10;
			k--;
		}
		else
		{
			prod[k] = sum1;
			carry = 0;
			k--;
		}
	}
}
