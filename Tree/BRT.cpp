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
    cout << "( " << node->val << ", " << node->color << " parent->" << node->parent->val << " )" << endl;
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
/*对于普通二叉树
"被删结点"没有孩子，那么直接删除即可；//他的替换可以为左也可以为右
"被删结点"只有一个孩子，那么直接删除该结点，并用该结点的唯一孩子替换它；
"被删结点"有两个孩子，那么先找出它的"后继结点"，然后删除"被删结点"，再用"后继结点"去替换"被删结点"。
后继大概就是中序遍历的下一个节点吧
"我们把"被删结点"称为"原先结点"，用来替换"被删结点"的结点称为"当前结点"。
*/
void BRT::erase_rebalance(BRTNode *z)
{
    BRTNode *y = z;
    BRTNode *x = nullptr; 
    BRTNode *x_parent = nullptr;
    if (y->left == nullptr)//这里 如果左右都空 用右当做后继替换
        x = y->right;
    else if (y->right == nullptr)
        x = y->left;
    else
    {
        //找出它的"后继结点"
        y = y->right;   //比y大
        while (y->left) //比y大里面最小的
            y = y->left;
        x = y->right; //比y大里面最小的的大的节点就是后继结点
    }
/*1原先结点"为黑色，"当前结点"为红色，那么我们把"原先结点"删掉后，拿"当前结点"去替换它并修改颜色为黑色即可；
2"原先结点"为黑色，"当前结点"为黑色，这种情况比较复杂，待会再说；
3"原先结点"为红色，"当前结点"为红色，那么我们把"原先结点"删掉后，直接拿"当前结点"去替换它即可；
4"原先结点"为红色，"当前结点"为黑色，那么我们把"原先结点"删掉后，再拿"当前结点"去替换它并修改颜色为红色。
我们发现，此时"原先结点"位置是满足红黑树性质的，但是由于"当前结点"被拿走，"当前结点"位置可能就会违背红黑树性质。
分析发现，此时的"当前结点"不就是上面"情况1"和"情况2"中所讲的"原先结点"！那么当前的这种情况直接就变成了"情况1"或"情况2"。
*/
//"情况2"。这种情况可以进一步再划分为8种情况，因为涉及到镜像操作 4种
    if (y != z) //y是z的后继 "被删结点"z有2个孩子 y是z的后继 要删除z 用y替换z
    {
        z->left->parent = y; //调整z左孩子的父亲指针为y
        y->left = z->left;   //y的左孩子指向z的左孩子

        if (y != z->right) //y并不是直接是z的右孩子
        {
            x_parent = y->parent;
            if (x)
                x->parent = y->parent;
            y->parent->left = x;
            y->right = z->right;
            z->right->parent = y;
        }
        else //y直接是z的右孩子
            x_parent = y;

        if (root() == z)
            root() = y;
        else if (z->parent->left == z)
            z->parent->left = y;
        else
            z->parent->right = y;

        y->parent = z->parent;
        swap(y->color, z->color);
        y = z;
    }
    else //"被删结点"只有一个孩子 那么直接删除该结点，并用该结点的唯一孩子替换它；{若没有就用右边(见上面)}
    {    //调整y->parent和z->parent->left||right
        x_parent = y->parent;
        if (x)
            x->parent = y->parent;

        if (root() == z)//调整z父节点的指针指向x
        
            root() = x;
        else if (z->parent->left == z)
            z->parent->left = x;
        else
            z->parent->right = x;
    }
    // now, y is pointing to what you will erase!
    //      x is the child of y, and note that x might be nullptr.
    // Now, the actual reblance is coming!
    // .....
    if (y->color == black)
    {
        while (x != root() && (x == nullptr || x->color == black))
        {
            if (x == x_parent->left)
            {                                 //节点的兄弟      节点
                BRTNode *w = x_parent->right; // w can not possibly be nullptr!

                if (w->color == red) // Case 1
                {
                    w->color = black;
                    x_parent->color = red;
                    rotate_l(x_parent);
                    w = x_parent->right;
                }

                if ((w->left == nullptr || w->left->color == black) && // Case 2
                    (w->right == nullptr || w->right->color == black))
                {
                    w->color = red;
                    x = x_parent;
                    x_parent = x_parent->parent;
                }
                else
                {
                    if (w->right == nullptr || w->right->color == black) //Case 3
                    {
                        if (w->left)
                            w->left->color = black;
                        w->color = red;
                        rotate_r(w);
                        w = x_parent->right;
                    }

                    w->color = x_parent->color; // Case 4
                    x_parent->color = black;
                    if (w->right)
                        w->right->color = black;
                    rotate_l(x_parent);
                    break;
                }
            }
            else // same as above, just left <-> right x在右边
            {
                BRTNode *w = x_parent->left;

                if (w->color == red)
                {
                    w->color = black;
                    x_parent->color = red;
                    rotate_r(x_parent);
                    w = x_parent->left;
                }

                if ((w->right == nullptr || w->right->color == black) &&
                    (w->left == nullptr || w->left->color == black))
                {
                    w->color = red;
                    x = x_parent;
                    x_parent = x_parent->parent;
                }
                else
                {
                    if (w->left == nullptr || w->left->color == black)
                    {
                        if (w->right)
                            w->right->color = black;
                        w->color = red;
                        rotate_l(w);
                        w = x_parent->left;
                    }

                    w->color = x_parent->color;
                    x_parent->color = black;
                    if (w->left)
                        w->left->color = black;
                    rotate_r(x_parent);
                    break;
                }
            }
        } // while (x != root() && (x == nullptr || x->color == black))

        if (x)
            x->color = black;
    } // if (y->color == black)
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

    // // test "insert"

    // rb_tree.insert(1);
    // rb_tree.insert(2);

    // // rb_tree.insert(1);

    // rb_tree.insert(5);

    // rb_tree.insert(7);
    // rb_tree.insert(6);

    // rb_tree.insert(4);
    // rb_tree.insert(9);
    // rb_tree.insert(8);
    // rb_tree.insert(11);
    // rb_tree.insert(11);
    // rb_tree.insert(10);
    // rb_tree.insert(12);
    // rb_tree.insert(4);
    // rb_tree.insert(9);
    // rb_tree.insert(8);
    // rb_tree.insert(11);
    // rb_tree.insert(11);
    // rb_tree.insert(10);
    // rb_tree.insert(12);
    // rb_tree.print();
    // rb_tree.erase(9);
    // rb_tree.erase(8);
    // rb_tree.erase(11);
    // rb_tree.erase(11);
    rb_tree.insert(1);
    rb_tree.insert(2);
    rb_tree.insert(3);
    rb_tree.insert(4);
    rb_tree.erase(2);
    rb_tree.print();
}