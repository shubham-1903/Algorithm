#include<bits/stdc++.h>
#include<iostream>
using namespace std;
// const int V=6;
class Edge
{
  public:
  int src,dest,weight;
};
class Graph
{
public:
  int V,E;
  Edge* edge;
};
Graph* create_graph(int V,int E)
{
  Graph* graph= new Graph;
  graph->V=V;
  graph->E=E;
  graph->edge = new Edge[E];
  return graph;
}
bool bellman_ford(Graph* graph,int s)
{
  int V=graph->V;
  int E=graph->E;

  vector<int> dist(V,INT_MAX);
  int parent[V];
  dist[s]=0;

  for(int i=1;i<=V-1;i++)
  {
    for(int j=0; j < E; j++)
    {
      int u=graph->edge[j].src;
      int v=graph->edge[j].dest;
      int w=graph->edge[j].weight;

      if(dist[u]!=INT_MAX && dist[u]+w<dist[v])
      {
        dist[v]=dist[u]+w;
        parent[v]=u;
      }
    }
  }

  //* check for negative-weight cycles
  for(int j=0; j < E; j++)
  {
      int u=graph->edge[j].src;
      int v=graph->edge[j].dest;
      int w=graph->edge[j].weight;
      if(dist[u]+w<dist[v]) return false;
  }
  return true;
}
// bool bellman_ford(int graph[V][V],int s)
// {
//   vector<int> d(V,INT_MAX);
//   vector<int> p(V,NULL);

//   d[s]=0;

//   for(int i=0; i < V-1; i++)
//   {
//     for(int j=0; j < V; j++)
//     {
//       if()
//     }
//   }
// }
int main()
{
  // int graph[V][V];
  ifstream infile;
  infile.open("bellman.txt", ios::in);
  // for(int i=0;i<V; i++)
  //   for(int j=0; j < V; j++)
  //     infile>> graph[i][j];

  // bool res=bellman_ford(graph,0);
  int t;
  infile >> t;
  while(t--)
  {
  int V,E;
  infile>>V>>E;
  cout<<"V: "<<V<<" and  E: "<<E<<endl;
  Graph * graph = create_graph(V,E);
  for(int i=0;i<E; i++){
    infile>>graph->edge[i].src>>graph->edge[i].dest>>graph->edge[i].weight;
    cout<<i<<endl;
  }
  cout<<"a: "<<graph->edge[0].weight<<endl;
  for(int i=0; i < E; i++)
    cout<<" -- "<<graph->edge[i].src<<" -- "<<graph->edge[i].dest<<" -- "<<graph->edge[i].weight<<endl;

  bool res = bellman_ford(graph,0);
  if(res) cout<<"No negative cycle\n";
  else cout<<"Negative cycle present\n";
  }
  return 0;
}