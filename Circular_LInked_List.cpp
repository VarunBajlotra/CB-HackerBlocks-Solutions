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

node *CreateLL()
    {node *head=NULL;
     int data;
     cin>>data;
     while(data!=-1)
        {node *n=new node(data);
         n->next=head;
         head=n;
         cin>>data;
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

 void cir(node *&head)
    {node *temp=head->next;
     int flag=0;
     while(temp)
        {node *temp1=head;
         while(temp1->next!=temp)
            {if(temp1->data==temp->data)
                {node *temp2=head;
                 while(temp2->next!=temp)
                    {temp2=temp2->next;
                    }
                 temp2->next=NULL;
                 flag=1;
                 break;
                }
             temp1=temp1->next;
            }
         if(flag==1)
            break;
         temp=temp->next;
        }
    }

 void print(node *head)
    {while(head)
        {cout<<head->data<<" ";
         head=head->next;
        }
    }

int main()
{node *head=CreateLL();
 ReverseLL(head);
 cir(head);
 print(head);
 return 0;
}
