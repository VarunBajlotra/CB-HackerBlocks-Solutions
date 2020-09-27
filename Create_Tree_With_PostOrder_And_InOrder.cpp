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

void LevelOrder(node *root)
    {queue<node*> q;
     q.push(root);
     q.push(NULL);
     while(!q.empty())
        {node *temp=q.front();
         q.pop();
         if(temp)
            {if(temp->left)
                {cout<<temp->left->data<<" => ";
                 q.push(temp->left);
                }
             else
                {cout<<"END => ";
                }
             cout<<temp->data;
             if(temp->right)
                {cout<<" <= "<<temp->right->data;
                 q.push(temp->right);
                }
             else
                {cout<<" <= END";
                }
             cout<<endl;
            }
        }
    }

node *CreateTree(int *in,int *post,int s,int e,int &indx)
    {
        if(s<e)
          return NULL;
     if(indx<0)
        return NULL;
     int data=post[indx];
     indx--;
     node *root=new node(data);
     int k=-1;
     for(int i=s;i>=e;i--)
     {
       if(data==in[i])
       {
            k=i;
            break;
       }
    }
     root->right=CreateTree(in,post,s,k+1,indx);
     root->left=CreateTree(in,post,k-1,e,indx);
     return root;
    }

int main()
{int n,m,*post,*in;
 cin>>n;
 post=new int[n];
 for(int i=0;i<n;i++)
    cin>>post[i];
 cin>>m;
 in=new int[m];
 for(int i=0;i<m;i++)
    cin>>in[i];
    int index=n-1;
 node *root=CreateTree(in,post,n-1,0,index);
 LevelOrder(root);
 return 0;
}
