#include<iostream>
#include<queue>

using namespace std;

class Meracomparator
{
 public:
    bool operator()(int a,int b)
        {return a>b;
        }
};

int main()
{int t,n,m,num;
 cin>>t;

 while(t--)
 {
 priority_queue<int, vector<int>, Meracomparator> h;
 cin>>n;
 for(int j=0;j<n;j++)
    {cin>>num;
     h.push(num);
    }
 cin>>m;
 for(int j=0;j<m;j++)
    {cin>>num;
     h.push(num);
    }

 while(!h.empty())
    {cout<<h.top()<<" ";
     h.pop();
    }
}
 return 0;
}
