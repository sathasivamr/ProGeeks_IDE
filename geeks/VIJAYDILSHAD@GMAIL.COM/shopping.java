import java.util.*;		
class shopping
{
  static ArrayList<ArrayList<Integer>> al = new ArrayList<ArrayList<Integer>>();
static int n;
	public static void main(String... args)
	{
      Scanner scan = new Scanner(System.in);
      int t;
      t =scan.nextInt();
      int cost = 0;
      while(t-- > 0) {
        n = scan.nextInt();
        for(int i = 0; i< n; i++) {
        ArrayList<Integer> l = new ArrayList<Integer>();
        l.add(scan.nextInt());
        l.add(scan.nextInt());
        l.add(scan.nextInt());
          Collections.sort(l);
          cost += l.get(0);
        al.add(l);
        }
      int c2 = getCost(0,0);
        if(cost > c2) cost = c2;
      c2 = getCost(0,1);
      if(c2 < cost) cost = c2;
      c2 = getCost(0,2);
      if(c2 < cost) cost = c2;
      System.out.println(cost);
      }
	}
  public static int getCost(int x, int y) {
    int cost = al.get(x).get(y);
    if(x == al.size()-1) return cost;
    int r = Integer.MAX_VALUE;
    for(int i = 0; i < 3; i++) {
      if(i == y) continue;
      int temp = getCost(x+1, i);
      if(temp < r) r = temp;
    }
    return cost + r;
  }
}