#include<iostream>

using namespace std;

int main()
{int n,arr[1000],res[1000]={0};
 cin>>n;
 for(int i=0;i<n;i++)
    {cin>>arr[i];
     res[i]=1;
    }
 for(int i=1;i<=n;i++)
    {int j=i-1;
     while(j>0&&arr[j-1]<=arr[i-1])
        {res[i-1]++;
         j--;
        }
    }
 for(int i=0;i<n;i++)
    cout<<res[i]<<" ";
 cout<<"END";
 return 0;
}
