#include<iostream>
#include<queue>

using namespace std;

class node
{public:
 int data;
 node *left;
 node *right;

 node(int d):data(d),left(NULL),right(NULL)
    {
    }
};

node *LevelOrderInput()
    {queue<node*> q;
     int  data;
     cin>>data;
     node *root=new node(data);
     q.push(root);
     while(!q.empty())
        {node *temp=q.front();
         q.pop();
         int c1,c2;
         cin>>c1>>c2;
         if(c1!=-1)
            {temp->left=new node(c1);
             q.push(temp->left);
            }
         if(c2!=-1)
            {temp->right=new node(c2);
             q.push(temp->right);
            }
        }
      return root;
    }

void print1(node *root)
    {if(root==NULL)
        return;
     print1(root->left);
     cout<<root->data<<" ";
    }

void print2(node *root)
    {if(root==NULL)
        return;
     cout<<root->data<<" ";
     print2(root->right);
    }

int main()
{node *root=LevelOrderInput();
 print1(root);
 print2(root->right);
 return 0;
}
