//merge LL 递归
#include "ll.h"
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)//l1到头
    {
        return l2;
    }
    if (l2 == nullptr)//l2到头
    {
        return l1;
    }
    if (l1->val <= l2->val)//l1比较小
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
int main()
{

    ListNode *head1 = NULL;
    ListNode *head2 = NULL;
    tailinsert(head1, 1);
    tailinsert(head1, 2);
    tailinsert(head1, 3);
    tailinsert(head2, 4);
    tailinsert(head2, 5);
    list_print(head1);
    cout << '\n';
    list_print(head2);
    cout << '\n';
    ListNode *res = NULL;
    res = mergeTwoLists(head1, head2);
    list_print(res);
    std::cout << '\n';
}