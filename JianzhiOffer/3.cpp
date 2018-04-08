#include <iostream>  
#include <string>  
#include <stack>  
#include <queue>
#include <vector>
#include <cstdlib>
#include <fstream>  
using namespace std;
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        //if(head == NULL) return res;
        while(head){
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};