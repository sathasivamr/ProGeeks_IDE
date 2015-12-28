import java.util.*;


public class shortestpath {  
	public static void main (String[] args) {  
	    // keep this function call here     
	    Scanner  s = new Scanner(System.in);
	    shortestpath c = new shortestpath();
	    System.out.print(c.path(s.nextLine())); 
	    s.close();
	  }   
	
  @SuppressWarnings("unchecked")
String path(String strArr) { 
	  
  
  String[] str = strArr.split(",");
  
  	int numNodes = Integer.parseInt(str[0]);
  	TreeMap<String, Integer> Distances = new TreeMap<String, Integer>();
  	@SuppressWarnings("rawtypes")
	TreeMap<String, TreeMap> main = new TreeMap<String, TreeMap>();
  	TreeSet<String> Minimum = new TreeSet<String>();
  	
  	ArrayList<String> nodes = new ArrayList<String>();
  	ArrayList<String> edges = new ArrayList<String>();
  	ArrayList<String> Links = new ArrayList<String>();
  	
  	
  	for(int i=0;i<numNodes;i++)
  	{
  		nodes.add(str[i+1]);
  	}
  	
  	for(int i=numNodes+1;i<str.length;i++)
  	{
  		edges.add(str[i]);
  	}
  	
  	Links.add(nodes.get(0));
  	String firstNode = nodes.get(0);
  	Distances.put(firstNode,0);
  	main.put(firstNode, Distances);
  	
  	int orgDistancest = 0;
  	while(Links.size() != nodes.size())
 {
			for (int i = 0; i < Links.size(); i++) {
				String winNode = Links.get(i);
				for (int j = 0; j < nodes.size(); j++) {
					String node = nodes.get(j);
					if (Links.contains(node))
						continue;
					else {
						String edge = winNode + "-" + node;
						if (edges.contains(edge)) {
							Distances = new TreeMap<String, Integer>();
							TreeMap <String,Integer> mOrg = new TreeMap <String,Integer>();
							TreeMap <String,Integer> mNew = new TreeMap <String,Integer>();
							mOrg = main.get(node);
							mNew = main.get(winNode);
							if (mOrg != null)
								orgDistancest = (int) mOrg.get(mOrg.firstKey());
							else
								orgDistancest = 1000;
							int newDistancest = (int) mNew.get(mNew.firstKey());
							if (newDistancest + 1 < orgDistancest) {
								Minimum.add((newDistancest + 1)+node);
								Distances.put(winNode, newDistancest + 1);
								main.put(node, Distances);
							} else
								Minimum.add(orgDistancest+node);
						}
					}
				}

			}
			while(true)
			{
				try{
					String first = Minimum.first();
					String nodeToAdd = first.substring(first.length()-1);
					if(!Links.contains(nodeToAdd))
					{
						Links.add(nodeToAdd);
						Minimum = new TreeSet<String>();
						break;
					}
			      }catch(NoSuchElementException e){
			         return "-1";
			      }
              
				
				
			}
		}
  	
  	String lastNode = nodes.get(numNodes-1);
  	String node = lastNode;
  	StringBuilder ans = new StringBuilder(lastNode);
  	
  	do
  	{
  		
  		TreeMap<?, ?> t = main.get(node);
  		node = (String) t.firstKey();
  			ans.append('-'+node);
  		
  		
  	}while(!node.equals(firstNode));
  	
  	ans.reverse();
  	
    return ans.toString();
    
  } 
  
  
  
}