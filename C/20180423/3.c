//尾插法建立链表
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
	int val;
	struct Node *next;

} * Node; //别名 Node = struct Node*

void list_print(Node head)
{
	while (head != NULL)
	{
		printf("%3d", head->val);
		head = head->next;
	}
	printf("\n");
}

void tailinsert(Node head, int i)
{

	if (head == NULL)
	{   (head)= (Node)calloc(1, sizeof(Node));
		(head)->val = i;
		return ;
	}
	else
	{
		Node pnew = (Node)calloc(1, sizeof(Node));
		pnew->val = i;
		while ((head)->next)
		{
			(head) = ((head))->next;
		}
		(head)->next = pnew;
	}
}

int main()
{
	// Node head = (Node)calloc(1,sizeof(Node));
	Node head = (Node)calloc(1,sizeof(Node));
	
	tailinsert(head, 1);
	tailinsert(head, 3);
	tailinsert(head, 2);
	tailinsert(head, 4);
	tailinsert(head, 5);
	list_print(head);
	free(head);
}
