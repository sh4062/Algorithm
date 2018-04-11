/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution
{
  public:
    ListNode *deleteDuplication(ListNode *pHead)
    {
        if (!pHead || !pHead->next)
            return pHead;
        ListNode *newHead = new ListNode(-1);
        newHead->next = pHead;
        ListNode *i = newHead;
        ListNode *j = newHead->next;

        while (j&&j->next)
        {
            ListNode *tmp = j->next;
            if (j->val == tmp->val)
            {
                while (tmp && j->val == tmp->val)
                {
                    tmp = tmp->next;
                }
                i->next = tmp;
                j = tmp;
            }
            else
            {
                i = j;
                j = j->next;
            }
        }
        return newHead->next;
    }
};