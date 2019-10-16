/*
Given an integer as input return it's butterfly number
for example N= 1234
then it's you have to return 12344321 as output
return -1 if it is not possible create a butterfly number for the given input
*/
long long butterFlyNumber(long long N)
{
	if (N < 0)
		return -1;
	long long bf = N;
	int i = 0;
	while (N)
	{
		bf = bf * 10 + (N % 10);
		N = N / 10;
		i++;
	}
	if (i >= 9)
		return -1;
	return bf;
}