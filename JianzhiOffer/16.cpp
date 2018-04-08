//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1==NULL) return pHead2;
        else if (pHead2==NULL) return pHead1;//Sp
        else
        {
            ListNode *p=pHead1;
            ListNode *q=pHead2;
            ListNode *tail = NULL;//处理用指针
            if (p->val < q->val)
            {
                pHead1 = tail = p;
                p = p->next;
            }
            else
            {
                pHead1 = tail = q;
                q = q->next;
            }
             
            while(p && q)
            {
                if (p->val < q->val) {
                    tail->next = p;
                    tail = p;
                    p = p->next;
                }else{
                    tail->next = q;
                    tail = q;
                    q = q->next;
                }
            }
             
            if (q) tail->next = q;
            if (p) tail->next = p;
             
            return pHead1;
             
        }
    }
};