#include<iostream>  
#include<string.h>
#include<cstdio>
#include<algorithm>  
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node(int x) { data = x; next = NULL; }
};

Node * header = new Node(0);

void desc_construct(Node * header)
{
    Node * pre = NULL;  // 前一个结点
    int x;
  
    while (cin >> x && x != -1)
    {
        Node * cur = new Node(x);
        cur->data = x;
        cur->next = pre;  // 指向前一个结点
        pre = cur;        // 保存当前结点
    }
  
    header->next = pre;  // 头结点指向第一结点
}

void reverse(Node * header)
{
    if (!header->next || !header->next->next)  // 如果是空链表或链表只有一个结点
        return;
  
    Node * cur = header->next;  // 指向第一个结点
    Node * pre = NULL;
  
    while (cur)
    {
        Node * temp = cur->next;  // 保存下一个结点
        cur->next = pre;          // 调整指向
        pre = cur;                // pre 前进一步
        cur = temp;               // cur 前进一步
    }
  
    header->next = pre;  // 头结点指向反转后的第一结点
}   

int main(){
    
    desc_construct(header);
    Node * tmp= header;
    while(header->next){
        header = header->next;
        
        cout<<header->data<<'\n';
        
    }
    reverse(tmp);
    while(tmp->next){
        tmp = tmp->next;
        
        cout<<tmp->data<<'\n';
        
    }
}