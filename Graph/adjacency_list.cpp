#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void addEdge(vector<int> graphAdj[],int u,int v) //? undirected graph
{
  graphAdj[u].push_back(v); //? reprsent ith index and pushing adjacent vertex
  graphAdj[v].push_back(u); //? vice versa
}
void printGraph(vector<int> adj[], int V)
{
  for (int v = 0; v < V; ++v)
  {
    cout << "\n Adjacency list of vertex "<< v << "\n head "<< v;
    for (auto x : adj[v])
      cout << " -> " << x;
    printf("\n");
  }
}
int main()
{
  ifstream infile;
  infile.open("graph2.txt",ios::in);
  int v,e;
  infile>>v>>e;
  vector<int> graphAdj[v];
  for(int i=0;i<v;i++){
    int u,w;
    infile>>u>>w;
    addEdge(graphAdj,u,w);
  }
  //! graphAdj[v] == [[1,4,5],[2,0,3],[..],[..],..] format of vector array
  printGraph(graphAdj,v);

  cout<<graphAdj[0].at(0)<<endl; //? for asscessing value in graphAdj[0] use .at() method
  return 0;
}