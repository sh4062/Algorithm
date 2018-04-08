#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
        struct TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> in)
    {
                if (pre.size() == 0)
        {
            return NULL;
                    
        }
        else if (pre.size() == 1)
        {
                        return new TreeNode(pre[0]);
                    
        }
                TreeNode *root = new TreeNode(pre[0]);
                int pos = std::find(in.begin(), in.end(), pre[0]) - in.begin();
                vector<int> l_pre = vector<int>(pre.begin() + 1, pre.begin() + pos + 1);
                vector<int> l_in = vector<int>(in.begin(), in.begin() + pos);
                vector<int> r_pre = vector<int>(pre.begin() + pos + 1, pre.end());
                vector<int> r_in = vector<int>(in.begin() + pos + 1, in.end());
                root->left = reConstructBinaryTree(l_pre, l_in);
                root->right = reConstructBinaryTree(r_pre, r_in);
                return root;
            
    }
};