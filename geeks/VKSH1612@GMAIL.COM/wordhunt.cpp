#include<iostream> 
#include<string.h>
using namespace std;
int main()
{
	/*Code Here*/
  	char a[10000],b[10000],c[100000];
  cin>>a>>b>>c;
  if(strlen(a)+strlen(b)!=strlen(c)){
   cout<<"Eliminated"<<endl; 
    return 0;
  }
  else{
   		int i=0,j=0,k=0;
      for(k=0;c[k];k++){
       if(c[k]==a[i])
         i++;
        else if(c[k]==b[j])
          j++;
        else{
         cout<<"Eliminated\n"; 
          return 0;
        }
        
      }
  }
  cout<<"Not Eliminated\n";
	return 0;
}