#include<bits/stdc++.h>
#include<iostream>
using namespace std;
// void printGraph(int graph[][v],int v){

// }
int main()
{
  ifstream infile;
  infile.open("graph.txt",ios::in);
  int v,e;
  infile>>v>>e;
  int graph[v][v];
  cout<<v<<e<<endl;
  for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
      infile>>graph[i][j];
    }
  }
  for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
      cout<<graph[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}