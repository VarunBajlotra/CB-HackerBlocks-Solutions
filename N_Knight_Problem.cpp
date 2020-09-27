#include<iostream>
using namespace std;

int count=0,arr[10000000][3],num=0;

bool canplace(int a[1000][1000],int i,int j,int n)
{
    if((i-2)>=0 && (j-1)>=0)
    {
        if(a[i-2][j-1])
            return false;
    }
    if((i-2)>=0 && (j+1)<n)
    {
        if(a[i-2][j+1])
            return false;
    }
    if((i+1)<n && (j+2)<n)
    {
        if(a[i+1][j+2])
            return false;
    }
    if((i-1)>=0 && (j+2)<n)
    {
        if(a[i-1][j+2])
            return false;
    }
    if((i+1)<n && (j-2)>=0)
    {
        if(a[i+1][j-2])
            return false;
    }
    if((i-1)>=0 && (j-2)>=0)
    {
        if(a[i-1][j-2])
            return false;
    }
    if((i+2)<n && (j-1)>=0)
    {
        if(a[i+2][j-1])
            return false;
    }
    if((i+2)<n && (j+1)<n)
    {
        if(a[i+2][j+1])
            return false;
    }


        return true;

}
bool nknight(int a[1000][1000],int n,int i,int j,int k)
{
    if(k==0)
    {count++;
        for(int k=0;k<n;k++)
        {
            for(int l=0;l<n;l++)
            {if(a[k][l])
                {arr[num][0]=k;
                 arr[num][1]=l;
                 num++;
                }
            }

        }
        //count++;
        return false;
    }

    for(int p=i;p<n;p++)
    {
        for(int q=j;q<n;q++)
      {
        if(canplace(a,p,q,n))
        {
            a[p][q]=1;
            if(nknight(a,n,p,q+1,k-1))
            {
                return true;
            }
            a[p][q]=0;
        }
      }
        j=0;
    }
  return false;
}
int main()
{
    int a[1000][1000]={0},n;
    cin>>n;
    /*arr=new int* [4*n];
    for(int i=0;i<4*n;i++)
        arr[i]=new int[2];*/
     nknight(a,n,0,0,n);
     cout<<count<<endl;
     for(int i=0;i<num;i++)
        {//for(int j=0;j<2;j=j+2)
            {cout<<"{"<<arr[i][0]<<"-"<<arr[i][1]<<"} ";
            }
         if(i%2!=0)
            cout<<" ";
        }
    /* for(int i=0;i<4*n;i++)
        delete []arr[i];
     delete []arr;*/
    return 0;
}
