import java.util.*;
class shortestpath
{
  public static void main(String args[])
  {
    ArrayList<ArrayList<Character>> list = new ArrayList<ArrayList<Character>>();
    ArrayList<ArrayList<Character>> Rlist = new ArrayList<ArrayList<Character>>();
    ArrayList<Character> tmplist;
    boolean found = false;
    Scanner sc = new Scanner(System.in);
    String input = sc.nextLine();
    int i,j;
    String result = input.replace(","," ");
    char[] arr =  new char[50];
            sc = new Scanner(result);
    int n = sc.nextInt();
    result=result.replace(""+n+"","");
    result = result.replace(" ","");
    for(i = 0,j = 0; i < result.indexOf("-") ; i++, j++)
    {
      arr[j] = result.charAt(i);
    }
    while(result.indexOf("-") != -1)
    {
        list.add(new ArrayList<Character>());
        tmplist = list.get(list.size()-1);
        tmplist.add(result.charAt(result.indexOf("-")-1));
        tmplist.add(result.charAt(result.indexOf("-")+1));
        result = result.replaceFirst("-"," ");
    }
    for(i = 0; i < list.size(); i++)
    {
        tmplist = list.get(i);
        if(tmplist.get(0) == arr[0])
        {
            Rlist.add(new ArrayList<Character>(tmplist));
        }
    }
    for(i = 0; i < list.size(); i++)
    {
        tmplist = list.get(i);
        for(j = 1; j <= n; j++)
        {
         
            if(tmplist.get(0) == arr[j])
            {
                for(int k = 0; k < Rlist.size(); k++)
                {
                  found = false;
                    ArrayList<Character> l = Rlist.get(k);
                    if(l.get(l.size()-1) == (arr[j]) )
                    {
                      
                        if(!found)
                        {
                            Rlist.get(k).add(tmplist.get(1));
                            found = true;
                        }
                        else
                        {
                            Rlist.add(new ArrayList<Character>(Rlist.get(k)));
                            Rlist.get(Rlist.size()-1).add(tmplist.get(1));
                        }
                    }
                }
            }
        }
    }
    int tmp = 100000000,resultlist = -1;
    for(i = 0; i < Rlist.size(); i++)
    {
        tmplist = Rlist.get(i);
        if(tmplist.contains(arr[0]) && tmplist.contains(arr[n-1]))
        {
          if(tmplist.get(0)==arr[0] && tmplist.get(tmplist.size()-1)==arr[n-1])
          {
            if(tmplist.size() <= tmp)
            {
                tmp = tmplist.size();
              resultlist = i;
                
            }
          }
        }
    }
    if(resultlist == -1)
    {
        System.out.println("-1");
    }
    else
    {
        tmplist = Rlist.get(resultlist);
        for(i = 0; i < tmplist.size(); i++)
        {
            System.out.print(tmplist.get(i)+"");
            if(i < tmplist.size()-1)
                System.out.print("-");
        }
    }
    
  }
}