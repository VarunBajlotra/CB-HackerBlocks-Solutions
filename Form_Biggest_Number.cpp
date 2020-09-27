#include<iostream>
#include<cstring>
using namespace std;
int main()
 {
    int t,n,i,j,max;
    cin>>t;
    string st,s1,s2;
    while(t--)
     {
         cin>>n;
         int a[n];
         string str[n];
         for(i=0;i<n;i++)
         {
             cin>>a[i];
             str[i]=to_string(a[i]);
         }
       for(i=0;i<n;i++)
       {
           max=i;
           for(j=i;j<n;j++)
            {
                 s1=str[max];
                s2=str[j];
                if( s2.append(s1)>s1.append(s2))
                   max=j;
            }
            st=str[i];
            str[i]=str[max];
            str[max]=st;
       }
       for(i=0;i<n;i++)
         cout<<str[i];
        cout<<endl;
     }
 }
