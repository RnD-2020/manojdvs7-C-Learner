/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	if (head == NULL || K <= 1)
		return NULL;
	struct node* current = head;
	struct node* prev = NULL;
	struct node* next = NULL;
	int pos = 1;
	while (current != NULL) {
		if (pos%K == 0)
		{
			prev->next = current->next;
		}
		next = current->next;
		/*current->next = prev;*/
		pos++;
		prev = current;
		current = next;
	}

	head = prev;
	return head;
}