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
{stack s;
 string str;
 cin>>str;
 int i=0,flag=0,flag1=0;
 while(i<str.length())
    {if(str[i]=='('||str[i]=='{'||str[i]=='[')
        {s.push(str[i]);
         flag1++;
        }
     if(str[i]==')')
        {if(!s.empty())
            {if((char)(s.top())=='(')
                {if(!s.empty())
                    s.pop();
                 else
                    {flag=1;
                    }
                }
             else
                {flag=1;
                 break;
                }
            }
         else
            {flag=1;
             break;
            }
        }
     if(str[i]=='}')
        {if(!s.empty())
            {if((char)(s.top())=='{')
                {if(!s.empty())
                    s.pop();
                 else
                    {flag=1;
                    }
                }
             else
                {flag=1;
                 break;
                }
            }
         else
            {flag=1;
             break;
            }
        }
     if(str[i]==']')
        {if(!s.empty())
            {if((char)(s.top())=='[')
                {if(!s.empty())
                    s.pop();
                 else
                    {flag=1;
                    }
                }
             else
                {flag=1;
                 break;
                }
            }
         else
            {flag=1;
             break;
            }
        }
     i++;
    }
 if(flag1==str.length())
    {flag=1;
    }
 if(!s.empty())
    {flag=1;
    }
 if(flag==0)
    cout<<"Yes";
 else
    cout<<"No";
 return 0;
}
