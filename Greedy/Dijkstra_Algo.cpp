#include <bits/stdc++.h>
#include <iostream>
const int V=9;
using namespace std;
int selectedMinVertex(vector<int> &value,vector<bool>& setMst)
{
  int minimum=INT_MAX;
  int vertex;
  for(int i = 0; i < V; i++)
  {
    if(setMst[i]==false && value[i]<minimum)
    {
      vertex=i;
      minimum=value[i];
    }
  }
  return vertex;
}
void find_mst(int graph[V][V])
{
  int parent[V];
  vector<int> value(V,INT_MAX);
  vector<bool> setMst(V,false);

  parent[0]=-1;
  value[0]=0;
  int s=0;
  for(int i = 0; i < V-1; i++)
  {
    int U=selectedMinVertex(value,setMst);
    setMst[U]=true;
    for(int j=0; j < V; j++)
    {
      if(graph[U][j]!=0 && setMst[j]==false && value[U]!=INT_MAX && (value[U]+ graph[U][j])<value[j])
      {
        value[j]=value[U]+graph[U][j];
        parent[j]=U;
      }
    }
  }
  cout<<"vertex"<<"   "<<"Distance from src"<<endl;
  for(int i = 0; i < V; i++)
      cout <<char(i+65)<<"  \t\t"<<value[i]<<endl;
}
int main()
{
  ifstream infile;
  infile.open("prims.txt", ios::in);
  // int V;
  // infile >> V;
  int graph[V][V];
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      infile >> graph[i][j];

  find_mst(graph); //* Time Complexity = O(V*V)
  return 0;
}