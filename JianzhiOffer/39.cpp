//平衡二叉树
class Solution
{
  public:
    bool IsBalanced_Solution(TreeNode *root, int &depth)
    {
        //如果为空，往父节点返
        if (root == NULL)
        {
            depth = 0;
            return true;
        }
        //记录左节点和右节点深度
        int left = 0;
        int right = 0;
        //采取传引用的方式，下层递归进行对深度修改以后会影响上一层
        if (IsBalanced_Solution(root->left, left) && IsBalanced_Solution(root->right, right))
        {
            //计算平衡因子
            int pf = right - left;
            //判断平衡因子是否合法
            if (pfIsInvaild(pf))
            {
                //合法就让自身加上子树的深度，然后因为是传引用，所以当递归回到上一层的时候，上层中的right和left就是左右子树的深度
                depth = 1 + (right > left ? right : left);
                return true;
            }
        }
        return false;
    }
    //判断平衡因子是否合法
    bool pfIsInvaild(const int &pf)
    {
        return abs(pf) < 2;
    }
};