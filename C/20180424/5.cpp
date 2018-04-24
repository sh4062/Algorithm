//Linked List 删除特定节点...给出具体节点的是O(1)的
#include <bits/stdc++.h>
#include "ll.h"
using namespace std;
void delnode(ListNode *header, ListNode *position) //O(1)
{
    if (!position->next) // 要删除的是最后一个结点
    {
        ListNode *p = header;
        while (p->next != position)
            p = p->next; // 找到 position 的前一个结点
        p->next = nullptr;
        delete position;
    }
    else
    {
        ListNode *p = position->next;
        swap(p->val, position->val);
        position->next = p->next;
        delete p;
    }
}
void del(ListNode *&head, int i)
{
    if (!head)
        return;
    ListNode *pcur = head;
    ListNode *ppre = head;
    if (pcur->val == i)
    {
        head = pcur->next;
        return;
    }
    else
    {
        while (pcur)
        {
            if (pcur->val == i)
            {
                ppre->next = pcur->next;
                free(pcur);
                return;
            }
            ppre = pcur;
            pcur = pcur->next;
        }
        if(pcur==nullptr){
            cout<<"No such value in LL.";
        }
    }
}

int main()
{
    ListNode *head = NULL;
    tailinsert(head, 9);
    tailinsert(head, 5);
    tailinsert(head, 3);
    tailinsert(head, 2);
    tailinsert(head, 1);
    list_print(head);
    std::cout << '\n';
    del(head,10);
    list_print(head);
    std::cout << '\n';
    del(head,3);
    list_print(head);
    std::cout << '\n';
    del(head,2);
    list_print(head);
    std::cout << '\n';
    del(head,1);
    list_print(head);
    std::cout << '\n';
    del(head,5);
    list_print(head);
    std::cout << '\n';
    del(head,9);
}