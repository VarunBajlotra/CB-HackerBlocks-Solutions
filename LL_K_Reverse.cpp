#include<iostream>

using namespace std;

class node
{public:
    int data;
    node *next;
    node(int d):data(d),next(NULL)
        {
        }
};

node *CreateLL(node *head)
    {
     int data;
     cin>>data;
     if(head==NULL)
        {node *n=new node(data);
         head=n;
        }
     else
     {
     node *temp=head;
     while(temp->next!=NULL)
        {temp=temp->next;
        }
     node *n=new node(data);
     temp->next=n;
     }
     return head;
    }

void ReverseLL1(node *&head,int a,int b,int k)
    {if(a==0)
        {int i=0;
         node *prev=head;
         node *cur=head->next;
         node *n;
         while(i<k-1)
            {n=cur->next;
             cur->next=prev;
             prev=cur;
             head=cur;
             cur=n;
             i++;
            }
         node *temp=head;
         int j=0;
         while(j<k-1)
            {temp=temp->next;
             j++;
            }
         temp->next=n;
        }
    }

void ReverseLL2(node *head,int a,int b,int k)
    {node *temp=head;
     int i=0;
     while(i<a)
        {temp=temp->next;
         i++;
        }
     int h=0;
     node *temp2=head;
     while(h<a-1)
        {temp2=temp2->next;
         h++;
        }
     node *prev=temp;
     node *cur=temp->next;
     node *n;
     int j=0;
     while(j<k-1)
        {n=cur->next;
         temp->next=n;
         cur->next=prev;
         temp2->next=cur;
         prev=cur;
         cur=n;
         j++;
        }
    }

void print(node *head)
    {while(head)
        {cout<<head->data<<" ";
         head=head->next;
        }
    }

int main()
{int n,k;
 cin>>n>>k;
 node *head=NULL;
 for(int i=0;i<n;i++)
    {head=CreateLL(head);
    }
 if(k!=1)
 {ReverseLL1(head,0,k,k);
  for(int j=k;j<=n-k;j=j+k)
    {ReverseLL2(head,j,j+k,k);
    }
 }
 print(head);
 return 0;
}
