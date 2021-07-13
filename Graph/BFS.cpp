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
void breadth_first_search(vector<int> a[],int v,int size)
{
  cout<<"BFS is: ";
  vector<int> visited;
  visited.resize(size);
  for(int i=0;i<size;i++) visited[i]=0;
  queue<int> q;
  q.push(v);
  int j=0;
  visited[v]=1;
  while(!q.empty())
  {
    cout<<q.front()<<" ";
    q.pop();
    for(int i=0;i<a[j].size();i++){
      int k=a[j].at(i);
      if(visited[k]==0) 
      {
        q.push(k);
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
  breadth_first_search(graphAdj,0,v);

  cout<<graphAdj->size()<<endl; //? for asscessing value in graphAdj[0] use .at() method
  return 0;
}