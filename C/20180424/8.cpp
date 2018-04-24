//找出链表的倒数第四个节点
#include "ll.h"
ListNode* Last4(ListNode* head){
    ListNode* fast = head->next->next->next->next;
    ListNode* slow = head;
    while(fast){
        fast = fast->next;
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
    ListNode* res=Last4(head);
    std::cout<<"  "<<res->val;
    std::cout<<'\n';
    }