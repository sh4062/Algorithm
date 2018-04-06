//从上往下打印出二叉树
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        vector<int> res;
        queue<TreeNode *> q;
        if (!root)
            return res;
        q.push(root);
        TreeNode *p;
        while (!q.empty())
        {
            res.push_back(q.front()->val);
            p = q.front();
            q.pop();
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
        return res;
    }
};