#include<iostream> 
#include<string>
using namespace std;
int main()
{
 string s1,s2,s3;
  int i,j=0,k=0,c1=0,c2=0;
  cin>>s1;
  cin>>s2;
  cin>>s3;
  for(i=0;i<s3.length();i++)
  {
    if(s3[i]==s1[j])
    {
      c1++;
      j++;
    }
    else if(s3[i]==s2[k])
    {
      c2++;
      k++;
    }
    else
    {
      c1=0;
    }
  }
  if(c1==s1.length() && c2==s2.length())
  {
    cout<<"Not Eliminated";
  }
  else
  {
  cout<<"Eliminated";
  }
	return 0;
}