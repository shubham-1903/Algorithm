#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> parent;
int find(int v)
{
  if(parent[v]==-1)
    return v;
  return find(parent[v]);
}
void union_op(int fromP,int toP)
{
  fromP=find(fromP);
  toP=find(toP);
  parent[fromP]=toP;
}
bool is_cyclic(vector<pair<int,int>> &edge_list)
{
  for(auto p:edge_list)
  {
    int fromP=find(p.first);
    int toP=find(p.second);

    if(fromP==toP)
      return true;

    union_op(fromP,toP);
  }
  return false;
}
int main()
{
  int e, v;
  cin>>e>>v;

  parent.resize(v,-1);
  vector<pair<int,int>> edge_list;
  for(int i=0; i < e; i++)
  {
    int from,to;
    cin>> from >> to;
    edge_list.push_back({from,to});
  }
  if(is_cyclic(edge_list))
    cout<<"TRUE"<< endl;
  else
    cout<<"FALSE"<< endl;
  return 0;
}