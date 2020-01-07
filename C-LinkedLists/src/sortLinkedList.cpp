/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};
struct node * sortLinkedList(struct node *head) {
	if(head==NULL)
		return NULL;
	struct node* select = head;
	struct node* shift;
	while (select != NULL)
	{
		shift = select->next;
		while (shift != NULL)
		{
			if (select->num > shift->num)
			{
				int temp = select->num;
				select->num = shift->num;
				shift->num = temp;
			}
			shift = shift->next;
		}
		select = select->next;
	}
	return head;
}