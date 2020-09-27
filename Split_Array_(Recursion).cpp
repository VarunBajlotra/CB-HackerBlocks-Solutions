#include<iostream>

using namespace std;

int count=0;

void subs(int *arr,int *res1,int *res2,int i,int j,int k,int n)
    {if(i==n)
        {int suml=0,sumr=0;
         for(int a=0;a<j;a++)
            suml+=res1[a];
         for(int b=0;b<k;b++)
            sumr+=res2[b];
         if(suml==sumr)
            {for(int a=0;a<j;a++)
                cout<<res1[a]<<" ";
             cout<<"and ";
             for(int b=0;b<k;b++)
                cout<<res2[b]<<" ";
             cout<<endl;
             count++;
            }
         return;
        }
     res1[j]=arr[i];
     subs(arr,res1,res2,i+1,j+1,k,n);
     res2[k]=arr[i];
     subs(arr,res1,res2,i+1,j,k+1,n);
    }

int main()
{int n,*arr,*res1,*res2;
 cin>>n;
 arr=new int[n];
 res1=new int[n];
 res2=new int[n];
 for(int i=0;i<n;i++)
    cin>>arr[i];
 subs(arr,res1,res2,0,0,0,n);
 cout<<count;
 return 0;
}
