/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
struct node* reverseLinkedList(struct node* head)
{
	struct node* current = head;
	struct node* prev = NULL;
	struct node* next = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

void storeNumber(struct node* head, int N)
{
	if (N == 0)
		return;
	storeNumber(head->next, N / 10);
	head->num = N % 10;
}

struct node* createLinkedList(int N)
{
	struct node* newNode;
	struct node* temp;
	struct node* head = NULL;
	int count = 1;
	if (N == 0)
	{
		head = (struct node*)malloc(sizeof(struct node));
		head->next = NULL;
		head->num = 0;
		return head;
	}
	while (N)
	{
		newNode = (struct node*)malloc(sizeof(struct node));
		if (count == 1)
		{
			head = newNode;
			temp = head;
		}
		newNode->next = NULL;
		temp->next = newNode;
		temp = temp->next;
		N = N / 10;
		count++;
	}
	return head;
}

struct node * numberToLinkedList(int N) {
	if (N < 0)
		N = N*(-1);
	struct node* head = createLinkedList(N);
	storeNumber(head, N);
	head = reverseLinkedList(head);
	return head;
}