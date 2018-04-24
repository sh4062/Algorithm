//将一个链表逆置
#include "ll.h"
ListNode* ReverseLL(ListNode* head){
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while(cur){
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;

}
int main(){
    ListNode* head=NULL;
    tailinsert(head,9);
    tailinsert(head,5);
    tailinsert(head,3);
    tailinsert(head,2);
    tailinsert(head,1);
    list_print(head);
    std::cout<<'\n';
    ListNode* res =ReverseLL(head);
    list_print(res);
    std::cout<<'\n';
    }