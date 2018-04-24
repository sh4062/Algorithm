#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void list_print(ListNode* head)
{
	while (head != NULL)
	{
		printf("%3d", head->val);
		head = head->next;
	}
	printf("\n");
}

void tailinsert(ListNode* &head, int i)
{

	if (head == NULL)
	{   (head)=new ListNode(i);
		return ;
	}
	else
	{
		
		ListNode * pnew =new ListNode(i);
        ListNode *p=head;
		while ((p)->next)
		{
			(p) = ((p))->next;
		}
		(p)->next = pnew;
	}
}
