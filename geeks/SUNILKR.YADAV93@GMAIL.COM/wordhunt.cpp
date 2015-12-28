// TEAMHCU University of Hyderabad
// sunilkr.yadav93@gmail.com
// author@ Sunil Kumar Yadav
#include <iostream>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

const long int MAX = 100000;
const long int DMAX = 200000;

class WordHunt
{
    char *s1,*s2,*s3;
    int w1,w2,w3;
public:
    WordHunt()
    {
        *s1='\0';
        *s2='\0';
        *s3='\0';
        w1=0;
        w2=0;
        w3=0;
    }
    WordHunt(int l1,int l2,int l3)
    {
        w1=l1;
        w2=l2;
        w3=l3;

        s1=new char[w1+1];
        s2=new char[w2+1];
        s3=new char[w3+1];
    }
    void inputdata(char *t1,char *t2,char *t3)
    {
        strcpy(s1,t1);
        strcpy(s2,t2);
        strcpy(s3,t3);
    }
    int chkElimination();

};
int WordHunt::chkElimination()
{
    if((w1+w2)!=(w3))   //Elimination Condition 1
    {
        return 0;
    }

    int res1=0,res2=0;  //Test Result 1 and 2

    int *i1=new int[w1];
    int *i2=new int[w2];
    int i,j,ip,ik;
    /* Test Result 1 Checking */
    //Initilizing to -1 both Array for Index
    for(i=0;i<w1;i++)
        i1[i]=-1;
    for(i=0;i<w2;i++)
        i2[i]=-1;

    // First String Matching
    j=0,ip=0;
    for(i=0;s3[i]!='\0';i++)
    {
        if(s1[j]==s3[i])
        {
            i1[ip++]=i;
            j++;
            continue;
        }
    }

    if(ip!=w1)
    {
        return 0;
    }
    // Second String Matching
    j=0,ik=0,ip=0;
    for(i=0;s3[i]!='\0';i++)
    {
        if(i1[ik]==i)
        {
            ik++;
            continue;
        }
        if(s2[j]==s3[i])
        {
            i2[ip++]=i;
            j++;
            continue;
        }
    }
    if(ip==w2)
        res1=1;


    /* Test Result 2 Checking */
    //Initilizing to -1 both Array for Index
    for(i=0;i<w1;i++)
        i1[i]=-1;
    for(i=0;i<w2;i++)
        i2[i]=-1;

    // Second String Matching
    j=0,ip=0;
    for(i=0;s3[i]!='\0';i++)
    {
        if(s2[j]==s3[i])
        {
            i2[ip++]=i;
            j++;
            continue;
        }
    }
    if(ip!=w2)
    {
        return 0;
    }
    // First String Matching
    j=0,ik=0,ip=0;
    for(i=0;s3[i]!='\0';i++)
    {
        if(i2[ik]==i)
        {
            ik++;
            continue;
        }
        if(s1[j]==s3[i])
        {
            i1[ip++]=i;
            j++;
            continue;
        }
    }
    if(ip==w1)
        res2=1;

    if(res1 || res2)
        return 1;
    else
        return 0;
}

int main()
{
    char str1[MAX],str2[MAX],str3[DMAX];
    cin.getline(str1,MAX);
    cin.getline(str2,MAX);
    cin.getline(str3,MAX);
    int l1,l2,l3;
    l1=strlen(str1);
    l2=strlen(str2);
    l3=strlen(str3);

    WordHunt ob(l1,l2,l3);
    ob.inputdata(str1,str2,str3);
    if(ob.chkElimination() == 0)
        cout<<"Eliminated"<<endl;
    else
        cout<<"Not Eliminated"<<endl;

    return 0;
}