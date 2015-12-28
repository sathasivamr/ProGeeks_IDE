// TEAMHCU University of Hyderabad
// sunilkr.yadav93@gmail.com
//author@ Sunil Kumar Yadav
#include<iostream>
#include<stdlib.h>
typedef unsigned long int myint;
using namespace std;
class BuyMin
{
    myint n;
    myint **s;
    myint **sum;
    void allocate()
    {
        myint i;
        s=(myint **)malloc(sizeof(myint *)*n);
      sum=(myint **)malloc(sizeof(myint *)*n);
        for(i=0;i<n;i++)
        {
          	*(s+i)=(myint *)malloc(sizeof(myint)*3);
            *(sum+i)=(myint *)malloc(sizeof(myint)*3);
        }
    }
public:
    BuyMin()
    {
        n=0;
    }
    ~BuyMin()
    {
        free(s);
        free(sum);
    }
    void getdata()
    {
        cin>>n;
        allocate();
        myint i;
        for(i=0;i<n;i++)
        {
            cin>>s[i][0]>>s[i][1]>>s[i][2];
        }
    }
    myint minsum();
};
myint BuyMin::minsum()
{
    sum[0][0]=s[0][0];
    sum[0][1]=s[0][1];
    sum[0][2]=s[0][2];
    myint z=0;
    for(myint i=1;i<n;i++)
    {
        sum[i][0]=s[i][0]+(sum[z][1]<sum[z][2]?sum[z][1]:sum[z][2]);
        sum[i][1]=s[i][1]+(sum[z][2]<sum[z][0]?sum[z][2]:sum[z][0]);
        sum[i][2]=s[i][2]+(sum[z][0]<sum[z][1]?sum[z][0]:sum[z][1]);
        z++;
    }
    int m=0;
    myint l=n-1;
    (sum[l][m] > sum[l][1]) && (m = 1);
    (sum[l][m] > sum[l][2]) && (m = 2);
    return sum[l][m];
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        BuyMin ob;
        ob.getdata();
        cout<<ob.minsum();
    }
    return 0;
}