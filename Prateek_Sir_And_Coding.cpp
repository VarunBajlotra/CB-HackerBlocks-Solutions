#include<iostream>
#include<cstring>
//#include "Stack.h"

using namespace std;

class node
{public:
    int data;
    node *next;

    node(int d):data(d),next(NULL)
        {
        }
};

class stack
{   node *head;
    int cs;
public:
    stack()
        {head=NULL;
         cs=0;
        }

    void push(int data)
        {node *n=new node(data);
         n->next=head;
         head=n;
         cs++;
        }

    void pop()
        {node *temp=head;
         head=head->next;
         delete temp;
         cs--;

        }

    int top()
        {return head->data;
        }

    bool empty()
        {if(cs==0)
            return true;
         return false;
        }
};

int main()
{int n,num1,num2;
 cin>>n;
 stack s;
 for(int i=0;i<n;i++)
    {cin>>num1;
     if(num1==1)
        {if(!s.empty())
            {cout<<s.top()<<endl;
             s.pop();
            }
         else
            cout<<"No Code"<<endl;
        }
     else if(num1==2)
        {cin>>num2;
         s.push(num2);
        }
    }
 return 0;
}

