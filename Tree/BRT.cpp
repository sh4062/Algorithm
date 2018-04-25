//红黑树 0. 节点红的黑的
//1.根是黑的
//2.红节点孩子是黑的
//3.对于任意一个结点，其到叶子结点的每条路径上都包含相同数目的黑色结点。
//Java中的：java.util.TreeMap，java.util.TreeSet；
//C++ STL中的：map，multimap，multiset;
//对于AVL树，在插入或删除操作后，都要利用递归的回溯，去维护从被删结点到根结点这条路径上的所有结点的平衡性，回溯的量级是需要O(logn)的，
//其中插入操作最多需要两次旋转，删除操作可能是1次、2次或2次以上。而红黑树在insert_rebalance的时候最多需要2次旋转，
//在erase_rebalance的时候最多也只需要3次旋转。
//其次，AVL树的结构相较红黑树来说更为平衡，故在插入和删除结点时更容易引起不平衡。
//因此在大量数据需要插入或者删除时，AVL树需要rebalance的频率会更高，相比之下，红黑树的效率会更高。
#include <bits/stdc++.h>
using namespace std;
enum
{
    red = 0,
    black = 1
};
struct BRTNode
{
    bool color;
    int val;
    BRTNode *parent;
    BRTNode *left;
    BRTNode *right;
    BRTNode(int key = 0)
    {
        this->val = key;
        this->color = red;
        this->parent = this->left = this->right = nullptr;
    }
};
class BRT
{
  private:
    BRTNode *header;

  private:
    void rotate_l(BRTNode *x);
    void rotate_r(BRTNode *y);
    void destroy(BRTNode *node);
    BRTNode *&root();
    void insert_rebalance(BRTNode *x);
    void erase_rebalance(BRTNode *z);
    void in_order(BRTNode *node);

  public:
    BRT();
    ~BRT();
    BRTNode *insert(int key);
    BRTNode *find(int key);
    void erase(int key);
    void print();
};
//"重新着色"和"旋转"
/* 
 * 对红黑树的节点(x)进行左旋转
 *
 * 左旋示意图(对节点x进行左旋)：
 *      px                              px
 *     /                               /
 *    x                               y                
 *   /  \      --(左旋)-->           / \                #
 *  lx   y                          x  ry     
 *     /   \                       /  \
 *    ly   ry                     lx  ly  
 *
 *左右旋转很显然为镜像操作
 */
void BRT::rotate_l(BRTNode *x)
{
    // 设置x的右孩子为y
    BRTNode *y = x->right;
    // 将 “y的左孩子” 设为 “x的右孩子”；
    // 如果y的左孩子非空，将 “x” 设为 “y的左孩子的父亲”
    x->right = y->left;
    if (y->left)
        y->left->parent = x;
    // 将 “x的父亲” 设为 “y的父亲”
    y->parent = x->parent;
    //修改红黑树的根节点
    if (x == root())
    {
        root() = y;
    }
    else
    {
        // 如果 x是它父节点的左孩子，则将y设为“x的父节点的左孩子”
        if (x->parent->left == x)
            x->parent->left = y;
        // 如果 x是它父节点的右孩子，则将y设为“x的父节点的右孩子”
        else
            x->parent->right = y;
    }
    // 将 “x” 设为 “y的左孩子”
    y->left = x;
    // 将 “x的父节点” 设为 “y”
    x->parent = y;
}
/* 
 * 对红黑树的节点(y)进行右旋转
 *
 * 右旋示意图(对节点y进行左旋)：
 *            py                               py
 *           /                                /
 *          y                                x                  
 *         /  \      --(右旋)-->            /  \                     #
 *        x   ry                           lx   y  
 *       / \                                   / \                   #
 *      lx  rx                                rx  ry
 * 
 */
void BRT::rotate_r(BRTNode *y) //一共3个节点最多7个指针变化 先从x-y开始 然后是 x和py
{
    // 设置x是当前节点的左孩子。
    BRTNode *x = y->left;
    // 将 “x的右孩子” 设为 “y的左孩子”；
    // 如果"x的右孩子"不为空的话，将 “y” 设为 “x的右孩子的父亲”
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    // 将 “y的父亲” 设为 “x的父亲”
    x->parent = y->parent;
    if (y == root())
    {
        root() = x;
    }
    else
    {
        if (y == y->parent->right)
            y->parent->right = x; // 如果 y是它父节点的右孩子，则将x设为“y的父节点的右孩子”
        else
            y->parent->left = x; // (y是它父节点的左孩子) 将x设为“x的父节点的左孩子”
    }

    // 将 “y” 设为 “x的右孩子”
    x->right = y;

    // 将 “y的父节点” 设为 “x”
    y->parent = x;
}
BRTNode *&BRT::root() //根节点
{
    return header->left;
}
void BRT::destroy(BRTNode *node) //递归删除节点
{
    if (node == nullptr)
        return;

    destroy(node->left);
    destroy(node->right);
    delete node;
}
void BRT::in_order(BRTNode *node)
{
    if (node == nullptr)
        return;

    in_order(node->left);
    cout << "( " << node->val << ", " << node->color << " )" << endl;
    in_order(node->right);
}
//!!!
//将插入的结点着色为红色，不会违背"性质4"。而少违背一条性质，就意味着我们需要处理的情况越少。
/*
被插入结点是根结点，那我们把此结点涂为黑色就行了；
被插入结点的父亲结点是黑色的，那么什么也不需要做，结点被插入后，仍然是红黑树。
被插入结点的父亲结点是红色的，那么此时是违背"性质3"的。
*/
void BRT::insert_rebalance(BRTNode *x)
{
    x->color = red;
    while (x != root() && x->parent->color == red)
    {
        //左右镜像操作
        if (x->parent == x->parent->parent->left)
        {
            BRTNode *y = x->parent->parent->right;
            //Case1当前结点的父亲是红色，叔叔存在且也是红色
            /*将"父亲结点"改为黑色；
            将"叔叔结点"改为黑色；
            将"祖父结点"改为红色；
            将"祖父结点"设为"当前结点"，继续进行操作。*/
            if (y && y->color == red)
            {
                x->parent->color = black;
                y->color = black;
                x->parent->parent->color = red;
                x = x->parent->parent;
            }
            else
            {
                //Case 2：当前结点的父亲是红色，叔叔不存在或是黑色，且当前结点是其父亲的右孩子
                /*将"父亲结点"设为"当前结点"；
            以"新的当前结点"为支点进行左旋。
            处理完后，我们发现依旧不满足红黑树的性质，别急，这就是"Case 3"。*/
                if (x->parent->right == x)
                {
                    x = x->parent;
                    rotate_l(x);
                }
                //Case 3：当前结点的父亲是红色，叔叔不存在或是黑色，且当前结点是其父亲的左孩子
                /*将"父亲结点"改为黑色；
            将"祖父结点"改为红色；
            以"祖父结点"为支点进行右旋。*/
                x->parent->color = black;
                x->parent->parent->color = red;
                rotate_r(x->parent->parent);
            }
        }
        else //镜像操作
        {
            BRTNode *y = x->parent->parent->left;
            //Case1当前结点的父亲是红色，叔叔存在且也是红色
            /*将"父亲结点"改为黑色；
            将"叔叔结点"改为黑色；
            将"祖父结点"改为红色；
            将"祖父结点"设为"当前结点"，继续进行操作。*/
            if (y && y->color == red)
            {
                x->parent->color = black;
                y->color = black;
                x->parent->parent->color = red;
                x = x->parent->parent;
            }
            else
            {
                //Case 2：当前结点的父亲是红色，叔叔不存在或是黑色，且当前结点是其父亲的左孩子
                /*将"父亲结点"设为"当前结点"；
            以"新的当前结点"为支点进行右旋。
            处理完后，我们发现依旧不满足红黑树的性质，别急，这就是"Case 3"。*/
                if (x->parent->left == x)
                {
                    x = x->parent;
                    rotate_r(x);
                }
                //Case 3：当前结点的父亲是红色，叔叔不存在或是黑色，且当前结点是其父亲的右孩子
                /*将"父亲结点"改为黑色；
            将"祖父结点"改为红色；
            以"祖父结点"为支点进行左旋。*/
                x->parent->color = black;
                x->parent->parent->color = red;
                rotate_l(x->parent->parent);
            }
        }
    }
    //根结点为黑色
    root()->color = black;
}
void BRT::erase_rebalance(BRTNode *z)
{
}

BRT::BRT()
{
    header = new BRTNode(0);
}
BRT::~BRT()
{
    destroy(root());
    delete header;
    header = nullptr;
}
BRTNode *BRT::insert(int key)
{
    BRTNode *cur = root();
    BRTNode *pre = header;
    //找插入位置 需要记录parent
    while (cur)
    {
        pre = cur;
        if (key < cur->val)
            cur = cur->left;
        else if (key > cur->val)
            cur = cur->right;
        else
            return nullptr;
    }
    //建立新的节点 调整父指针
    cur = new BRTNode(key);
    cur->parent = pre;
    //调整双亲指针
    if (pre == header || key < pre->val)
        pre->left = cur;
    else
        pre->right = cur;
    //调整平衡
    insert_rebalance(cur);

    return cur;
}

BRTNode *BRT::find(int key)
{
    BRTNode *z = root();

    while (z)
    {
        if (key < z->val)
            z = z->left;
        else if (key > z->val)
            z = z->right;
        else
            return z;
    }

    return z;
}

void BRT::erase(int key)
{
    BRTNode *z = find(key);

    if (z)
    {
        erase_rebalance(z);
        delete z;
    }
}

void BRT::print()
{
    in_order(root());
    cout << endl;
}

int main()
{
    BRT rb_tree;

    // test "insert"

    rb_tree.insert(1);
    rb_tree.insert(2);

    // rb_tree.insert(1);

    rb_tree.insert(5);

    rb_tree.insert(7);
    rb_tree.insert(6);
    

    rb_tree.insert(4);
    rb_tree.insert(9);
    rb_tree.insert(8);
    rb_tree.insert(11); rb_tree.insert(11);
    rb_tree.insert(10);
    rb_tree.insert(12);
    rb_tree.insert(4);
    rb_tree.insert(9);
    rb_tree.insert(8);
    rb_tree.insert(11); rb_tree.insert(11);
    rb_tree.insert(10);
    rb_tree.insert(12);
    rb_tree.print();
}