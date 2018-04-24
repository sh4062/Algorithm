//加呗
//Linked List ...逆序看着真是别扭
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
ListNode* add(ListNode* l1, ListNode* l2)
{int flag=0;
        int sum=0;
        ListNode *dummyHead = new ListNode(0);//加一个头节点
        ListNode* res=dummyHead,*p,*a=l1,*b=l2;
        while(a||b){
            int x = (a != NULL) ? a->val : 0;
            int y = (b != NULL) ? b->val : 0;
            sum=x+y+flag;
            flag=0;
            if(sum>=10){
                flag=1;
                sum=sum%10;
            }
       
            res->next= new ListNode(sum) ;
            sum=0;
            res=res->next;
            if (a != NULL) a=a->next;
            if (b != NULL) b=b->next;
            //cout<<1;
        }
        if(flag==1){
            res->next= new ListNode(1) ;
            res=res->next;
        }
            
        return dummyHead->next;

	
}
int main(){
    ListNode* head1=NULL;
    ListNode* head2=NULL;
    tailinsert(head1,7);
    tailinsert(head1,6);
    tailinsert(head1,5);
    tailinsert(head2,1);
    tailinsert(head2,1);
    list_print(head1);
    cout<<'\n';
    list_print(head2);
    cout<<'\n';
    ListNode* res=add(head1,head2);//567+11=578
    list_print(res);
}