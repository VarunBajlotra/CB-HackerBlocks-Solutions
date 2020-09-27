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


void BubbleSort(node *&head)
    {int len=length(head);
     node *current,*prev,*n;
     for(int i=0;i<len;i++)
        {current=head;
         prev=NULL;
         while(current && current->next)
            {n=current->next;
                {if(prev==NULL)
                    {if(current->data>current->next->data)
                        {current->next=n->next;
                        n->next=current;
                        head=n;
                        prev=n;
                        }
                     else
                        {prev=current;
                         current=current->next;
                        }
                    }
                 else
                    {if(current->data>current->next->data)
                        {current->next=n->next;
                         prev->next=n;
                         n->next=current;
                         prev=n;
                        }
                     else
                        {prev=current;
                         current=current->next;
                        }
                    }
                }
            }
        }
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

node *merge(node *a,node *b)
    {if(a==NULL)
        {return b;
        }
     if(b==NULL)
        {return a;
        }
     node *c;
     if(a->data<b->data)
        {c=a;
         c->next=merge(a->next,b);
        }
     else
        {c=b;
         c->next=merge(a,b->next);
        }
     return c;
    }

node *mergeSort(node *head)
    {if(head==NULL||head->next==NULL)
        return head;
     node *m=mid(head);
     node *a=head;
     node *b=m->next;
     m->next=NULL;
     a=mergeSort(a);
     b=mergeSort(b);
     node *newHead=merge(a,b);
     return newHead;
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
 head=mergeSort(head);
 print(head);
 return 0;
}
