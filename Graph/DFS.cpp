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
void depth_first_search(vector<int> a[],int v,int size)
{
  cout<<"DFS is: ";
  vector<int> visited;
  visited.resize(size);
  for(int i=0;i<size;i++) visited[i]=0;
  stack<int> s;
  s.push(v);
  visited[v]=1;
  while(!s.empty())
  {
    cout<<s.top()<<" ";
    int j=s.top();

    s.pop();
    for(int i=0;i<a[j].size();i++){
      int k=a[j].at(i);
      if(visited[k]==0) 
      {
        s.push(k);
        visited[k]=1;
      }
    }
    j++;
  
    
  }

}
int main()
{
  ifstream infile;
  infile.open("graph3.txt",ios::in);
  int v,e;
  infile>>v>>e;
  vector<int> graphAdj[v];
  for(int i=0;i<e;i++){
    int u,w;
    infile>>u>>w;
    addEdge(graphAdj,u,w);
  }
  //! graphAdj[v] == [[1,4,5],[2,0,3],[..],[..],..] format of vector array
  // printGraph(graphAdj,v);
  depth_first_search(graphAdj,0,v);

  return 0;
}