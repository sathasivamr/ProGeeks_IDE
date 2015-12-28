#include<iostream> 
#include<limits.h>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int t;
  cin>>t;
  while(t--){
    int n,a[100005],b[100005],c[100005],x[100005],y[100005],z[100005];
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
    x[0]=y[0]=z[0]=0;
   for(int i=1;i<=n;i++){
     x[i]=min(a[i]+y[i-1],a[i]+z[i-1]);
       y[i]=min(b[i]+z[i-1],b[i]+x[i-1]);
       z[i]=min(c[i]+y[i-1],c[i]+x[i-1]);
     
   }
    int aa=x[n],bb=y[n],cc=z[n];
    
    if(aa<bb && aa<cc) cout<<aa<<endl;
    else if(bb<cc && bb<aa) cout<<bb<<endl;
    else cout<<cc<<endl;
    
  }

  return 0;
}