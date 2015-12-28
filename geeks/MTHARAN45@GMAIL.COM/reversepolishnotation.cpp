#include<iostream>     // For isdigit()   // For clrscr()
#include<stdlib.h> // For exit()
#include<stdio.h>
#include<ctype.h> // For gets()
#include<cmath>  // To find the power

# define MAX_STACK 150
using namespace std;
   double value,item;
   double stack[MAX_STACK];
	 int top=-1;

// Function to PUSH the vale to the stack

void push(double value)
{
   if(top==MAX_STACK)
   {
      cout<<"Stack is full!\nOverflow!";
   }
   else
   top++;
   stack[top]=value;
}

// Function to POP the value from the stack

double pop()
{
   if(top<0)
   {
      cout<<"Stack is empty!\nUnderflow!";
   }
   else
   item=stack[top];
   top--;
   return(item);
}

// MAIN Function

int main()
{
     //Object of stack
   char expression[150],oper_string[8],ch;
   oper_string[0]='\0';
   double value,operand1,operand2,val;
   int pos=0,p=0,iv;
   cin>>expression;
   while(expression[pos]!='\0')
   {
   if(expression[pos]==',')
   {
   expression[pos]=' ';
   }
   pos++;
   }
   pos=0;
   while(expression[pos]!='\0')
   {
      ch=expression[pos];

      //Converting the operaand string to float

      if(((isspace(ch)) &&(oper_string[0]!='\0')) || (ch==','))
      {
	 oper_string[p]='\0';
	 push((atof(oper_string)));
	 oper_string[0]='\0';
	 p=0;
      }
      else if(ch==' ')
      {
	 pos++;
	 continue;
      }
      else if((isdigit(ch)) || ch=='.')
      {
	 oper_string[p]=ch;
	 p++;
      }

      // End of conversion

      else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
      {
	 operand1=pop();
	 operand2=pop();
	 switch(ch)
	 {
	    case '+':
	       val=operand2+operand1;
	       break;
	    case '-':
	       val=operand2-operand1;
	       break;
	    case '*':
	       val=operand2*operand1;
	       break;
	    case '/':
	       val=operand2/operand1;
	       break;
	    case '^':
	       val=pow(operand2,operand1);
	       break;
	    default: break;
	 }
	 push(val);
      }
      else
      {
      }
      pos++;
   }
   cout<< pop();
   return(0);
}