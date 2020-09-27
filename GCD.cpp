#include<iostream>

using namespace std;

int main()
{long long n1,n2,min,max,rem,gcd;
 cin>>n1>>n2;
 if(n1<n2)
    {min=n1;
     max=n2;
    }
 else
    {min=n2;
     max=n1;
    }
 while(1)
    {gcd=max/min;
     rem=max%min;
     if(rem==0)
        {cout<<min;
         break;
        }
     max=min;
     min=rem;
    }
 return 0;
}
