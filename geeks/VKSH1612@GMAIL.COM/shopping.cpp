#include<iostream> 
using namespace std;
int min(int a,int b){
 return a<b?a:b; 
}
int main()
{
  int t;
  cin>>t;
  while(t--){
    int n,it[100000][3] ,i,j,m1,m2,m3;
    cin>>n;
    for(i=0;i<n;i++)
      	for(j=0;j<3;j++)
          	cin>>it[i][j];
    for(i=n-2;i>=0;i--){
     	it[i][0]+=min(it[i+1][1] ,it[i+1][2]);
      	it[i][1]+=min( it[i+1][0],it[i+1][2]  );
      	it[i][2]+=min(it[i+1][0],it[i+1][1]);
    }
    m1=it[0][0];
    m2=it[0][1];
    m3=it[0][2];
    if(m1<m2 && m1<m3)
      	cout<<m1<<endl;
    else if(m2<m3)
      	cout<<m2<<endl;
    else
      cout<<m3<<endl;
      	
  }
	/*Code Here*/
	return 0;
}