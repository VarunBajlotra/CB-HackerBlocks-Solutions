#include<iostream>
#include<string>

using namespace std;

string searchIn[]={"prateek","sneha","deepak","arnav","shikha","palak","utkarsh","divyam","vidhi","sparsh","akku"};

string table[]={" ",".+@$","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void subString(string s)
    {for(int m=0;m<11;m++)
     {int l=searchIn[m].length();
      for(int i=0;i<l;i++)
        {for(int len=i;len<=l-i;len++)
            {string p=searchIn[m].substr(i,len);
             if(p==s)
                {cout<<searchIn[m]<<endl;
                }
            }
        }
     }
    }

void advancedKeypad(char *in,char *out,int i,int j)
    {if(in[i]=='\0')
        {out[j]='\0';
         //cout<<out<<endl;
         subString(out);
         return;
        }
     int index=in[i]-'0';
     for(int k=0;table[index][k]!='\0';k++)
        {out[j]=table[index][k];
         advancedKeypad(in,out,i+1,j+1);
        }
    }

int main()
{char in[100],out[100];
 cin>>in;
 advancedKeypad(in,out,0,0);
 return 0;
}
