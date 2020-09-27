#include<iostream>

using namespace std;

int main()
{int m,n,k,ener,max=0;
 char str[102][102];
 cin>>n>>m;
 cin>>k>>ener;
 for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        cin>>str[i][j];
 for(int i=0;i<n;i++)
    {for(int j=0;j<m;j++)
        {if(str[i][j]=='.')
            ener-=2;
         if(str[i][j]=='*')
            ener+=5;
         if(str[i][j]=='#')
            continue;
         ener--;
        }
    }
    // ener-=12;
 if(ener>=k&&ener!=k+12)
    {cout<<"Yes"<<endl;
     cout<<ener;
    }
 else
    cout<<"No";
 return 0;
}
