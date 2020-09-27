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
{int k,n,num;
 priority_queue<int, vector<int>, Meracomparator> h;
 cin>>k>>n;
 for(int i=0;i<k;i++)
    {for(int j=0;j<n;j++)
        {cin>>num;
         h.push(num);
        }
    }
 while(!h.empty())
    {cout<<h.top()<<" ";
     h.pop();
    }
 return 0;
}
