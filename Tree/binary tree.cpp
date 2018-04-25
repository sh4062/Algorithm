#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    char c;
    struct node *left;
    struct node *right;
} Node, *pNode;
void preOrder(pNode p)
{
    if (p != NULL)
    {
        putchar(p->c);
        preOrder(p->left);
        preOrder(p->right);
    }
}
void midOrder(pNode p)
{
    if (p != NULL)
    {

        midOrder(p->left);
        putchar(p->c);
        midOrder(p->right);
    }
}
void postOrder(pNode p)
{
    if (p != NULL)
    {

        postOrder(p->left);
        postOrder(p->right);
        putchar(p->c);
    }
}
const int N = 10;
int main()
{
    char c[N + 1] = "ABCDEFGHIJ";
    int i, j,pos=0;
    pNode a[N];
    for (i = 0; i < N; i++)
    {
        a[i] = (pNode)calloc(1, sizeof(Node));
        a[i]->c = c[i];
    }
    for (i = 1; i < N; i++) //要进入树的元素
    {
            if (NULL == a[pos]->left) //没有左子节点
            {
                a[pos]->left = a[i];
               
            }
            else if (NULL == a[pos]->right)
            {
                a[pos]->right = a[i];
                pos++;
            }
        
    }
    preOrder(a[0]);
    printf("\n");
    midOrder(a[0]);
    printf("\n");
    postOrder(a[0]);
}