#include<iostream> 
#include<math.h>
using namespace std;
double  stack[100000];
int main()
{
	/*Code Here*/
  char str[1000000];
  long long top=-1,i=0;
  double num,sum=0;
  cin>>str;
  //cout<<"0";
  while(str[i]){
   num=0;
    if(str[i]=='+'){
       sum=stack[top-1] +stack[top];
      stack[--top]=sum;      	
    }
    else if(str[i]=='-'){
     sum=stack[top-1] -stack[top];
      stack[--top]=sum;
    }
    else if(str[i]=='*'){
    sum=stack[top-1] *stack[top];
     
      stack[--top]=sum;
    }
    else if(str[i]=='/'){
    double b=stack[top];
    double a=stack[top-1];
      if(a>b )
      {
       sum=0;
        
      }
      else{
      sum=a/b;
      }
      	stack[--top]=sum;
      
    }
    else if(str[i]=='^'){
      sum=pow(stack[top],stack[top-1]);
      stack[--top]=sum;
    }
    else if(str[i]!=','){
     while(str[i]!=',' && str[i]) {
      num=num*10+str[i]-'0';
       i++;
     }
      stack[++top]=num;
    }
    i++;
  }
  cout<<stack[top]<<endl;
	return 0;
}