#include<iostream>
#include<climits>

using namespace std;

class node
{public:

    int data;
    node *left;
    node *right;

    node(int d)
        {data=d;
         left=NULL;
         right=NULL;
        }

};

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

struct deets
    {int size;
     int max;
     int min;
     int ans;
     bool isBST;
    };

deets largestBST(node *root)
    {if(root==NULL)
        return {0,INT_MIN,INT_MAX,0,true};
     if(root->left==NULL && root->right==NULL)
        return {1,root->data,root->data,1,true};
     deets left=largestBST(root->left);
     deets right=largestBST(root->right);
     deets res;
     res.size=left.size+right.size+1;
     if(left.isBST && right.isBST && root->data>left.max && root->data<right.min)
        {res.min=min(left.min, min(right.min,root->data) );
         res.max=max(left.max, max(right.max,root->data) );
         res.ans=res.size;
         res.isBST=true;
         return res;
        }
     res.ans=max(left.ans,right.ans);
     res.isBST=false;
     return res;
    }

int main()
{int n,*in,*pre;
 cin>>n;
 pre=new int[n];
 in=new int[n];
 for(int i=0;i<n;i++)
    cin>>pre[i];
 for(int i=0;i<n;i++)
    cin>>in[i];
 node *root=CreateTree(in,pre,0,n-1);
 deets d=largestBST(root);
 cout<<d.ans;
 return 0;
}
