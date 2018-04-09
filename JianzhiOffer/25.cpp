//复杂链表的复制
/*
在不使用辅助空间的情况下实现O(N)的时间效率。

第一步：根据原始链表的每个结点N创建对应的N'，然后将N‘通过pNext接到N的后面；

第二步：设置复制出来的结点的pSibling。假设原始链表上的N的pSibling指向结点S，那么其对应复制出来的N'是N->pNext指向的结点，同样S'也是结点S->pNext指向的结点。

第三步：把长链表拆分成两个链表，把奇数位置的结点用pNext连接起来的就是原始链表，把偶数位置的结点通过pNext连接起来的就是复制链表。
*/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution
{
  public:
    RandomListNode *Clone(RandomListNode *pHead)
    {
        if (!pHead)
            return pHead;
        RandomListNode *cur = pHead;
        while (cur)
        {
            RandomListNode *node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        cur = pHead;
        while (cur)
        {
            RandomListNode *node = cur->next;
            if (cur->random)
            {
                node->random = cur->random->next;
            }
            cur = node->next;
        }
        RandomListNode *res = pHead->next;
        RandomListNode *tmp;
        cur = pHead;
        while (cur->next)
        {
            tmp = cur->next;
            cur->next = tmp->next;
            cur = tmp;
        }
        return res;
    }
};