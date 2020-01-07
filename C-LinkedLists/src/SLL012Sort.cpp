/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.

You should only change the links and shouldnt swap the data. Basically no write operation should be done on data field.

INPUTS:  SLL head pointer
OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2
ERROR CASES:
NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

/*
Optional : For this function swapping data is allowed.Although this wont be tested on our end.
It is only for learning purpose.
*/
void sll_012_sort_swapData(struct node **head){
	struct node* temp;
	temp = *head;
	struct node* select = temp;
	struct node* shift;
	while (select != NULL)
	{
		shift = select->next;
		while (shift != NULL)
		{
			if (select->data > shift->data)
			{
				int temp = select->data;
				select->data = shift->data;
				shift->data = temp;
			}
			shift = shift->next;
		}
		select = select->next;
	}
}

/*
This is the actual function. You are supposed to change only the links.
*/
void getHead(struct node **head,struct node *zeros, struct node *firstzero, struct node *ones, struct node *firstone, struct node *twos, struct node *firsttwo)
{
	if (zeros == NULL)
	{
		if (ones == NULL)
		{
			*head = firsttwo;
			twos->next = NULL;
		}
		else if (twos == NULL)
		{
			*head = firstone;
			ones->next = NULL;
		}
		else if (ones == NULL && twos == NULL)
			*head = NULL;
		else
		{
			ones->next = firsttwo;
			twos->next = NULL;
			*head = firstone;
		}
	}
	else if (ones == NULL)
	{
		if (zeros == NULL)
		{
			*head = firsttwo;
			twos->next = NULL;
		}
		else if (twos == NULL)
		{
			*head = firstzero;
			zeros->next = NULL;
		}
		else if (zeros == NULL && twos == NULL)
			*head = NULL;
		else
		{
			zeros->next = firsttwo;
			twos->next = NULL;
			*head = firstzero;
		}
	}
	else if (twos == NULL)
	{
		if (zeros == NULL)
		{
			*head = firstone;
			ones->next = NULL;
		}
		else if (ones == NULL)
		{
			*head = firstzero;
			zeros->next = NULL;
		}
		else if (zeros == NULL && ones == NULL)
			*head = NULL;
		else
		{
			zeros->next = firstone;
			ones->next = NULL;
			*head = firstzero;
		}
	}
	else
	{
		zeros->next = firstone;
		ones->next = firsttwo;
		twos->next = NULL;
		*head = firstzero;
	}
}
void sll_012_sort(struct node **head){
	struct node *zeros = NULL;
	struct node *ones = NULL;
	struct node *twos = NULL;
	struct node *firstzero = NULL;
	struct node *firstone = NULL;
	struct node *firsttwo = NULL;
	struct node *temp = *head;
	int count0 = 0, count1 = 0, count2 = 0;
	while (temp != NULL)
	{
		if (temp->data == 0)
		{
			if (count0 == 0)
			{
				zeros = temp;
				firstzero = temp;
			}
			else
			{
				zeros->next = temp;
				zeros = temp;
			}
			count0++;
		}
		else if (temp->data == 1)
		{
			if (count1 == 0)
			{
				ones = temp;
				firstone = temp;
			}
			else
			{
				ones->next = temp;
				ones = temp;
			}
			count1++;
		}
		else if (temp->data == 2)
		{
			if (count2 == 0)
			{
				twos = temp;
				firsttwo = temp;
			}
			else
			{
				twos->next = temp;
				twos = temp;
			}
			count2++;
		}
		temp = temp->next;
	}
	getHead(head, zeros, firstzero, ones, firstone, twos, firsttwo);
}


