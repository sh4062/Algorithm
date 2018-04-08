//在O(1)删除链表节点
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int data;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

void DeleteN(ListNode * head,ListNode * position){
    if(!head || !position)
    return;
    if (!position->next)  // 要删除的是最后一个结点
	{
		ListNode * p = head;
		while (p->next != position)
			p = p->next;  // 找到 position 的前一个结点
		p->next = nullptr;
		delete position;
	}
	else
	{
		ListNode * p = position->next;
		swap(p->data, position->data);
		position->next = p->next;
		delete p;
	}
}