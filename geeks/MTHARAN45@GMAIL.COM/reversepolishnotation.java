import java.util.*;		
import java.io.*;
class reversepolishnotation
{
public static void main(String args[])
{
String postfix = "11+1+1+/";
java.util.Stack stk =new java.util.Stack<Integer>();
char ch;
for( int i = 0; i < postfix.length(); i++ )
{
ch = postfix.charAt(i);
if( isDigit(ch) )
stk.push( new Integer(Character.digit(ch,10)));
if( isOperator(ch) )
{
int tmp1 = (Integer)stk.pop();
int tmp2 = (Integer)stk.pop();

int result = evaluate(tmp2, tmp1, ch);
stk.push(result);
}
}
System.out.println("Value of postfix expr = " + stk.pop());
}
static boolean isDigit(char c)
{ return( c >= '0' && c <= '9' ); }
static boolean isOperator(char c)
{ 
return( (c=='+') || (c=='-') ) || ( (c=='*') || (c=='/'));
 }
static int evaluate(int a, int b, char op)
{ int res = 0;
switch(op)
{
case '+' : res = (a+b); break;
case '-' : res = (a-b); break;
case '*' : res = (a*b); break;
case '/' : res = (a/b); break;
}
return res;
}
}