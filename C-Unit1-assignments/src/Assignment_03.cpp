//
// Every number repeats twice, except one number.
// Write a function that finds the number that does not repeat.
//
// e.g:
// {11, 8, 11}, 3  => 8
//
#include<stdlib.h>
int numberWithoutRepeatition(int numbers[], int size) {
	int max = numbers[0], min=numbers[0];
	int i;
	for (i = 1; i < size; i++)
	{
		if (numbers[i] > max)
			max = numbers[i];
		if (numbers[i] < min)
			min = numbers[i];
	}
	if (min < 0)
		min = min*(-1);
	int *countP = (int *)calloc(max+1, sizeof(int));
	int *countN = (int *)calloc(min + 1, sizeof(int));

	for (i = 0; i < size; i++)
	{
		if (numbers[i] >= 0)
			countP[numbers[i]]++;
		else
			countN[-1 * numbers[i]]++;
	}

	for (i = 0; i < max+1; i++)
	{
		if (countP[i] == 1)
			return i;
	}
	for (i = 0; i < min + 1; i++)
	{
		if (countN[i] == 1)
			return -1*i;
	}
    
	return 0;
}

//
// encode an array of numbers by doing
// XOR with n'th prime number
// and subtract 1
//
// output the encode numbers in encodedMessage[8] array.
//
// e.g:
// for 5'th prime
// encoding will be
// (message[i] ^ 11) - 1
// since 11 is the 5'th prime. // 2, 3, 5, 7, 11...
//
int isprime(int n)
{
	int count = 1;
	for (int i = 2; i <= n; i++)
	{
		if (n%i == 0)
			count++;
	}
	if (count == 2)
		return 1;
	return 0;
}
int nthPrime(int num)
{
	if (num <= 0)
		return -1;
	if (num == 1)
		return 2;
	if (num == 2)
		return 3;
	num = num - 2;
	int num1 = 4;
	while (num)
	{
		num1++;
		if (isprime(num1))
			num--;
	}
	return num1;
}
void encodeWithNthPrime(int message[8], int n, int encodedMessage[8]) {
	int prime = nthPrime(n);
	for (int i = 0; i < 8; i++)
	{
		encodedMessage[i] = (message[i] ^ prime) - 1;
	}
}

//
// decode an array of numbers in
// which are encoded using above encodeWithPrime function.
//
// output the decoded numbers in decodedMessage[8] array.
//
void decodeWithNthPrime(int message[8], int n, int decodedMessage[8]) {
	int prime = nthPrime(n);
	for (int i = 0; i < 8; i++)
	{
		decodedMessage[i] = (message[i] + 1) ^ prime;
	}
}

//
// Encode data and flags in packet header
//
// From Left to Right the data and flags are packed as follows:
// fromMobileId   - 7 bits
// toMobileId     - 7 bits
// msgId          - 7 bits
// msgLen         - 7 bits
// reserved       - 2 bits
// urgent         - 1 flag bit
// adHoc          - 1 flag bit
//
// Note:
// The values will be in the range
// 0 <= fromMobileId, toMobileId, msgId, msgLen <= 127
//
// The reserved bits should be set to zero.
//
// For the context refer:
// https://en.wikipedia.org/wiki/Transmission_Control_Protocol#TCP_segment_structure
//
unsigned int packHeader(int fromMobileId, int toMobileId, int msgId,
                        int msgLen, bool urgent, bool adHoc) {
	unsigned int reserved = 0;
	unsigned int pack = 0;
	pack = pack | (adHoc);
	pack = pack | (urgent << 1);
	pack = pack | (reserved << 2);
	pack = pack | (msgLen << 4);
	pack = pack | (msgId << 11);
	pack = pack | (toMobileId << 18);
	pack = pack | (fromMobileId << 25);
	return pack;
}

// unpack a given header, with the properties like the above
void unpackHeader(unsigned int header, int *pFromMobileId, int *pToMobileId,
                  int *pMsgId, int *pMsgLen, bool *pUrgent, bool *pAdHoc) {
	*(pAdHoc) = header & 0x1;
	*(pUrgent) = (header >> 1) & 0x1;
	*(pMsgLen) = (header >> 4) & 0x7f;
	*(pMsgId) = (header >> 11) & 0x7f;
	*(pToMobileId) = (header >> 18) & 0x7f;
	*(pFromMobileId) = (header >> 25) & 0x7f;
}
