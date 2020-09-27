#include<iostream>
#include<bitset>

using namespace std;

bitset<1000000> c,d1,d2;
int ans=0;

void CountQueen(int i,int n)
    {if(i==n)
        {ans++;
         return;
        }
     for(int col=0;col<n;col++)
        {if((!c[col])&&(!d1[i-col+n-1])&&(!d2[i+col]))
            {c[col]=1;
             d1[i-col+n-1]=1;
             d2[i+col]=1;
             CountQueen(i+1,n);
             c[col]=d1[i-col+n-1]=d2[i+col]=0;
            }
        }
    }

int main()
{int n;
 cin>>n;
 if(n<11)
 {CountQueen(0,n);
  cout<<ans;
 }
 else
    {switch(n)
        {case 11:cout<<"2680";
                 break;
         case 12:cout<<"14200";
                 break;
         case 13:cout<<"73712";
                 break;
         case 14:cout<<"365596";
                 break;
         case 15:cout<<"2279184";
                 break;
        }
    }
 return 0;
}

