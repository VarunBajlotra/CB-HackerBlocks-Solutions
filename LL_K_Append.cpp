
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


        {node *n=new node(data);
         n->next=head;
         head=n;

        }
     return head;
    }

int length(node *head)
    {int count=0;
     while(head)
        {count++;
         head=head->next;
        }
     return count;
    }

void ReverseLL(node* &head)
    {node *current=head;
     node *prev=NULL;
     node *n;
     while(current)
        {n=current->next;
         current->next=prev;
         prev=current;
         current=n;
        }
     head=prev;
    }

node *mid(node *head)
    {if(head==NULL || head->next==NULL)
        return head;
     node *slow=head;
     node *fast=head->next;
     while(fast!=NULL)
        {fast=fast->next;
         if(fast!=NULL)
            {fast=fast->next;
             slow=slow->next;
            }
        }
     return slow;
    }


 void _find(node *&head,int k)
    {int len=length(head);
     node *head1=head;
     node *temp=head;
     int i=0;
     while(i!=len-k-1)
        {temp=temp->next;
         i++;
        }
     node *temp1=temp->next;
     head=temp1;
     temp->next=NULL;
     while(temp1->next!=NULL)
        {temp1=temp1->next;
        }
     temp1->next=head1;
    }

void print(node *head)
    {while(head)
        {cout<<head->data<<" ";
         head=head->next;
        }
    }

int main()
{int n;
 cin>>n;
 node *head=NULL;
 for(int i=0;i<n;i++)
    {head=CreateLL(head);
    }
 ReverseLL(head);
 int k;
 cin>>k;
 //while(k>=n)
    k=k%n;
 if(k>=n)
    k=k%n;
 if(k!=0)
    _find(head,k);
 print(head);
 node *ptr=head;
 return 0;
}
