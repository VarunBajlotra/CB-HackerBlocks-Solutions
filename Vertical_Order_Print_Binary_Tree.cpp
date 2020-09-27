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

void PreOrder(node *root)
    {if(root==NULL)
        return;
     cout<<root->data<<" ";
     PreOrder(root->left);
     PreOrder(root->right);
    }

void LevelOrder(node *root)
    {queue<node*> q;
     q.push(root);
     q.push(NULL);
     while(!q.empty())
        {node *temp=q.front();
         q.pop();
         if(temp==NULL)
            {cout<<endl;
             if(!q.empty())
                q.push(NULL);
            }
         else
            {cout<<temp->data<<" ";
             if(temp->left)
                q.push(temp->left);
             if(temp->right)
                q.push(temp->right);
            }
        }
    }

node *LevelOrderInput()
    {queue<node*> q;
     int data;
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

 void findMinMax(node *root,int *min,int *max,int hd)
    {if(root==NULL)
        return;
     if(hd<*min)
        *min=hd;
     if(hd>*max)
        *max=hd;
     findMinMax(root->left,min,max,hd-1);
     findMinMax(root->right,min,max,hd+1);
    }

 void print(node *root,int i,int hd)
    {if(root==NULL)
        return;
     if(i==hd)
        cout<<root->data<<" ";
     print(root->left,i,hd-1);
     print(root->right,i,hd+1);
    }

int main()
{int n;
 cin>>n;
 node *root=LevelOrderInput();
 int min=0,max=0;
 findMinMax(root,&min,&max,0);
 for(int i=min;i<=max;i++)
    {print(root,i,0);
     cout<<endl;
    }
 return 0;
}
