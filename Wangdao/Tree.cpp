 #include<iostream>
 #include<vector>
 #include <sstream>
 using namespace std;
 vector<int> res;
 struct Node {
     int val;
     Node *left;
     Node *right;
     Node(int x) : val(x), left(NULL), right(NULL) {}
  };

  
  void InsertT(Node *&r,int a){
      if(r == NULL){
          r = new Node(a);
          return;
      }
      else if(a > r->val){ InsertT(r->right,a);}
      else{InsertT(r->left,a);}
  }
  string its(int a){
    ostringstream oss;
    oss << a;
    return oss.str();

}
  void MT(Node* r1,string &s){
      if(r1!=NULL){
          s=s+its(r1->val);
          MT(r1->left,s);
          
          //cout<<r1->val;
          MT(r1->right,s);
      
  }}
//公共祖先
  Node *LCA(Node *r,Node *a,Node*b){
      if (r == NULL)
        return  NULL;
        if(r == a|| r==b)return r;
        Node * left = LCA(r->left, a, b);
        Node * right = LCA(r->right, a, b);
        if (left && right)  // 分别在左右子树
        return r;
       return left ? left : right; 


  }
  //前中推后

  int pre_order_arry[1111];
int in_order_arry[1111];

void PrintPostOrder(int pos1, int pos2, int n)
{
    if (n == 1)
    {
        cout << pre_order_arry[pos1];
        return;
    }
    if (n == 0)
        return;
  
    int i = 0;
    for (; pre_order_arry[pos1] != in_order_arry[pos2 + i]; i++)
        ;
  
    PrintPostOrder(pos1 + 1, pos2, i);
    PrintPostOrder(pos1 + i + 1, pos2 + i + 1, n - i - 1);
    cout << pre_order_arry[pos1];
}

  int main(){
      int n;
        cin>>n;
        string s1;
        string r1 = "";
        cin>>s1;
        Node *root =new Node(int(s1[0])-48);
        //cout<<root->val;
        
        for(int i=1;i<s1.size();i++){
            InsertT(root,int(s1[i])-48);
        }
        MT(root,r1);
        while(n--){
            string s2;
        cin>>s2;
        Node *root2 =new Node(int(s2[0])-48);
        for(int i=1;i<s2.size();i++){
            InsertT(root2,int(s2[i])-48);
        }
        string r2 = "";
        MT(root2,r2);
        if(!r2.compare(r1)){cout<<"YES"<<'\n';}
        else{cout<<"NO"<<'\n';}
        //cout<<r1;

        }

    
  }