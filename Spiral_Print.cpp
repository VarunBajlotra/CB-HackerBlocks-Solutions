#include<iostream>

using namespace std;

void spiral_print(int a[1000][1000],int n,int m)
    {int str[1000];
     int y=0,i=0;
     while(y<n*m)
        {if(y==n*m)
            break;
         for(int j=i;j<n-i;j++)
            {cout<<a[i][j]<<" ";
             y++;
            }
         if(y==n*m)
            break;
         for(int k=i+1;k<m-i;k++)
            {cout<<a[k][n-1-i]<<" ";
             y++;
            }
         if(y==n*m)
            break;
         for(int l=n-2-i;l>=i;l--)
            {cout<<a[m-1-i][l]<<" ";
             y++;
            }
         if(y==n*m)
            break;
         for(int u=m-2-i;u>i;u--)
            {cout<<a[u][i]<<" ";
             y++;
            }
         if(y==n*m)
            break;
         i++;
        }
    }

int main()
{int str[1000][1000];
 int n,m;
 cin>>m>>n;
 for(int i=0;i<m;i++)
    {for(int j=0;j<n;j++)
        cin>>str[i][j];
    }
 spiral_print(str,n,m);
 return 0;
}
