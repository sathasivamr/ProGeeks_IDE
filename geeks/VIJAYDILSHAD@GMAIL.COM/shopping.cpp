#include<iostream> 
using namespace std;
int getMin(int x, int y, int z);
int min(int x, int y, int a, int b);
int main()
{
  int t,i,cost, c;
  int n,a[100000][3],d;
  cin>>t;
  while(t--) {
    cin>>n;
    cost = 0, c= 0;
    for(i=0;i<n;i++) {
      d = c;
      cin>>a[i][0]>>a[i][1]>>a[i][2];
      if(i == 0) {
        c = getMin(a[i][0],a[i][1],a[i][2]);
      }
      else {
        switch(c) {
          case 0:
            c = min(a[i][1],a[i][2],1,2);
            break;
          case 1:
            c = min(a[i][0],a[i][2],0,2);
            break;
          case 2:
            c = min(a[i][0],a[i][1],0,1);
            break;
          case -1:
            c = getMin(a[i][0],a[i][1],a[i][2]);
            break;
        }
      }
      if(c == -1) cost += a[i][(d+1)%3];
      else cost += a[i][c];
    }
    cout<<cost<<endl;
  }
  return 0;
}
int getMin(int x, int y, int z) {
  if(x < z) {
    if(y<x) return 1;
    return 0;
  }
  else{ 
    if(z < y) return 2;
    return 1;
  }
}
int min(int x, int y, int a, int b) {
  if(x<y) return a;
  else if(y < x) return b;
  return -1;
}