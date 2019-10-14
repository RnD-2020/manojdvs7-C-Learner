
//
// Compute factorial of a given positive integer
// 0 <= n <= 100
//
// return value         - number of digits in n!
// factorialDigits[158] - digits of n!
//

int factorialOfN(int n, int factorialDigits[158]) {
	factorialDigits[0] = 1;
	int acount = 1, count;
	int j = 0, i, carry, temp;
	for (i = 2; i <= n; i++)
	{
		j = 0;
		carry = 0;
		for (count = 0; count < acount; count++)
		{
			int prod = factorialDigits[count] * i + carry;
			factorialDigits[count] = prod % 10;
			if (prod >= 10)
				carry = prod / 10;
			else
				carry = 0;
		}
		while (carry)
		{
			factorialDigits[acount++] = carry % 10;
			carry = carry / 10;
		}

	}
	return acount;
}


//
// recamán’s sequence: "subtract if you can, otherwise add"
//
// a(0) = 0; for n > 0, a(n) = a(n-1) - n if positive and
// not already in the sequence, otherwise a(n) = a(n-1) + n.
//
// http://oeis.org/A005132
//
// Write a function to find the first n numbers in this sequence
// n >= 0
//
// e.g:
// 0 => {0}
// 2 => {0, 1, 3}
// 5 => {0, 1, 3, 6, 2, 7}
//
// Note:
// The sequence will contain (n + 1) terms.
//
int check(int sequence[] ,int num ,int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (sequence[i] == num)
			return 0;
	}
	return 1;
}
void recamanSequence(int n, int sequence[]) {
	sequence[0] = 0;
	int i = 1,num=0;
	for (i = 1; i < n; i++)
	{
		num = sequence[i - 1] - i;
		if (num >= 0 && check(sequence, num, i))
			sequence[i] = num;
		else
			sequence[i] = sequence[i - 1] + i;
	}
}
