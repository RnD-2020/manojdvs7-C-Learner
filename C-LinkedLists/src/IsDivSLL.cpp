/*
Problem Code : ISDIVSLL

You are Given an SLL where each Node has a character (which is picked from digits or '-'/'+') and a Key integer .
Example SLL : '1' -> '2' -> '3' -> '4'

You need to return 1 if the sum of numbers formed by (the SLL and reverse SLL) is divisible by key ,Return 0 otherwise . Return -1 for invalid cases  .

Sample Input :
SLL: '+'->'1'->'3'->'6'; (which is 136) and Key is 59 .

Sample Output :
1

If Key is 67 in the above example ,You should return 0 .

Explanation :
SLL is 136 , Reverse SLL is 631 . Sum is 631+136 = > 767 . 767 is divisible by 59 , So you should return 1 .

Constraints :

->Characters Range will be in from the following string "+-0123456789" .
->Length of SLL will be less than 10Nodes .
->0<=Key<=10000000
->First char need not defenetly be a sign , if its a digit ,it is considered as a positive number .

Note : Reverse of a negetive SLL is negetive only .And -963 can be divided by 3 .
*/

#include <stddef.h>
#include <malloc.h>
#include <stdio.h>

struct charNode{
	char letter;
	struct charNode *next;
};

long getReverse(struct charNode *head)
{
	if (head == NULL)
		return 0;
	return (getReverse(head->next) * 10 + ((head->letter) - '0'));
}

int getNumber(struct charNode *head, int key)
{
	struct charNode *temp=head;
	long number = 0;
	long reverse = 0;
	bool posflag = false;
	bool negflag = false;

	if (temp->letter == '-')
	{
		negflag = true;
		temp = temp->next;
	}
	if (temp->letter == '+')
	{
		posflag = true;
		temp = temp->next;
	}

	while (temp!=NULL)
	{
		number = number * 10 + ((temp->letter) - '0');
		temp = temp->next;
	}
	if (posflag || negflag)
	{
		reverse = getReverse(head->next);
		if (negflag)
		{
			number = number*(-1);
			reverse = reverse*(-1);
		}
	}
	else
		reverse = getReverse(head);

	if ((number + reverse) % key == 0)
		return 1;
	return 0;
}

int isDivisibleSLL(struct charNode * head, int key){
	if (head == NULL)
		return -1;
	 return getNumber(head, key);
}

