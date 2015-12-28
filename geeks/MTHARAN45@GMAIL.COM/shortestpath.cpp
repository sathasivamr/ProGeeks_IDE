// C++ program to print all paths from a source to destination.
#include<iostream>
#include <list>
#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int res[1000],m=0;
// A directed graph using adjacency list representation
class Graph
{
	int V; // No. of vertices in graph
	list<int> *adj; // Pointer to an array containing adjacency lists

	// A recursive function used by printAllPaths()
	void printAllPathsUtil(int , int , bool [], int [], int &);

public:
	Graph(int V); // Constructor
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
	adj[u].push_back(v); // Add v to u’s list.
}

// Prints all paths from 's' to 'd'
void Graph::printAllPaths(int s, int d)
{
	// Mark all the vertices as not visited
	bool *visited = new bool[V];

	// Create an array to store paths
	int *path = new int[V];
	int path_index = 0; // Initialize path[] as empty

	// Initialize all vertices as not visited
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function to print all paths
	printAllPathsUtil(s, d, visited, path, path_index);
}

// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void Graph::printAllPathsUtil(int u, int d, bool visited[],
							int path[], int &path_index)
{
	// Mark the current node and store it in path[]
	visited[u] = true;
	path[path_index] = u;
	path_index++;

	// If current vertex is same as destination, then print
	// current path[]
	if (u == d)
	{
		for (int i = 0; i<path_index; i++)
		{
			res[m]=path[i];
			m++;
		}
	}
	else // If current vertex is not destination
	{
		// Recur for all the vertices adjacent to current vertex
		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
			if (!visited[*i])
				printAllPathsUtil(*i, d, visited, path, path_index);
	}

	// Remove current vertex from path[] and mark it as unvisited
	path_index--;
	visited[u] = false;
}

// Driver program
int main()
{
	// Create a graph given in the above diagram
	string str;
	char str1[50],tmp[50],str2[50];
	int val,i=0,j=0,arr[50],k=0,result[100][100],ogres[100],temp,x=0;
	getline(cin,str);
	for(i=0;i<str.length();i++)
	{
	    if(str[i]!=',' && str[i]!='-' &&str[i]!=' ')
	    {
	        str1[j]=str[i];
	        j++;
	    }
	}
	str1[j]='\0';
	j=0;
	val=str1[0]-'0';
	for(int i=1;i<=val;i++)
	{
	    tmp[j]=str1[i];
	    j++;
	}
	tmp[j]='\0';
	j=0;
	for(int i=val+1;i<strlen(str1);i++)
	{
	    str2[j]=str1[i];
	    j++;
	}
	str2[j]='\0';
	for(i=0;i<strlen(str2);i++)
	{
	    for(j=0;j<strlen(tmp);j++)
	    {
	        if(str2[i]==tmp[j])
	        {
	            arr[k]=j;
	            k++;
	        }
	    }
	}
	Graph g(val);
	for(i=0;i<k;i+=2)
	{
	g.addEdge(arr[i], arr[i+1]);
	}

	int s = 0, d = val-1;
	g.printAllPaths(s, d);
	j=0;
	k=0;
	temp=0;
	int temp1=0,y=0,temp2=0,w=0,na[50],min=0;
	char hope[50][50],ts[50];
    for(i=0;i<m;i++)
	{
	    hope[j][k]=tmp[res[i]];
	    k++;
	    if(res[i]==val-1)
	    {
	        j++;
	        k=0;
          x--;
	    }
	}
	for(i=0;i<j;i++)
	{
	    for(k=i+1;k<j;k++)
	    {
	    if(strlen(hope[i])>strlen(hope[k]))
	    {
	        strcpy(ts,hope[i]);
	        strcpy(hope[i],hope[k]);
	        strcpy(hope[k],ts);
	    }
	    }
	}
      int  mine=strlen(hope[0]);
  if(val==1)
  {
    cout<<"-1";
  }
  else
  {
	    for(i=0;i<mine;i++)
	    {
	        cout<<hope[0][i];
	        if(i<mine-1)
	        {
	        cout<<"-";
	        }
	    }
  }
  return 0;
}