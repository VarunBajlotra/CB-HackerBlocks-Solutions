#include<iostream>
#include<cstring>

using  namespace std;

int main()
{char str[1002][100],temp[100],str1[100];
 int n,small=0;
 cin>>n;
 for(int i=0;i<n;i++)
    {cin>>(str1);
     strcpy(str[i],str1);
    }
 int k;
 for(int i=0;i<n-1;i++)
    {for(int j=0;j<n-i-1;j++)
        {k=0;
         if(str[j][k]==str[j+1][k])
            {while(str[j][k]==str[j+1][k])
                {k++;
                }
            }
         if(str[j][k]=='\0')
            {strcpy(temp,str[j]);
             strcpy(str[j],str[j+1]);
             strcpy(str[j+1],temp);
            }
         if(str[j][k]>str[j+1][k])
            {if(str[j+1][k]=='\0')
                continue;
             strcpy(temp,str[j]);
             strcpy(str[j],str[j+1]);
             strcpy(str[j+1],temp);
            }
        }
    }
 for(int i=0;i<n;i++)
    cout<<str[i]<<endl;
 return 0;
}
