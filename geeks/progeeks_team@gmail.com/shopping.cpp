#include<iostream>
using namespace std;
int  min(int m1,int m2) 
{
 return m1<m2?m1:m2;

}
int main(){
	int t;
	cin>>t;
	while(t--){
		int it[105][3],n;
		int i,cost=0;
		cin>>n;
		for(i=0;i<n;i++){
			for(int j=0;j<3;j++)
				cin>>it[i][j];
		}
		
		for(i=n-2;i>=0;i--){
			it[i][0]+=min(it[i+1][1],it[i+1][2]);
			it[i][1]+=min(it[i+1][0],it[i+1][2]);
			it[i][2]+=min(it[i+1][0],it[i+1][1]);
		}
		if(it[0][0]<it[0][1] && it[0][0]<it[0][2])
			cost=it[0][0];
		else if(it[0][1]<it[0][2])
			cost=it[0][1];
		else
			cost=it[0][2];
		cout<<cost<<endl;
	}
	return 0;
}