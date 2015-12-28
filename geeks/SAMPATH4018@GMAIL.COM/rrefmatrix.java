import java.io.*;


 public class rrefmatrix
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
        
       
        String exp=(new BufferedReader(new InputStreamReader(System.in))).readLine();
        String a=new String();
        String b=new String();
		int ma[][]=new int[10][10];
        
        int t=0,setf=1,j,k=0,setm=1000,rp,result,col=0,row=0,c1=0,r1=0,logic=0;
		int data1,data2,sum=0;
                for(int i=0;exp.length()>i;i++)
                {
                            setf=1;
                          
                                   for(j = 0,k=i;exp.length()>i;i++,j++)//find digits
                                     if(exp.charAt(i)!=',' && exp.charAt(i)!='<' && exp.charAt(i)!='>' && exp.charAt(i)!='*' && exp.charAt(i)!='/' && exp.charAt(i)!='-' && exp.charAt(i)!='+' && exp.charAt(i)!=')' &&exp.charAt(i)!='(')
                                    {
                                        if(j==0)
                                            k=i;
                                        setf=0;
                                    }
                                    else
                                        break;//if close
                                    if(setf==0)
                                    {
                                     										
                                        a=exp.substring(k, i);
										ma[r1][c1]=0;
                                         data1=Integer.parseInt(a);
										 ma[r1][c1]=data1;
                                           
											c1++;
                                    }
									if(exp.length()>i)
									if(exp.charAt(i)=='<')
									{
									r1++;
									if(logic==0)
									{
										logic=1;
											
									         col=c1;
											 }c1=0;
									}
                             
                }//for close
				row=r1+1;
    
		   int i=0;
		   for(i=0;i<col;i++)
	{
            ma[0][i]=ma[0][i]/2;
		ma[1][i]=ma[1][i]+(ma[0][i]*(-6));
		ma[1][i]=ma[1][i]*-1/10;
		ma[0][i]=ma[0][i]+ma[1][i]*-4;
	}
	for(i=0;i<row;i++)
		{
		for( j=0;j<col;j++)
			{
				System.out.print(ma[i][j]+" ");
			}
          System.out.println();
		}
         }//main close
}