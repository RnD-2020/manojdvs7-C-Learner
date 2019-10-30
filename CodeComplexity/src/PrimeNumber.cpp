/*
Problem Code : ISPRIME

In this lesson you will write 3 ways of how to find a prime number and then note down its performances.

Question : Given a number return 1 if its a prime number ,0 otherwise.

Dont try to over optimize soultion unless asked. Write bad code its okay. The purpose of this lesson is to learn
how bad code effects the time taken for running.

Observations: (Write down what you observed here):

Way 1 :We are checking the count of factors from 1 to N. 

Way 2 :We are checking the count of factors from 1 to sqrt(N).

Way 3:We are checking the count of factors from 3 to sqrt(N) ignoring even numbers as no even number can divide an odd number.

Conclusion : 
*/

#include <stdio.h>
#include <math.h>

/*
Divide the number with all elements from  1 to number and check whether its prime number or not.
Dont do any optimizations. Just write the brute force code.
*/
int isPrimeBruteForce(int number){
	int count = 0;
	for (int i = 1; i <= number; i++)
	{
		if (number%i == 0)
			count++;
	}
	if (count == 2)
		return 1;
	return 0;
}

/*
Is checking division till number neccesary? 

You can do it just till half of number or even better just square root of n.

Divide the number with all elements from  1 to sqrt(number) and check whether its prime number or not.
Dont do any more optimizations.

Think why is it sufficient to do it till just square root of number.
*/
int isPrimeSquareRoot(int number){
	int sroot = (int)sqrt(number);
	int count = 0;
	for (int i = 1; i <= sroot; i++)
	{
		if (number%i == 0)
			count++;
	}
	if (count <= 2)
		return 1;

	return 0;
}

/*
Add more optimizations you like, 
Like if a number is odd number you need not divide it with even numbers. etc.
*/
int isPrimeOptimized(int number){
	if (number % 2 == 0)
		return 0;
	int sroot = (int)sqrt(number);
	int count = 1;
	for (int i = 3; i <= sroot; i = i + 2)
	{
		if (number%i == 0)
			count++;
	}
	if (count == 1)
		return 1;

	return 0;
}


