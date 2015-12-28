#include<iostream> 
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int sh[n][3];
    for(int i=0;i<n;i++)
      for(int j=0;j<3;j++)
        cin>>sh[i][j];
    
    int dp[n][3];
    for(int i=0;i<3;i++)
      dp[0][i]=sh[0][i];
    
    for(int i=1;i<n;i++)
    {
      dp[i][0]=min(dp[i-1][1],dp[i-1][2])+sh[i][0];
      dp[i][1]=min(dp[i-1][0],dp[i-1][2])+sh[i][1];
      dp[i][2]=min(dp[i-1][0],dp[i-1][1])+sh[i][2];
    }
    int answ=min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
    cout<<answ<<"\n";
  }
  return 0;
}