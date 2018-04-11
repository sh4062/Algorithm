/*链表中环的入口结点
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
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        if (!pHead || !pHead->next || !pHead->next->next)
            return nullptr;
        ListNode *fast = pHead;
        ListNode *slow = pHead;
        while (fast->next && fast )
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            break;
        }
        ListNode *meet = nullptr;
        if (slow == fast)
            meet = slow;
        else
            return nullptr;
        ListNode *start = pHead;
        while (start != fast)
        {
            start = start->next;
            fast = fast->next;
        }

        return start;
    }
};