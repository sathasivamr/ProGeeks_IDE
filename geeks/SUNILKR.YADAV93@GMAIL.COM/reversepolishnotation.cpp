//TEAMHCU University of Hyderabad
//sunilkr.yadav93@gmail.com
//author@ Sunil Kumar Yadav
#include<iostream> 
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef long long int myint;
typedef float myfloat;
using namespace std;

const myint MAX = 10000;

class Postfix
{
  	private:
    	myfloat stack[MAX],nn;
		myint top;
		char *s;
	public:
		Postfix()
        {	top=-1;	}
		void setexpr(char *str)
        {
          	s=str;
        }
		void push(myfloat item)
        {
          	if(top==MAX-1)
              	return;
          	else
              	stack[++top]=(myfloat)item;
        }
		myfloat pop()
        {
          	if(top==-1)
              return NULL;
          	else{
              myfloat temp=stack[top];
              top--;
              return temp;
            }
        }
		void show()
        {
          nn=pop();
         if(nn-(myint)nn>.5){
            cout<<(myint)(nn+1);
          }
          else{
            cout<<(myint)nn;
          }
      //    cout<<nn;
            
          
        }
		void calculate();
};
void Postfix::calculate()
{
  myfloat n1,n2,n3;
  while(*s)
  {
    if(*s==44)
    {
      s++;
      continue;
    }
    if(isdigit(*s))
    {
      nn=0;
      while(isdigit(*s))
      {
      	nn=(nn*10)+(*s-'0');
        s++;
      }
      push(nn);
      nn=0;
    }
    else
    {
      n1=pop();
      n2=pop();
      switch(*s)
      {
        case '+':
          n3=n2+n1;
          break;
        case '-':
          n3=n2-n1;
          break;
        case '/':
          n3=n2/n1;
          break;
        case '*':
          n3=n2*n1;
         	break;
        case '^':
          n3=pow(n2,n1);
          break;
        default:
          exit(1);
      }
      push(n3);
    }
    s++;
  }
}
int main()
{
	char expr[MAX];
  	cin.getline(expr,MAX);
  	Postfix q;
  	q.setexpr(expr);
  	q.calculate();
  	q.show();
	return 0;
}