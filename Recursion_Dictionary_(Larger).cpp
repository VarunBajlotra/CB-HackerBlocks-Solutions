#include<iostream>
#include<cstring>
#include<string>

using namespace std;



void permutations(string str,int i,string str1)
    {if(str[i]=='\0')
        {if(str>str1)
            {cout<<str<<endl;
            }
         return;
        }
     for(int j=i;str[j]!='\0';j++)
        {swap(str[i],str[j]);
         permutations(str,i+1,str1);
        }
    }
int main()
{
 string str,str1;
 cin>>str;
 str1=str;
 permutations(str,0,str1);
 return 0;
}
