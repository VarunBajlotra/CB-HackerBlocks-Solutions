#include<bits/stdc++.h>

using namespace std;

//Make the code modern

class node{
public:
 int data;
 node *left;
 node *right;
 node(int d):data(d),left(NULL),right(NULL){
 }
};

node *LevelOrderInput(){
     queue<node*> q;
     int newVal;
     cin>>newVal;
     node *root=new node(newVal);
     q.push(root);
     while(!q.empty()){
         node *temp=q.front();
         q.pop();
         int n1,n2;
         cin>>n1>>n2;
         if(n1!=-1)
            {temp->left=new node(n1);
             q.push(temp->left);
            }
         if(n2!=-1)
            {temp->right=new node(n2);
             q.push(temp->right);
            }
        }
      return root;
}

void print1(node *root){
     if(!root)
        return;
     print1(root->left);
     cout<<root->data<<" ";
}

void print2(node *root){
     if(!root)
        return;
     cout<<root->data<<" ";
     print2(root->right);
}

int main(){
 node *root=LevelOrderInput();
 print1(root);
 print2(root->right);
 return 0;
}
