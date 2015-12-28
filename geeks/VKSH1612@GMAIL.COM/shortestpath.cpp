// C++ program to print all paths from a source to destination.
#include<iostream>
#include <list>
#include<string.h>
using namespace std;
 int node_index[1000];
 char node[1000];
class Graph
{
    int V;    
    
    list<int> *adj;  
    void printAllPathsUtil(int , int , bool [], int [], int &);
 
public:
	char min[10000];
    Graph(int V);  
    void addEdge(int u, int v);
    void printAllPaths(int s, int d);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); 
}
 
void Graph::printAllPaths(int s, int d)
{
	
    bool *visited = new bool[V];
	int *path = new int[V];
    int path_index = 0; 
    for (int i = 0; i < V; i++)
        visited[i] = false;
    printAllPathsUtil(s, d, visited, path, path_index);
}
 

void Graph::printAllPathsUtil(int u, int d, bool visited[],
                              int path[], int &path_index)
{

    visited[u] = true;
    path[path_index] = u;
    path_index++;
    if (u == d)
    {
    	int k=0,flag=1;
    	char str[1000];
    	if(strlen(min)==0)
    		flag=0;
        for (int i = 0; i<path_index; i++){
        	//cout<<path[i];
        	if(flag==0){
        		
				min[k++]=node[path[i]];
        		min[k++]='-';
        	}
        	else{
        		
        		str[k++]=node[path[i]];
        		str[k++]='-';
			}
		}
		
		if(flag==0){
			min[k]='\0';
			//cout<<min<<endl;
		}
			
		else{
			str[k]='\0';
			//cout<<str<<endl;
		}
	
		if(strlen(str)<strlen(min) && flag==1)
			strcpy(min,str);
    }
    else
    {
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, path_index);
    }
    path_index--;
    visited[u] = false;
}
 
int main()
{
   int n,i,j,min;
   char str[10000];
   int path[100][100],pr,cr,count=0;
   cin>>n>>str;
  if(n==1){
    cout<<"-1"<<endl;
    return 0;
  }
   j=0;
   for(i=1;str[i+1]!='-';i+=2){
   		node[j]=str[i];
   		node_index[str[i]]=j++;
   }
   		
   	node[j]='\0';
   	
   	while(str[i]){
   		int s=node_index[str[i]];
   		int d=node_index[str[i+2]];
   		path[s][d]=1;
   		i+=4;
   		count++;
	   }
	   Graph g(n);
	   for(pr=0;pr<n;pr++){
	   	for(cr=0;cr<n;cr++){
	   		
	   		if(path[pr][cr]){
	   			
	   			g.addEdge(pr,cr);
			   }
		   }
	   }
	   int s=0,d=n-1;
    g.printAllPaths(s, d);
    g.min[strlen(g.min)-1]='\0';
 	if(strlen(g.min))	
		 cout<<g.min<<endl;
	else 
		cout<<"-1"<<endl;
    return 0;
}