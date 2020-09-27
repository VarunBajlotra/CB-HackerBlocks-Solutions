#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{long long n,num,q,k;
 vector<long long> v;
 cin>>n;
 for(long long i=0;i<n;i++)
    {cin>>num;
     v.push_back(num);
    }
 for(long long i=0;i<n;i++)
    {cin>>num;
     v[i]+=num;
    }
 for(long long i=0;i<n;i++)
    {cin>>num;
     v[i]+=num;
    }
 cin>>q;
 sort(v.begin(),v.end());
 for(long long j=0;j<q;j++)
    {cin>>k;
     if(k>v.size())
        {cout<<"-1"<<endl;
        }
     else
        {cout<<v[k-1]<<endl;
         v.erase(v.begin()+k-1);
        }
    }
 return 0;
}
