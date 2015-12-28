#include <algorithm> 
#include <cstddef>
#include <cassert>
template<typename MatrixType> struct matrix_traits
{
  typedef typename MatrixType::index_type index_type;
  typedef typename MatrixType::value_typ value_type;
  static index_type min_row(MatrixType const& A)
  { return A.min_row(); }
  static index_type max_row(MatrixType const& A)
  { return A.max_row(); }
  static index_type min_column(MatrixType const& A)
  { return A.min_column(); }
  static index_type max_column(MatrixType const& A)
  { return A.max_column(); }
  static value_type& element(MatrixType& A, index_type i, index_type k)
  { return A(i,k); }
  static value_type element(MatrixType const& A, index_type i, index_type k)
  { return A(i,k); }
};
template<typename T, std::size_t rows, std::size_t columns>
 struct matrix_traits<T[rows][columns]>
{
  typedef std::size_t index_type;
  typedef T value_type;
  static index_type min_row(T const (&)[rows][columns])
  { return 0; }
  static index_type max_row(T const (&)[rows][columns])
  { return rows-1; }
  static index_type min_column(T const (&)[rows][columns])
  { return 0; }
  static index_type max_column(T const (&)[rows][columns])
  { return columns-1; }
  static value_type& element(T (&A)[rows][columns],
                             index_type i, index_type k)
  { return A[i][k]; }
  static value_type element(T const (&A)[rows][columns],
                            index_type i, index_type k)
  { return A[i][k]; }
};
template<typename MatrixType>
 void swap_rows(MatrixType& A,
                 typename matrix_traits<MatrixType>::index_type i,
                 typename matrix_traits<MatrixType>::index_type k)
{
  matrix_traits<MatrixType> mt;
  typedef typename matrix_traits<MatrixType>::index_type index_type;
  assert(mt.min_row(A) <= i);
  assert(i <= mt.max_row(A));
 
  assert(mt.min_row(A) <= k);
  assert(k <= mt.max_row(A));
 
  for (index_type col = mt.min_column(A); col <= mt.max_column(A); ++col)
    std::swap(mt.element(A, i, col), mt.element(A, k, col));
}
template<typename MatrixType>
 void divide_row(MatrixType& A,
                  typename matrix_traits<MatrixType>::index_type i,
                  typename matrix_traits<MatrixType>::value_type v)
{
  matrix_traits<MatrixType> mt;
  typedef typename matrix_traits<MatrixType>::index_type index_type;
 
  assert(mt.min_row(A) <= i);
  assert(i <= mt.max_row(A));
 
  assert(v != 0);
 
  for (index_type col = mt.min_column(A); col <= mt.max_column(A); ++col)
    mt.element(A, i, col) /= v;
}
template<typename MatrixType>
 void add_multiple_row(MatrixType& A,
                  typename matrix_traits<MatrixType>::index_type i,
                  typename matrix_traits<MatrixType>::index_type k,
                  typename matrix_traits<MatrixType>::value_type v)
{
  matrix_traits<MatrixType> mt;
  typedef typename matrix_traits<MatrixType>::index_type index_type;
 
  assert(mt.min_row(A) <= i);
  assert(i <= mt.max_row(A));
 
  assert(mt.min_row(A) <= k);
  assert(k <= mt.max_row(A));
 
  for (index_type col = mt.min_column(A); col <= mt.max_column(A); ++col)
    mt.element(A, i, col) += v * mt.element(A, k, col);
}
template<typename MatrixType>
 void to_reduced_row_echelon_form(MatrixType& A)
{
  matrix_traits<MatrixType> mt;
  typedef typename matrix_traits<MatrixType>::index_type index_type;
 
  index_type lead = mt.min_row(A);
 
  for (index_type row = mt.min_row(A); row <= mt.max_row(A); ++row)
  {
    if (lead > mt.max_column(A))
      return;
    index_type i = row;
    while (mt.element(A, i, lead) == 0)
    {
      ++i;
      if (i > mt.max_row(A))
      {
        i = row;
        ++lead;
        if (lead > mt.max_column(A))
          return;
      }
    }
    swap_rows(A, i, row);
    divide_row(A, row, mt.element(A, row, lead));
    for (i = mt.min_row(A); i <= mt.max_row(A); ++i)
    {
      if (i != row)
        add_multiple_row(A, i, row, -mt.element(A, i, lead));
    }
  }
}
#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<string>
using namespace std;
int main()
{
 char ch[100],s[100],s3[100];
  
long int res[100],i=0,j=0,k=0,temp=0,ores[100][100],t=0,col[1000],myres[100][100];
cin>>s3;
  int chk=1;
  for(i=0;i<strlen(s3);i++)
{
if(s3[i]>='0' && s3[i]<='9' || s3[i]==',' || s3[i]=='<' || s3[i]=='>')
{
  s[j]=s3[i];
    j++;
}
}
  s[j]='\0';
  j=0;
for(i=0;i<strlen(s);i++)
{
if(s[i]=='<' || s[i]=='>')
{
chk=0;
}
}
if(chk==0)
{
for(i=0;i<strlen(s);i++)
{
   if(s[i]!=',' && s[i] !='<' && s[i]!='>')
   {
   ch[j]=s[i];
   j++;
   }
   if((s[i]==',' || i==strlen(s)-1) || (s[i]=='<'&&s[i+1]=='>'))
   {
   ch[j]='\0';
   j=0;
   temp=atoi(ch);
   res[k]=temp;
   k++;
   }
   if(s[i]=='<' && s[i+1]=='>')
   {
   res[k]=12345;
   k++;
   }
   }
}
  else
  {
    for(i=0;i<strlen(s);i++)
{
if(s[i]!=',')
   {
   ch[j]=s[i];
   j++;
   }
  if((s[i]==',' || i==strlen(s)-1))
   {
   ch[j]='\0';
   j=0;
   temp=atoi(ch);
   res[k]=temp;
   k++;
   }
  }
  }
j=0;
int v=0,count=0;
for(i=0;i<k;i++)
{
if(res[i]==12345)
{
count++;
}
}
for(i=0;i<k;i++)
{
if(res[i]!=12345)
{
ores[j][v]=res[i];
v++;
}
if(res[i]==12345 || i==k-1)
{
j++;
col[t]=v;
t++;
v=0;
}
}
for(i=0;i<count+1;i++)
{
for(k=0;k<col[i];k++)
{
myres[i][k]=ores[i][k];
}
} 
  to_reduced_row_echelon_form(myres);
  for (int i = 0; i <count+1; i++)
  {
    for (int j = 0; j < col[i]; j++) 
    {
      std::cout <<myres[i][j]<<" ";
    }
   cout<<"\n";
  }
  return 0;
}