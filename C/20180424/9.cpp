//找出链表的中间节点
#include "ll.h"
ListNode* mideLL(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;
    while((fast->next&&fast->next->next)){//&&从左到右
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;

}
int main(){
    ListNode* head=NULL;
    tailinsert(head,9);
    tailinsert(head,5);
    tailinsert(head,3);
    tailinsert(head,2);
    tailinsert(head,1);
    tailinsert(head,8);
    tailinsert(head,7);
    tailinsert(head,2);
    tailinsert(head,55);
    list_print(head);
    std::cout<<'\n';
    ListNode* res=mideLL(head);
    std::cout<<"  "<<res->val;
    std::cout<<'\n';
    }