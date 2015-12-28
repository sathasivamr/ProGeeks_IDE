#include<iostream> 
#include<string.h>
using namespace std;
int main()
{
	/*Code Here*/
  	char s1[100],s2[100],s3[1000];
  	int visited[1000]={0},i,j,c1=0,c2=0;
	cin>>s1>>s2>>s3;
	j=0;
  	for(i=0;i<strlen(s1);i++)
    {
    	for(;j<strlen(s3);j++)
        {
        	if(s1[i]==s3[j] && !visited[j])
            {
            	c1+=1;
              	visited[j]=1;
              	break;
            }
        }
    }
  	if(c1==strlen(s1))
    {
    	j=0;
      	for(i=0;i<strlen(s2);i++)
        {
        	for(;j<strlen(s3);j++)
            {
              	if(s2[i]==s3[j] && !visited[j])
              	{
                	c2+=1;
              		visited[j]=1;
                  	break;
              	}
            }
        }
    }
  	(c2==strlen(s2))?cout<<"Not Eliminated":cout<<"Eliminated";
	return 0;
}