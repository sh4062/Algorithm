//判断单链表是否有环
#include "ll.h"
bool isloop( ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;
    while((fast->next&&fast->next->next)){//&&从左到右
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow)return true;
    }
    return false;

}
int main(){
    ListNode* head=NULL;
    tailinsert(head,9);
    tailinsert(head,5);
    tailinsert(head,3);
    tailinsert(head,2);
    tailinsert(head,1);
    list_print(head);
    std::cout<<isloop(head)<<'\n';
    head->next->next->next->next->next=head;
    std::cout<<isloop(head)<<'\n';
    }