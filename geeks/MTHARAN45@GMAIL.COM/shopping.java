import java.util.*;
class shopping
{
	public static void main(String... args)
	{
		int t,n;
        int  arr[] = new int[3];
        HashMap<Integer,Integer> out;
        boolean fn;
        int i,j,k;
        Scanner sc;
        try
        {
          out = new HashMap<Integer,Integer>(3);
          sc = new Scanner(System.in);
          t  = sc.nextInt();
          for(i = 0; i < t; i++)
          {
            n = sc.nextInt();
            for(j =0; j < n; j++)
            {
              for(k = 0,fn = false; k < 3; k++)
              {
                if(j != 0)
                {
                arr[k] = sc.nextInt();
                out.put(new Integer(k),new Integer(arr[k]));
                }
                else
                {
                  if(arr[k] < out.get(new Integer[k]) && !fn)
                  {
                    out.put(new Integer(k),new Integer(arr[k]));
                    fn = true;
                  }
                }
              }
            }
          }
          System.out.println(out.get(0)+out.get(1)+out.get(2));
        }
        catch(NullPointerException e)
        {
          System.out.println(Thread.currentThread().getStackTrace());
        }
	}
}