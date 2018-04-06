//二叉树中和为某一值的路径 用带记忆的DFS
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution
{
  public:
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        vector<vector<int>> res;
        vector<int> trace;
        if (root)
            dfs(root, expectNumber, res, trace);
        return res;
    }
    void dfs(TreeNode *root, int s, vector<vector<int>> &res, vector<int> &trace)
    {
        trace.push_back(root->val);//记录
        if (!root->left && !root->right)
        {
            if (s == root->val)
                res.push_back(trace);
        }
        if (root->left)
            dfs(root->left, s - root->val, res, trace);
        if (root->right)
            dfs(root->right, s - root->val, res, trace);
        trace.pop_back();//不对
    }
};