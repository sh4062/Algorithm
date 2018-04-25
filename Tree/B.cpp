/*所有的叶子结点在同一层； 
每棵B-树有一个Minimum Degree(度)，称其为t；其中度t的值由磁盘块的大小来决定
除了根结点，其余每个结点至少包含t-1个keys，根结点可以只包含1个key；
每个结点（包括根结点）最多包含2t-1个keys；
一个结点的孩子指针数等于这个结点的keys数+1；
每个结点的keys都按升序排列；
对于每个key，其左边孩子结点的所有keys都小于它，右边孩子结点的所有keys都大于它。
*/
//或者 t度 的B树就是 2t阶 的B树(这也是B树的分裂机制决定的)

/* m阶
1、根节点至少有两个孩子
2、每个非根节点有[ M/2，M ]个孩子
3、每个非根节点有[ (M/2) -1，M-1 ]个关键字，并且以升序排序
4、key[i]和key[i+1]之间的孩子节点的值介于两者之间
5、所有的叶子节点都在同一层
*/
struct Node
{
    bool leaf;        // 是否是叶子结点
    int n;            // keys 的数目
    int * keys;       // 保存 keys
    Node ** siblings; // 保存孩子指针
    
    Node(int t, bool leaf)
    {
        this->leaf = leaf;
        this->n = 0;
        this->keys = new int[2 * t - 1];
        this->siblings = new Node*[2 * t]{ 0 };
    }
};

class BTree
{
private:
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
};