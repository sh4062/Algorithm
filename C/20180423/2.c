//头插法建立链表
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
	int val;
	struct Node *next;

} *Node;

void list_print(Node head)
{
	while (head != NULL)
	{
		printf("%3d", head->val);
		head = head->next;
	}
	printf("\n");
}

void headinsert(Node *head, int i)
{
	Node pnew = (Node)calloc(1, sizeof(Node));
	pnew->val = i;
	if (*head == NULL)
	{
		*head = pnew;
	}
	else
	{
		pnew->next = *head;
		*head = pnew;
	}
}

int main()
{
	// Node head = (Node)calloc(1,sizeof(Node));
	Node head = NULL;
	headinsert(&head, 1);
	headinsert(&head, 3);
	headinsert(&head, 2);
	headinsert(&head, 4);
	headinsert(&head, 5);
	list_print(head);
}
