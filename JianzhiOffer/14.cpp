//输入一个链表，输出该链表中倒数第k个结点。

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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL || k < 1)
          return NULL;
        ListNode* s =   pListHead;
        ListNode* f = pListHead;
        if(k==1&&pListHead->next == NULL) return pListHead;

        for(int i = 0;i<k-1;i++){//倒数第k个结点比如倒数第二注意k-1
            if(f->next == NULL)
              return NULL;
            f = f->next;

        }
        while(f->next){
            f = f->next;
            s = s->next;
        }
        return s;
    
    }
};