#include<iostream>
#include<queue>

using namespace std;

int arr[100]={0};

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
            {
             if(temp->left)
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

int indx=0;
node *CreateTree(int *in,int *pre,int s,int e)
    {if(s>e)
        return NULL;
     int data=pre[indx++];
     node *root=new node(data);
     int k=-1;
     for(int i=s;i<=e;i++)
        {if(data==in[i])
            {k=i;
             break;
            }
        }
     root->left=CreateTree(in,pre,s,k-1);
     root->right=CreateTree(in,pre,k+1,e);
     return root;
    }

int main()
{int n,m,*pre,*in;
 cin>>n;
 pre=new int[n];
 for(int i=0;i<n;i++)
    cin>>pre[i];
 cin>>m;
 in=new int[m];
 for(int i=0;i<m;i++)
    cin>>in[i];
 node *root=CreateTree(in,pre,0,n-1);
 LevelOrder(root);
 return 0;
}
