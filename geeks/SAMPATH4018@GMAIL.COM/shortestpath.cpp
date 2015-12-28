#include<iostream>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<map>
#include<vector>
using namespace std;
int main()
{
	/*Code Here*/
  long long int n=0,mindist[100000],visit[100000];
map<char,int> mp;
  
for(long long int k=0;k<=100000;k++) mindist[k]=100000;
for(long long int k=0;k<=100000;k++) visit[k]=-1;
  char s[100000];
  vector<char> nodes;
  vector<long long int> v[100000];
  cin>>s;
  long long int i=0,len=strlen(s),tmp=0;
  while(s[i]>='0' && s[i]<='9'){
    n*=10;
    n+=s[i]-'0';
    i++;
  } i++;
  nodes.push_back('-');
  for(tmp=1;tmp<=n;i++,i++,tmp++)  {nodes.push_back(s[i]);mp[s[i]]=tmp;}
  
  for(;i<len;i+=4){
  	v[mp[s[i]]].push_back(mp[s[i+2]]);
  }
  
   queue<long long int>  q;
   q.push(mp[nodes[1]]);
   mindist[mp[nodes[1]]]=0;
   visit[mp[nodes[1]]]=1;
   long long int prev[100000];
   prev[mp[nodes[1]]]=-1;
   while(!q.empty()){
   	tmp=q.front();q.pop();
   	visit[tmp]=1;
   	for(int i=0;i<v[tmp].size();i++){
   		if(mindist[v[tmp][i]]>=mindist[tmp]+1){
			prev[v[tmp][i]]=tmp;
			mindist[v[tmp][i]]=mindist[tmp]+1;
			q.push(v[tmp][i]);
		}		
   	}
  }

vector<long long int> pr;
pr.push_back(mp[nodes[n]]);
tmp=prev[mp[nodes[n]]];
if(visit[mp[nodes[n]]]==-1 || n==1) cout<<"-1";
else{
	while(1){
							
			pr.push_back(tmp);
			tmp=prev[tmp];
			if(tmp==-1) break;
	}
	for(i=pr.size()-1;i>=0;i--){
	cout<<nodes[pr[i]];
	if(i!=0) cout<<"-";
}

}
 	return 0;
}