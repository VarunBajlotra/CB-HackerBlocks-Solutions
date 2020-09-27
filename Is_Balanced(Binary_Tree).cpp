#include<iostream>
using namespace std;
class node
{
  public:
  int data;
  int height;
  node*left;
  node*right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
        height=0;
    }
};
node*buildtree()
{   string s;
    int d;
    cin>>s;
    if(s[0]=='t')
    {
      cin>>d;
      node*root=new node(d);
      root->left=buildtree();
      root->right=buildtree();

      return root;
    }
    else return NULL;

}
int store_height(node*root)
{
    if(root==NULL)
    {
       return 0;
    }

      int leftheight=store_height(root->left);
      int rightheight=store_height(root->right);

    root->height=1+max(leftheight,rightheight);

    return root->height;
}
bool is_balanced(node*root)
{


    if( (root->left==NULL || root->right==NULL ) && root->height<=2)
     return true;
    else if( (root->left==NULL || root->right==NULL ) && root->height>2)
     return false;


    if(is_balanced(root->left) && is_balanced(root->right))
    {

            if(((root->left->height)-(root->right->height))<=1)
         {
             return true;
         }

        else return false;
    }

    return false;
}
void inorder(node*root)
{
    if(root==NULL)
        return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return ;
}
int main()
{   int d;
    cin>>d;
    node*root=new node(d);
    root->left=buildtree();
    root->right=buildtree();
       int h=store_height(root);
     if(is_balanced(root))
      cout<<"true";
     else cout<<"false";

	return 0;
}
