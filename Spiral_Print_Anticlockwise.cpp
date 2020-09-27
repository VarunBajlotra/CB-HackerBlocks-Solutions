#include<iostream>

using namespace std;

/*void wave_print(char a[10][10],int n,int m)
    {for(int i=0;i<m;i++)
        {if(i%2==0)
            {for(int j=0;j<n;j++)
                {cout<<a[j][i]<<",";
                }
            }
         else if(i%2!=0)
            {for(int j=n-1;j>=0;j--)
                {cout<<a[j][i]<<" ";
                }
            }
        }
     cout<<endl;
    }*/

void spiral_print(int a[10][10],int n,int m)
    {int str[100];
     int y=0,i=0;
     //cout<<"Rows:"<<m<<endl;
     //cout<<"Columns:"<<n<<endl;
     while(y<n*m)
        {for(int j=i;j<m-i;j++)
            {str[y]=a[j][i];
             //cout<<"@";
             y++;
            }
         for(int k=i+1;k<n-i;k++)
            {str[y]=a[m-i-1][k];
             //cout<<"#";
             y++;
            }
         for(int l=m-2-i;l>=i;l--)
            {str[y]=a[l][n-i-1];
             //cout<<"$";
             y++;
            }
         for(int u=n-2-i;u>i;u--)
            {str[y]=a[i][u];
             //cout<<"%";
             y++;
            }
         i++;
        }
     //cout<<endl;
     for(int b=0;b<m*n;b++)
        cout<<str[b]<<", ";
     cout<<"END";
    }

int main()
{int str[10][10];
 int n,m;
 cin>>m>>n;
 for(int i=0;i<m;i++)
    {for(int j=0;j<n;j++)
        cin>>str[i][j];
    }
 //wave_print(str,n,m);
 spiral_print(str,n,m);
 return 0;
}
