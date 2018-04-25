#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int val){
        this->val = val;
        this->left=this->left=nullptr;
    }
};
class BST
{
private:
    TreeNode * header;
private:
    void destroy(TreeNode * node);
    TreeNode * insert_real(int key, TreeNode *& node);
    TreeNode *& find_real(int key, TreeNode *& node);
    void in_order(TreeNode * node);
public:
    BST();
    ~BST();
    TreeNode * insert(int key);
    TreeNode * find(int key);
    void erase(int key);
    void print();
};
BST::BST()
{
    TreeNode header(0);
}
int main(){
    BST root;
    
}