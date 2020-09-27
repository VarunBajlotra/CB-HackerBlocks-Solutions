#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class node
{public:
    char data;
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

    int size()
        {return cs;
        }

    void print()
        {node *temp=head;
         while(temp!=NULL)
            {cout<<temp->data;
             temp=temp->next;
            }
         cout<<endl;
        }

    bool empty()
        {if(cs==0)
            return true;
         return false;
        }
};

int main()
{int t;
 cin>>t;
 string str;
 while(t--)
    {stack s;
     cin>>str;
     int i=0,count1=0;
     while(i<str.length())
        {if(str[i]!=')')
            {s.push(str[i]);
            }
         else if(str[i]==')')
            {count1=0;
             while(s.top()!='(')
                {s.pop();
                 count1++;
                }
             s.pop();
             if(count1==0)
                {cout<<"Duplicate"<<endl;
                 break;
                }
            }
         i++;
        }
     if(count1!=0)
        cout<<"Not Duplicates"<<endl;
    }
 return 0;
}
