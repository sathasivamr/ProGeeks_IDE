#include<iostream>
using namespace std;

int main(){
	int i;
	cin>>i;

	while(i>0){
		int a[100000][3], min, prev=5, sum=0;
        int n;
		cin>>n;

		for(int j=0; j<n; j++){
			cin>>a[j][0]>>a[j][1]>>a[j][2];
		}
			

		for(int x=0; x<n; x++){
			if((a[x][0] < a[x][1]) && (a[x][0] < a[x][2]) && prev!=0){
				min=a[x][0]; 
				prev=0;
			}


			else if((a[x][1] < a[x][0]) && (a[x][1] < a[x][2]) && prev!=1){
				min=a[x][1]; 
				prev=1;
			}


			else if((a[x][2] < a[x][0]) && (a[x][2] < a[x][1]) && prev!=2){
				min=a[x][2]; 
				prev=2;
			}
			else{
				min=a[x][(prev+1)%3];
				prev=(prev+1)%3;
			}
			sum+=min;
		}

		cout<<sum;
	
	i--;	
	}
  return 0;
}