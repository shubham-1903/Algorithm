#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define INF 999
int M[100][100];
const int x=6;
int S[x][x];
void matrix_chain(int *p,int n)
{
  for(int i=1;i<= n; i++) M[i][i]=0;

  for(int len=2; len <= n; len++){
    for(int i=1; i <= n-len+1; i++){
      int j=i+len-1;
      M[i][j]=INF;
      for(int k = i; j < n && k <= j - 1; k++){
        int cost=M[i][k] + M[k+1][j] + p[i-1] * p[k] * p[j];
        if(cost<M[i][j]){
          M[i][j]=cost;
          S[i][j]=k;
        }
      }
    }
  }
}
void print_optimal_parens(int S[x][x],int i,int j)
{
  if(i==j) cout<<"A"<<i;
  else{
    cout<<"(";
    print_optimal_parens(S,i,S[i][j]);
    print_optimal_parens(S,S[i][j]+1,j);
    cout<<")";
  }
}
int main()
{
  int n;
  cin>> n;
  int p[n];
  for(int i = 0; i < n; i++)
    cin>>p[i];
  matrix_chain(p,n);
  for(int i=1; i < n; i++){
    for(int j= 1; j < n; j++)
      cout<<M[i][j]<<"  ";
    cout<<endl;
  }
  cout<<"Minimum Cost is "<<M[1][n-1]<<endl;
  for(int i=1; i < n; i++){
    for(int j= 1; j < n; j++)
      cout<<S[i][j]<<"  ";
    cout<<endl;
  }
  print_optimal_parens(S,1,5);
  return 0;
}

//! Input
//* 6
//*2 3 5 2 4 3