/*二叉搜索树与双向链表
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
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        if (pRootOfTree == nullptr)
            return nullptr;
        TreeNode *pTailOfList = nullptr;
        CN(pRootOfTree, pTailOfList);
        TreeNode *pHeadOfList = pTailOfList;
        while (pHeadOfList->left)
            pHeadOfList = pHeadOfList->left;

        return pHeadOfList;
    }

    void CN(TreeNode *cur, TreeNode *&pre)
    {
        if (cur == nullptr)
            return;

        CN(cur->left, pre);

        cur->left = pre;
        if (pre)
            pre->right = cur;
        pre = cur;

        CN(cur->right, pre);
    }
};