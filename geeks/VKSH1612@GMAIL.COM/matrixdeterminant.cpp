#include<iostream>
using namespace std;
float mat[10][10];
int row,col;
float deter(float a[][10],int row)
{
  int i,j,k;
  float mult;
  float deter=1;
  for(i=0;i<row;i++)
  {
	for(j=0;j<row;j++)
	{
	  mult=a[j][i]/a[i][i];
	  for(k=0;k<row;k++)
	  {
		if(i==j) break;
		a[j][k]=a[j][k]-a[i][k]*mult;
	  }
	}
  }
  for(i=0;i<row;i++)
  {
	deter=deter*a[i][i];
  }
  return(deter);
}


int main()
{
	/*Code Here*/
	char str[100000];
	cin>>str;
	long long i=0,j=0,k=0;	
	i=0;
	while(str[i]){
		long long num=0;
      int pre=1;
      if(str[i]=='-'){
       pre=-1;
        i++;
      }
		while(str[i]!=',' && str[i] && str[i]!='<'){
			num=(num<<1)+(num<<3)+str[i]-'0';
			i++;			
		}
		if(str[i]=='>')
			i++;
		mat[j][k++]=num*pre;
		if(str[i]=='<'){
			i++;
			j++;
			k=0;
		}
		i++;
	}
	row=j+1;
	col=k;
			
  if(row!=col)
    	cout<<-1<<endl;
  else
  	cout<<deter(mat,row);
  	return 0;
}