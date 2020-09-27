#include<bits/stdc++.h>
using namespace std;

class Class
{
 public:
    bool operator()(long long a,long long b)
        {return a>b;
        }
};

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
     long long int num,sum,cs,n,k;
     sum=0,cs=0;
     priority_queue<long long int> h;
     cin>>n>>k;
     for(int i=0;i<n;i++)
     {
        cin>>num;
        h.push(num);
     }
     while(k--)
     {
        long long int t=h.top();
        sum=sum+h.top();
        h.pop();
        h.push(t/2);
     }
     cout<<sum<<endl;
    }
 return 0;
}
