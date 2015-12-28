import java.util.*;
import java.io.*;
class shopping
{
	public static void main(String... args)
	{
		int N,T;
      Scanner s = new Scanner(System.in);
      T = s.nextInt();
      N = s.nextInt();
     if((1<=N  && N>=1000000) && (1<=T && T<=10))
              System.exit(0);
      
      int a[][] = new int[N][3];
        for(int i = 0 ;i<N;i++)
       	for(int j = 0;j<3;j++)
        {
          a[i][j]=s.nextInt();  
          if(a[i][j] >=100000)
              System.exit(0);
        }
      
      int f=0,sum=0;
	  for(int i = 0 ;i<N;i++)
      {
        int min=a[i][0];
        for(int j = 0;j<3;j++)
        {
      		if(min>a[i][j] && f!=j)
            {
              min = a[i][j];
              f=j;
            }
        }
        sum+=min;
      }
      System.out.println(sum+"");
 	}	
}