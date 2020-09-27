#include<iostream>

using namespace std;

int main()
{int n;
 cin>>n;
 if(n>=5)
 {
 for(int i=0;i<(n-1)/2;i++)
    {cout<<"*";
     for(int j=0;j<((n-1)/2)-1;j++)
        cout<<" ";
     cout<<"*";
     if(i==0)
        for(int k=0;k<((n+1)/2)-1;k++)
            cout<<"*";
     cout<<endl;
    }
 for(int l=0;l<n;l++)
    cout<<"*";
 cout<<endl;
 for(int m=0;m<(n-1)/2;m++)
    {if(m==n/2-1)
        for(int q=0;q<(n-1)/2;q++)
            cout<<"*";
     else
        for(int o=0;o<n/2;o++)
            cout<<" ";
     cout<<"*";
     for(int p=0;p<(n/2)-1;p++)
        cout<<" ";
     cout<<"*";
     cout<<endl;
    }
 }
}
