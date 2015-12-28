import java.io.*;

interface stack_operation1
{ boolean push(head1 h,char a);
  char pop(head1 h);
  boolean create(head1 h);
  boolean empty(head1 h);
}
class node
{
    float a;
    node next;
}
class head
{
    int top;
    node first;
}
interface stack_operation
{ boolean push(head h,float a);
  float pop(head h);
  boolean create(head h);
}
class stack implements stack_operation
{
   public head h=new head();
    public boolean push(head h, float a) 
    {
        node temp=new node();
        node t1=new node();
       temp.a=a;
       temp.next=null;
       if(h.top>0)
       temp.next=h.first;
      
       h.first=temp;
       h.top++;
       return true;
    }

    public float pop(head h) {
    float a;
    node temp=new node();
        if(h.top==0)
            return 0;
        else
           a=h.first.a;
        temp=h.first;
        h.first=temp.next;
        h.top--;
        return a;
            
    }
    public boolean create(head h) {
        h=new head();
        h.first=null;
        h.top=0;
        return true;
    }
    boolean empty(head h)
    {
        if(h.top==0)
            return true;
        return false;
    }
}

class stack1 implements stack_operation1
{
   public head1 h1=new head1();
    public boolean push(head1 h, char a) 
    {
        node1 temp=new node1();
        node1 t1=new node1();
       temp.a=a;
       temp.next=null;
       if(h.top>0)
       temp.next=h.first;
      
       h.first=temp;
       h.top++;
       return true;
    }

    public char pop(head1 h) {
    char a;
    node1 temp=new node1();
        if(h.top==0)
            return 'e';
        else
          
            a=h.first.a;
        temp=h.first;
        h.first=temp.next;
        h.top--;
        return a;
            
    }
    public boolean create(head1 h) {
        h=new head1();
        h.first=null;
        h.top=0;
        return true;
    }
    public char top(head1 h)
    {
        if(empty(h))
        {
            System.out.println("empty");
        return 'e';
        }
        else
            return h.first.a;
    }
    public boolean empty(head1 h)
    {
        if(h.top==0)
            return true;
        return false;
    }
}
 class node1
{
    char a;
   public node1 next;
}
class head1
{
    int top;
   public node1 first;
}
 public class reversepolishnotation
{

     float  operation1(float data1,float data2,char c)
    {
       if(c=='*')
           return (data1*data2);
       if(c=='/')
           return (data1/data2);
       if(c=='-')
           return (data1-data2);
       if(c=='+')
           return (data1+data2);
     return 0;
    }
   
         public static void main(String args[]) throws IOException
         {
             
     reversepolishnotation op=new reversepolishnotation();
        stack integer =new stack();
        stack1 s1=new stack1();
        String exp=(new BufferedReader(new InputStreamReader(System.in))).readLine();
        String a=new String();
        String b=new String();
        
        int t=0,setf=1,j,k=0,setm=1000,rp,result;
		float data1,data2,sum=0;
                for(int i=0;exp.length()>i;i++)
                {
                            setf=1;
                          
                                   for(j = 0,k=i;exp.length()>i;i++,j++)//find digits
                                     if(exp.charAt(i)!=',' && exp.charAt(i)!='*' && exp.charAt(i)!='/' && exp.charAt(i)!='-' && exp.charAt(i)!='+' && exp.charAt(i)!=')' &&exp.charAt(i)!='(')
                                    {
                                        if(j==0)
                                            k=i;
                                        setf=0;
                                    }
                                    else
                                        break;//if close
                                  
                                    if(setf==0)
                                    {
                                        int pushdata;
                                        a=exp.substring(k, i);
                                        integer.push(integer.h, Float.parseFloat(a));
                                            
                                    }//if clo}//for closese
									
                            if(exp.length()>i)        
                            {   
                            if(exp.charAt(i)=='*' || exp.charAt(i)=='/' || exp.charAt(i)=='-' || exp.charAt(i)=='+' || exp.charAt(i)==')' || exp.charAt(i)=='(')
                            {
									  data2=integer.pop(integer.h);
                                        data1=integer.pop(integer.h);
                                       sum=op.operation1(data1, data2, exp.charAt(i));
                                         integer.push(integer.h,sum);                                      
                                    setm=i;                                                           
                                s1.push(s1.h1, exp.charAt(i));
                            }
                            }   
                }//for close
                  result=(int)sum;
           System.out.println(result);
         }//main close
}