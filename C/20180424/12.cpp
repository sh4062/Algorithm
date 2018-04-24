//删除单链表中重复的元素
//由于用的是头节点大概默认删掉后出现的简单点吧
//hash应该可以O(n)*2
#include "ll.h"
void deletere(ListNode *&head)//这个循环大概是。。。O(n^2)?
{
    ListNode *p = head;
    while (p)
    {
        ListNode *q = head;
        while (q->next != p && q->next)
        {
            if (q->next->val == p->val)
            {   ListNode * f=q->next;
                q->next = q->next->next;
                free(f);
            }   
            else
                q = q->next;
        }

        p = p->next;
    }
}
int main()
{
    ListNode *head = NULL;
    tailinsert(head, 9);
    tailinsert(head, 2);
    tailinsert(head, 2);
    tailinsert(head, 3);
    tailinsert(head, 4);
    tailinsert(head, 4);
    tailinsert(head, 9);
    list_print(head);
    std::cout << '\n';
    deletere(head);
    list_print(head);
    std::cout << '\n';
}