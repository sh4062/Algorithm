//判断两个链表是否相交, 如果相交, 计算交点
//有环无环判断 。。。真的有人Hash地址吗
//1.都没环 2.一个有一个没有不可能相交 3.都有
#include "ll.h"
ListNode *isloop(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while ((fast->next && fast->next->next))
    { //&&从左到右
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return slow;
    }
    return nullptr;
}
ListNode *loopstart(ListNode *head)
{
    if (!isloop(head))
        return nullptr;
    ListNode *meet = isloop(head);
    ListNode *start = head;
    while (start != meet)
    {
        start = start->next;
        meet = meet->next;
    }
    return meet;
}

ListNode *iscross(ListNode *head1, ListNode *head2)
{
    if (!isloop(head1) && !isloop(head2))
    { //都没有环
        ListNode *p = head1;
        while (p->next)
            p = p->next;
        p->next = head2;
        return loopstart(head1);
    }
    else if (isloop(head1) && isloop(head2))
    { //都有环
        ListNode *l1 = loopstart(head1);
        ListNode *l2 = loopstart(head2);
        if (l1 == l2)
        {
            return l1;
        }
        else
        {
            ListNode *l1p = l1->next;
            while (l1p != l1)
            {
                if (l1p == l2)
                    return l1p;
                l1p = l1p->next;
            }
            return nullptr;
        }
    }
    else
    {
        return nullptr;
    }
}
int main()
{
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;
    tailinsert(head1, 1);
    tailinsert(head1, 2);
    tailinsert(head1, 3);
    tailinsert(head1, 4);
    tailinsert(head1, 5);
    tailinsert(head2, 8);
    tailinsert(head2, 9);
    tailinsert(head2, 16);
    head2->next->next->next = head1->next->next;
    ListNode *res = iscross(head2, head1);
    std::cout << res->val << '\n';
}