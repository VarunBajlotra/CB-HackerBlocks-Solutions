#include<iostream>
#include<queue>
#include<climits>
#include<cmath>

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

node *ArrayToBST(int *a,int s,int e)
    {if(s>e)
        return NULL;
     int mid=(s+e)/2;
     node *root=new node(a[mid]);
     root->left=ArrayToBST(a,s,mid-1);
     root->right=ArrayToBST(a,mid+1,e);
     return root;
    }

int main()
{int t,n,*arr;
 cin>>t;
 while(t--)
    {cin>>n;
     arr=new int[n];
     for(int i=0;i<n;i++)
        cin>>arr[i];
     node *root=ArrayToBST(arr,0,n-1);
     PreOrder(root);
    }
 return 0;
}
