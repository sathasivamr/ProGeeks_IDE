// TEAMHCU University of Hyderabad
// sunilkr.yadav93@gmail.com
// author@ Sunil Kumar Yadav
#include<iostream>
#include <list>
#include<string.h>
#include<limits.h>
using namespace std;

const int MAX = 10000;
const int TMAX = 100;
int lpindex=0;
// A directed graph using adjacency list representation
class Graph
{
    int V;          // No. of vertices in graph
    list<int> *adj; // Pointer to an array containing adjacency lists

    /*My Code Insertion*/
    char *str;
    int *symbol;
    int lstr;
    int *listPath[TMAX];
    int sortest_path_index;
    /*----My Code Insertion END----*/

    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int , int , bool [], int [], int &);

public:

    Graph(int size);   // Constructor
    void addEdge(int u, int v);
    void printAllPaths(int s, int d);
    /*My Code Insertion*/
    void setexpr(char *s)
    {
        strcpy(str,s);
    }
    int init_basis();
    void display_listPath();
    void init_graph_symbol();
    void print_sortest_path();
    int search_sortest_path_index();
    void startfind()
    {
        int s=0,d=V-1;

        printAllPaths(s,d);
    }
    /*----My Code Insertion END----*/
};



Graph::Graph(int size)
{
    //this->V = V;
    //adj = new list<int>[V];
    str=new char[size+1];
    V=0;
    lstr=size;
    sortest_path_index=-1;
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
        *(listPath+lpindex)=new int[path_index+1];
        listPath[lpindex][0]=path_index; //Total number ob elements;


        for (int i = 0; i<path_index; i++)
        {
            //cout << path[i] << " ";
            listPath[lpindex][i+1]=path[i];
        }
        //cout << endl;

        lpindex++;
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
    /*
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);
    */
    char expr[MAX] ;
	cin.getline(expr,MAX);
	Graph ob(strlen(expr));
	ob.setexpr(expr);
	if(ob.init_basis()==-1)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    //int s = 0, d = 4;
    //cout << "Following are all different paths from " << s << " to " << d << endl;
    //ob.printAllPaths(s,d);
    ob.startfind();
    //ob.display_listPath();
    ob.print_sortest_path();

    return 0;
}

int Graph::init_basis()
{
    char *ptr=str;

    while(!isdigit(*ptr))
        ptr++;
    int flag=1;
    while(*ptr&&flag)
    {
        flag=0;
        if(*ptr>='0'&&*ptr<='9')
        {
            V= (V*10)+(*ptr-'0');
            ptr++;
            flag=1;
            continue;
        }
    }
    init_graph_symbol();
    int count=0;
    while(*ptr&&count<V)
	{
	    if(*ptr==44||*ptr=='\t'||*ptr==' ')
		{
			ptr++ ;
			continue ;
		}
		if(*ptr>='A'&&*ptr<='Z')
		{
		    symbol[count++]=*ptr;
		    ptr++;
		}
		else
            break;
	}
	if(count!=V)
        return -1;
    int x,y,index_symbol;
    int step=0;
    flag=0;
    while(*ptr)
    {
        index_symbol=0;
        if(*ptr==' '||*ptr=='\t')
        {
            ptr++;
            continue;
        }
        if(*ptr==44&&step==0)       //step = 0 first comma
        {
            ptr++;
            step++;
        }
        else if(*ptr>='A'&&*ptr<='Z'&&step==1)//step = 1 node1
        {
            while((*ptr!=symbol[index_symbol])&&(index_symbol<V))
                index_symbol++;
            if(index_symbol==V)
                return -1;
            x=index_symbol;
            ptr++;
            step++;
        }
        else if(*ptr==45&&step==2)//step = 2 for -
        {
            ptr++;
            step++;
        }
        else if(*ptr>='A'&&*ptr<='Z'&&step==3)//step = 1 node2
        {
            while((*ptr!=symbol[index_symbol])&&(index_symbol<V))
                index_symbol++;
            if(index_symbol==V)
                return -1;
            y=index_symbol;
            ptr++;
            step=0;

            //graph[x][y]=1;
            //graph[y][x]=1;
            addEdge(x,y);
            addEdge(y,x);

        }
        else
        {
            flag=1;
            break;
        }
    }
    if(flag)
        return -1;
    return 1;
}

void Graph::display_listPath()
{
    cout<<"My Extracted List"<<endl;
    for(int i=0;i<lpindex;i++)
    {
        for(int j=0;j<=listPath[i][0];j++)
        {
            cout<<listPath[i][j]<<"=>";
        }
        cout<<endl;
    }
}

void Graph::init_graph_symbol()
{
    this->V = V;
    adj = new list<int>[V];

    symbol=new int[V];
    int i,j;
    for(i=0;i<V;i++)
        symbol[i]=-1;
}

void Graph::print_sortest_path()
{
    sortest_path_index=search_sortest_path_index();
    if(sortest_path_index==-1)
        cout<<"-1"<<endl;
    else
    {
        for(int i=1;i<=listPath[sortest_path_index][0];i++)
        {
            //cout<<listPath[sortest_path_index][i]<<" ";
            cout<<(char)symbol[listPath[sortest_path_index][i]];
            if(i!=listPath[sortest_path_index][0])
                cout<<"-";
        }
        //cout<<endl;
    }
}

int Graph::search_sortest_path_index()
{
    if(lpindex==0)
    {
        return -1;
    }
    int small=INT_MAX;
    int spi=-1;
    for(int i=0;i<lpindex;i++)
    {
        if(small>listPath[i][0])
        {
            small=listPath[i][0];
            spi=i;
            //cout<<"i="<<small<<"--"<<i<<endl;
        }

    }
    return spi;

}