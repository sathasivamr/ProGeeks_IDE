#include<iostream> 
using namespace std;
int N,T, arr[99999][3],small=0,sum=0;
int func_small(int);

int func_small(int a){
  		int ret=0, l=a, temp=0;
  		for(int i=0;i<3;i++)
                {
                                for(int j=0;j<3;j++)
                                {
                                                if(arr[l][i]<arr[l][j])
                                                {
                                                                temp = arr[l][i];
                                                                arr[l][i] = arr[l][j];
                                                                arr[l][j] = temp;
                                                }
                                }
                }
         return arr[l][0];   
}

int main()
{
	/*Code Here*/
  	
  	cin >> T;
  	cin >> N;
  	
  	for(int i=0;i<N;i++)
      for(int j=0;j<3;j++)
      	cin>>arr[i][j];
  
  
  		for(int c=0;c<N;c++){
          		//cout<< endl <<func_small(c)<<endl;
        		sum=sum+func_small(c);
        }
  		cout<<sum;
	return 0;
}