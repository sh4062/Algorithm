#include <bits/stdc++.h>
using namespace std;
//这里面t是度数 来自算法导论的定义 m = 2*t
//t度 的B树就是 2t阶 的B树
/*
所有的叶子结点在同一层；
每棵B-树有一个Minimum Degree，称其为t；
除了根结点，其余每个结点至少包含t-1个keys，根结点可以只包含1个key；
每个结点（包括根结点）最多包含2t-1个keys；
一个结点的孩子指针数等于这个结点的keys数+1；
每个结点的keys都按升序排列；
对于每个key，其左边孩子结点的所有keys都小于它，右边孩子结点的所有keys都大于它。
*/
struct Node {
    bool leaf;//If having leaf node
    int n;//number of key
    int *keys;//key
    Node** siblings;//son pointer
    Node (int t, bool leaf) {
        this->leaf = leaf;
        this->n = 0;
        this->keys = new int[2 * t -1];
        this->siblings = new Node*[2*t]{0};
    }
};

class BTree
{
public:
    int t; // Minimum Degree
    Node * root;
private:
    void destroy(Node * node);
    void split_child(Node * parent, int i, Node * child);
    void insert_non_full(Node * node, int key);
    bool find_real(Node * node, int key);
    void merge(Node * node, int i);
    void erase_real(Node * node, int key);
public:
    BTree(int t);
    ~BTree();
    void insert(int key);
    bool find(int key);
    void erase(int key);
    void print();
    void print_(Node* node,int layer);
};
//输入父子和孩子的位置(需要父亲有位置！)
void BTree::split_child(Node * parent, int i, Node * child) 
{
    Node *z = new Node(t, child->leaf);//储存最后一半的keys和孩子节点(如果有)
    //移动最后一半的keys和孩子节点到z中
    for(int j = 0; j < t-1; j++) {//key
        z->keys[j] = child->keys[t + j];
    }
    if (!child->leaf)//child
    {
        for (int j = 0; j < t; j++)
            z->siblings[j] = child->siblings[j + t];
    }
    //把中间的key移动到parent首先要空出位置(右移)
    for (int j = parent->n; j >= i + 1; j--)
        parent->siblings[j + 1] = parent->siblings[j];
    for (int j = parent->n - 1; j >= i; j--)
        parent->keys[j + 1] = parent->keys[j];
    //移动
    parent->keys[i] = child->keys[t - 1]; 

    z->n = t - 1;
    child->n = t - 1;
    parent->siblings[i + 1] = z;
    parent->n++;
}
void BTree::insert_non_full(Node * node, int key)
{
    int i = node->n -1;//最大的key
    if(node->leaf) {//对于叶节点 从右向左查找并插入
        while(i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--; 
        }
        node->keys[i + 1] = key;
        node->n++;
    } else 
    {  //不是叶节点
        while (i >= 0 && node->keys[i] > key)
            i--;
        // 每次下降的时候，都要检查下降的那个结点的 keys 数是不是等于上限 2t-1，如果是就要做一分为二处理
        if (node->siblings[i + 1]->n == 2 * t - 1)
        {
            split_child(node, i + 1, node->siblings[i + 1]);
            if (node->keys[i + 1] < key)
                i++;
        }
        //下降
        insert_non_full(node->siblings[i + 1], key);
    }

}
void BTree::insert(int key) {
    //如果不存在直接创建
    if(!root) {
        root = new Node(t, true);
        root->keys[0] = key;
        root->n = 1;
    } else {
        //根节点已经满了（总高度可能上升一层）
        if(root->n == 2*t-1){
            Node *s = new Node(t, false);
            s->siblings[0] = root;
            split_child(s, 0, root);
            int i = 0;
            if (s->keys[0] < key)
                i++;
            insert_non_full(s->siblings[i], key);
            root = s;
        }
        //根节点没满
        else {
            insert_non_full(root, key);
        }

    }
}
void BTree::erase(int key) 
{
    if(!root) return;
    erase_real(root, key);

    if (root->n == 0)//如果根没有key了
    {
        Node * t = root;

        if (root->leaf)
            root = nullptr;
        else
            root = root->siblings[0];

        delete t;
    }
}
//内结点x的第i个子结点y和第i+1个子结点z的关键字数都是t-1，此时需要把内结点x的第i个关键字下移与y和z的合并，形成一个结点y。
void BTree::merge(Node * node, int i)
{
    Node * cur = node->siblings[i];
    Node * next = node->siblings[i + 1];

    // 夹在中间的那个 key 移过来(下降)[j + t] = next->keys[j];
    if (!cur->leaf)
    cur->keys[t - 1] = node->keys[i];

    // 再把兄弟结点里的所有信息合并过来
    for (int j = 0; j < next->n; j++)
        cur->keys[j + t] = next->keys[j];
    if (!cur->leaf)
    {
        for (int j = 0; j <= next->n; j++)
            cur->siblings[j + t] = next->siblings[j];
    }

    // 夹在中间的那个 key 被移走，造成位置空缺，所以就全部往前挪一步
    for (int j = i + 1; j < node->n; j++)
        node->keys[j - 1] = node->keys[j];
    for (int j = i + 2; j <= node->n; j++)
        node->siblings[j - 1] = node->siblings[j];

    cur->n += next->n + 1;
    node->n--;

    delete next;
}
void BTree::erase_real(Node* node, int key) 
{
    int i = 0;
    //找到第一个大于等于 key 的位置
    while(i < node->n && node->keys[i] < key) {
        i++;
    }
    if (i < node->n && node->keys[i] == key) // 如果在当前结点找到 key
    {
        if (node->leaf) //当前结点是叶子的话，直接删除
        {
            for (int j = i + 1; j < node->n; j++)
                node->keys[j - 1] = node->keys[j];

            node->n--;
        }else //当前结点不是叶子的话，分为三种情况
        {
            // 如果 key 的左边那个孩子结点 keys 数大于 t-1 ，就用 key 的前驱替换 key，问题转化为删除前驱
            if (node->siblings[i]->n > t - 1)
            {
                Node * left = node->siblings[i];

                while (!left->leaf)
                    left = left->siblings[left->n - 1];

                int precursor_key = left->keys[left->n - 1];
                node->keys[i] = precursor_key;

                erase_real(node->siblings[i], precursor_key);
            }
            // 如果 key 的右边那个孩子结点 keys 数大于 t-1 ，就用 key 的后继替换 key，问题转化为删除后继
            else if (node->siblings[i + 1]->n > t - 1)
            {
                Node * right = node->siblings[i + 1];

                while (!right->leaf)
                    right = right->siblings[0];

                int successor_key = right->keys[0];
                node->keys[i] = successor_key;

                erase_real(node->siblings[i + 1], successor_key);
            }
            // 如果左右两个孩子结点 keys 都等于 t-1，那就进行合并操作，再删除
            else
            {
                merge(node, i);
                erase_real(node->siblings[i], key);
            }

        }
    }
    else // 如果未在当前结点找到 key
    {
        if (node->leaf) // 是叶子的话，说明根本不存在该 key
        {
            cout << "The key " << key << " is not existed !\n";
            return;
        }
        bool flag = (i == node->n) ? true : false;//是否为最右节点
        // 每次下降的时候，都要检查下降的那个结点的 keys 数是不是等于下限 t-1，如果是就要做填充处理，分为三种情况
        if (i != 0 && node->siblings[i - 1]->n > t - 1) // 左兄弟结点 keys 数大于 t-1
            {
                Node * cur = node->siblings[i];
                Node * pre = node->siblings[i - 1];

                for (int j = cur->n - 1; j >= 0; j--)
                    cur->keys[j + 1] = cur->keys[j];

                if (!cur->leaf)
                {
                    for (int j = cur->n; j >= 0; j--)
                        cur->siblings[j + 1] = cur->siblings[j];

                    cur->siblings[0] = pre->siblings[pre->n];
                }

                cur->keys[0] = node->keys[i - 1];
                node->keys[i - 1] = pre->keys[pre->n - 1];
                cur->n++;
                pre->n--;
            }
            else if (i != node->n && node->siblings[i + 1]->n > t - 1) // 右兄弟结点 keys 数大于 t-1
            {
                Node * cur = node->siblings[i];
                Node * next = node->siblings[i + 1];

                for (int j = 1; j < next->n; j++)
                    next->keys[j - 1] = next->keys[j];

                if (!next->leaf)
                {
                    for (int j = 1; j < next->n; j++)
                        next->siblings[j - 1] = next->siblings[j];

                    cur->siblings[cur->n + 1] = next->siblings[0];
                }

                cur->keys[cur->n] = node->keys[i];
                node->keys[i] = next->keys[0];
                cur->n++;
                next->n--;
            }
            else // 如果左右兄弟结点 keys 数都等于 t-1，则对它们进行合并
            {
                if (i != node->n)
                    merge(node, i);
                else
                    merge(node, i - 1);
            }
            if (flag && i > node->n)
            erase_real(node->siblings[i - 1], key);
            else
            erase_real(node->siblings[i], key);

    }


}
bool BTree::find_real(Node* node, int key) {
    int i = 0;
    //对于每个节点 如果比他小就向右走
    while(i < node->n && (node->keys[i] < key)) {
        i++;
    }
    if(node->keys[i] == key) {
        return true;
    }
    if(node->leaf) {
        return false;
    }
    //递归
    return find_real(node->siblings[i],key);
}
bool BTree::find(int key) {
    if(root) {
        return find_real(root, key);
    }
    return false;

}
//traversal print
void BTree::print() {
    if(root) {
        queue<Node*> q;
        q.push(root);
 
        while(!q.empty()) {
            Node*p = q.front();
            q.pop();
            for(int i = 0;i <p->n;i++) {
                cout<<p->keys[i]<<" ";
            }
            cout<<'\n';
            if(!p->leaf) {
                for(int i = 0;i <p->n+1;i++) {//!n+1
                q.push(p->siblings[i]);
                }
            }
        }
        cout<<'\n';
    }
}

void BTree::print_(Node* node,int layer) 
{
    int i;
    Node *p = node;
    if(p) {
        cout<<"第"<<layer<<"层"<<p->n<<"个";
    
    for(int i = 0;i <p->n;i++) {
                cout<<p->keys[i]<<" ";
    }
    cout<<'\n';
    ++layer;
    for( i = 0;i <= p->n;i++) {
        if(node->siblings[i]){
            print_(node->siblings[i], layer);
        }
    }
    }
    else{cout<<"sempty tree！\n";}
}

void BTree::destroy(Node * node)
{
    if (node->siblings[0])
    {
        for (int i = 0; i <= node->n; i++)
            destroy(node->siblings[i]);
    }

    delete node;
}

BTree::BTree(int t)
{
    this->t = t;
    this->root = nullptr;
}

BTree::~BTree()
{
    if (root)
        destroy(root);
}

int main(){
    BTree btree(2);

    // test "insert"
    btree.insert(1);
    btree.insert(2);
    //btree.print();
    btree.insert(3);
    btree.insert(4);
    // btree.insert(1);
    // btree.insert(3);
    // btree.insert(7);
    // btree.insert(10);
    // btree.insert(11);
    // btree.insert(13);
    // btree.insert(14);
    // btree.insert(15);
    // btree.insert(18);
    // btree.insert(16);
    // btree.insert(19);
    // btree.insert(24);
    // btree.insert(25);
    // btree.insert(26);
    // btree.insert(21);
    // btree.insert(4);
    // btree.insert(5);
    // btree.insert(20);
    // btree.insert(22);
    // btree.insert(2);
    // btree.insert(17);
    // btree.insert(12);
    // btree.insert(6);
    btree.print();
    btree.print_(btree.root,1);
    return 0;
}