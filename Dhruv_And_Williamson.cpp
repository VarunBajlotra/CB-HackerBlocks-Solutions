#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>

using namespace std;

void countHigh(priority_queue<int> p)
    {int c=0,num=p.top();
     while(p.top()==num && !p.empty())
        {c++;
         p.pop();
        }
     cout<<c<<endl;
    }

void countLow(priority_queue<int, vector<int>, greater<int> > p)
    {int c=0,num=p.top();
     while(p.top()==num && !p.empty())
        {c++;
         p.pop();
        }
     cout<<c<<endl;
    }

int main()
{int n,count=0;
 cin>>n;
 priority_queue<int> p1;
 priority_queue<int, vector<int>, greater<int> > p2;
 while(n--)
    {string str;
     cin>>str;
     int choice;
     if(str=="Push")
        choice=1;
     else if(str=="Diff")
        choice=2;
     else if(str=="CountHigh")
        choice=3;
     else if(str=="CountLow")
        choice=4;
     switch(choice)
        {case 1:{int num;
                 cin>>num;
                 p1.push(num);
                 p2.push(num);
                 count++;
                 break;
                }
         case 2:{if(count==0)
                    cout<<"-1\n";

                 else
                    {int dif=p1.top()-p2.top();
                     cout<<dif<<endl;
                     count-=2;
                     if(count<0)
                        count=0;
                     p1.pop();
                     p2.pop();
                    }
                 break;
                }
         case 3:{if(count==0)
                    cout<<"-1\n";
                 else
                    countHigh(p1);
                 break;
                }
         case 4:{if(count==0)
                    cout<<"-1\n";
                 else
                    countLow(p2);
                 break;
                }
         }
    }
 return 0;
}
