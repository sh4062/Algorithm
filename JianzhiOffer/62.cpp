//二叉搜索树的第k个结点
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution
{
  public:
    int index = 0;
    TreeNode *KthNode(TreeNode *pRoot, int k)
    {

        if (root)
        { //中序遍历寻找第k个
            TreeNode node = KthNode(root->left, k);
            if (node)
                return node;
            index++;
            if (index == k)
                return root;
            node = KthNode(root->right, k);
            if (node)
                return node;
        }
        return NULL;
    }
};