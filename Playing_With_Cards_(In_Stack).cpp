#include<iostream>
#include<stack>
#include<cmath>

using namespace std;

int check[8000]={0},arr[1000],c=0;

void sieve()
    {arr[c++]=2;
     arr[c++]=3;
     for(int i=2;i<7900;i+=2)
        check[i]=1;
     for(int i=3;i<7900;i+=3)
        check[i]=1;
     for(int i=5;i<7900;i++)
        {if(check[i]==0)
            {int flag=0;
             for(int j=2;j<=sqrt(i);j++)
                {if(i%j==0)
                    {flag=1;
                     break;
                    }
                }
             if(flag==0)
                {arr[c++]=i;
                 for(int j=i;j<7900;j+=i)
                    {check[j]=1;
                    }
                }
            }
        }
    }

int main()
{int n,q;
 cin>>n>>q;
 stack<int> a,b;
 sieve();
 for(int i=0;i<n;i++)
    {int num;
     cin>>num;
     a.push(num);
    }
 for(int i=0;i<q;i++)
    {int temp[1000],c1=0;
     while(!a.empty())
        {int num=a.top();
         if(num%arr[i]==0)
            {b.push(num);
            }
         else
            {temp[c1++]=num;
            }
         a.pop();
        }
     for(int j=0;j<c1;j++)
        a.push(temp[j]);
     while(!b.empty())
        {cout<<b.top()<<endl;
         b.pop();
        }
    }
 while(!a.empty())
    {cout<<a.top()<<endl;
     a.pop();
    }
 return 0;
}
