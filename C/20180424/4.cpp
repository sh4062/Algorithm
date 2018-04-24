//Linked List 顺序插入 今天这几题就拿cpp了 毕竟面试总有人问
#include <bits/stdc++.h>
#include "ll.h"
using namespace std;
void orderinsert(ListNode *&head, int i)
{

    if (head == NULL)
    {
        (head) = new ListNode(i);
        return;
    }
    else if (head->val >= i)
    {
        ListNode *pnew = new ListNode(i);
        pnew->next = head;
        head = pnew;
        return;
    }
    else
    {
        ListNode *pnew = new ListNode(i);
        ListNode *pcur = head;
        ListNode *ppre = head;
        while (pcur)
        {
            if (pcur->val > i)
            {
                ppre->next = pnew;
                pnew->next = pcur;
                break;
            }
            ppre = pcur;
            pcur = pcur->next;
        }

        if (!pcur)
        {
            ppre->next = pnew;
        }
    }
}
int main()
{
    ListNode *head = NULL;
    tailinsert(head, 1);
    tailinsert(head, 2);
    tailinsert(head, 3);
    tailinsert(head, 5);
    tailinsert(head, 9);
    list_print(head);
    cout << '\n';
    orderinsert(head, 0);
    orderinsert(head, 4);
    orderinsert(head, 7);
    orderinsert(head, 2);
    orderinsert(head, 8);
    orderinsert(head, 11);
    list_print(head);
    cout << '\n';
}