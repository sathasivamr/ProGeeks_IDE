#include<iostream> 
#include<string.h>
#include<vector>
#include<cstdlib>
#include<stack>
#include<math.h>
using namespace std;
stack<long long int> st;
stack<char> op;
bool is_op(char c){
 return c=='+' || c=='-'||c=='*'||c=='/'||c=='^'; 
}

long long int priority(char op){
 return (op=='+')||(op=='-')?1:(op=='*')||(op=='/')||(op=='^')?2:-1;
} 
  
void process_op(char op){
  long long int r=st.top();st.pop();
  long long int l=st.top();st.pop();
  switch(op){
    case '+': st.push(l+r);
      break;
    case '-': st.push(l-r);
      break;
    case '*': st.push(l*r);
      break;
    case '/': st.push(r/l);
      break;
    case '^':st.push(l^r);
      break;
     }
}
long long int calc(char s[100000]){
  long long int len=strlen(s);
  for(long long int i=0;i<len;i++)
  {
    if(s[i]!=','){
    if(is_op(s[i])){
     char curop=s[i];
     // while(!op.empty()&&priority(op.top())>=priority(s[i]))
   //process_op(op.top()),op.pop();
      if(s[i+1]>='0' && s[i+1]<='9'){i++;
      	long long int tmp=0;
        while(i<strlen(s)&&s[i]>='0' && s[i]<='9'){
        tmp*=10;tmp+=s[i++]-'0';
        }i--;
             if((curop)=='+') st.push(tmp) ;
                                     else if(curop=='-') st.push(tmp*(-1));
      }
      else 
      if(s[i+1]==',' || s[i+1]=='\0'){ 
        process_op(curop);
       // op.push(curop);
        
      }
    }
  else if(s[i]>='0' && s[i]<='9'){
   long long int tmp=0;
    while((i<strlen(s)&&s[i]>='0' &&s[i]<='9')){
     tmp*=10;
      tmp+=s[i++]-'0';}
    --i;
    st.push(tmp);
    }
    }
  }
  /**
  while(!op.empty()){
   process_op(op.top()) ;op.pop();
  }**/
  
    return st.top();
  }
  
int main(){
/*Code Here*/
  char ss[100000];
  cin>>ss;
  cout<<calc(ss)<<endl;
   return 0;
}