//将一个链表拆分(将链表奇数位置上的节点构成一个链表,偶数位置上的节点构成另一个链表)
#include "ll.h"
vector<ListNode *> breakLL(ListNode *head)
{
    vector<ListNode *> res;
    ListNode *p1 = head;
    ListNode *p2 = head->next;
    ListNode *p = head->next->next;
    p1->next = nullptr;
    p2->next = nullptr;
    if (!p1 || !p2)
    {
        res.push_back(p1);
        res.push_back(p2);
        return res;
    }
    ListNode *p1p = p1;
    ListNode *p2p = p2;
    int cnt = 1;
    while (p)
    {
        if (cnt % 2 == 1)
        {
            p1p->next = p;
            p1p = p1p->next;
            p = p->next;
            p1p->next = nullptr;
        }
        else
        {
            p2p->next = p;
            p2p = p2p->next;
            p = p->next;
            p2p->next = nullptr;
        }
        cnt++;
    }

    res.push_back(p1);
    res.push_back(p2);
    return res;
}
int main()
{
    ListNode *head = NULL;
    tailinsert(head, 1);
    tailinsert(head, 2);
    tailinsert(head, 3);
    tailinsert(head, 4);
    tailinsert(head, 5);
    tailinsert(head, 6);
    tailinsert(head, 7);
    tailinsert(head, 8);
    list_print(head);
    std::cout << '\n';
    vector<ListNode *> res = breakLL(head);
    list_print(res[0]);
    list_print(res[1]);
    std::cout << '\n';
    tailinsert(head, 9);
    list_print(head);
    vector<ListNode *> res2 = breakLL(head);
    list_print(res2[0]);
    list_print(res2[1]);
}