/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
	EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
	EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci() 
		 nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/

int nthFibonacci(int n)
{
	if (n <= 0)
		return -1;
	int ll = 0;
	int ul = 1;
	int i ;
	if (n == 1)
		return ll;
	if (n == 2)
		return ul;
	for (i = 3; i <= n; i++)
	{
		int temp = ll;
		ll = ul;
		ul = ul + temp;
	}
	return ul;
}
int isprime(int n)
{
	int count = 2;
	for (int i = 2; i <= n/2; ++i)
	{
		if (n%i == 0)
			count++;
	}
	if (count == 2)
		return 1;
	else
		return 0;
}
int nthPrime(int num)
{
	if (num <= 0)
		return -1;
	int num1 = 2;
	while (num)
	{
		if (isprime(num1))
			num--;

		num1++;
	}
	return --num1;
}
