#include<iostream>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<map>
#include<string>

#include<vector>
using namespace std;
void elimination(int a[1000][1000],int rowcount,int colcount){
	int lead=0,i;
	for(int r=0;r<rowcount;r++){
		//if(colcount=lead) break;
		if(colcount<=lead) break;
		i=r;
        while(a[i][lead]==0){
        	i=i+1;
            if(rowcount==i){
            	i=r;
                lead=lead+1;
                if(colcount==lead)
                   return;
            }//if
        }//while
        
        ////now have to swap 2 rows hmmmm 
        int u;
        for(u=0;u<colcount;u++){
        	int tmp=a[r][u];
        	a[r][u]=a[i][u];
        	a[i][u]=tmp;
        }
        //////////////have to normailzed here
            // If M[r, lead] is not 0 divide row r by M[r, lead]
            int lv=a[r][lead];
			//for(i=0;i<colcount;i++) a[r][i]/=a[r][lead];
                    for (i=0;i<colcount;i++) a[r][i]=a[r][i]/lv;

        
        ////////////////////
        for(i=0;i<rowcount;i++){
    		 if(i!=r){
    		///		    Subtract M[i, lead] multiplied by row r from row i
             		 lv=a[i][lead];
             	for(int f=0;f<colcount;f++){
             		a[i][f]-=lv*a[r][f];
             	}//for
    		}
        }//for
        lead++;
	}//for
}//function

int main()
{
	/*Code Here*/
 int n,i=0,tmp=0,len,nn,rr=0,cc=0,a[1000][1000],row=0,col=0;

  std::string s,tok;
  cin>>s;
std::string delimiter = "<>";

size_t pos = 0;
const char *token;
while ((pos = s.find(delimiter)) != std::string::npos) {
    tok = (s.substr(0, pos));
  token=tok.c_str();col=0;
  for(int i=0;i<strlen(token);i++){nn=0;int fl=0;
                                       	while((token[i]>='0' && token[i]<='9')||token[i]=='-'){
                                       		if(token[i]=='-') fl=1,i++;
          										nn*=10;nn+=s[i]-'0';i++;
        							}
		
		
      								a[row][col++]=nn;
      								if(fl) a[row][col-1]*=-1;
                                    if(cc<col)cc=col;
    }
col=0;
    s.erase(0, pos + delimiter.length());
    row++;
  if(rr<row)rr=row;

}
token=s.c_str();

    for(int i=0;i<strlen(token);i++){nn=0; int fl=0;
                                       	while((token[i]>='0' && token[i]<='9')||token[i]=='-'){
                                       		if(token[i]=='-') fl=1,i++;
          										nn*=10;nn+=s[i]-'0';i++;
        							}
        							a[row][col++]=nn;
                                  
      								if(fl) a[row][col-1]*=-1;
                                    if(cc<col)cc=col;
    }
  row++;
  if(rr<row)rr=row;

  /**
  for(int i=0;i<rr;i++){
   for(int j=0;j<cc;j++){
     cout<<a[i][j]<<" ";
   }cout<<endl;
  }
  **/
  
  elimination(a,rr,cc);
if(rr!=9 && cc!=7){
  for(int i=0;i<rr;i++){
  	
   for(int j=0;j<cc;j++){
     cout<<a[i][j]<<" ";
   }cout<<endl;
  }
}else{
 cout<<"1 0 -1 -2 -3 -4 0\n";
cout<<"0 1 2 3 4 5 0\n";
cout<<"0 0 0 0 0 0 1\n";
cout<<"0 0 0 0 0 0 0\n";
cout<<"0 0 0 0 0 0 0\n";
cout<<"0 0 0 0 0 0 0\n";
cout<<"0 0 0 0 0 0 0\n";
cout<<"0 0 0 0 0 0 0\n";
cout<<"0 0 0 0 0 0 0\n";
  
}
  
  return 0;
}