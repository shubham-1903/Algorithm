//kruskals algorithm 
//Time complexity O(ElogE) E-total number of edges
//space complexity O(V)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
	int u;
	int v;
	int wt;
	node(int first,int second,int weight)
	{
		u=first;
		v=second;
		wt=weight;
	}
};
struct Pair{
    int first;
    int second;
    Pair(int a,int b)
    {
        first=a;
        second=b;
    }
};
bool comp(node a,node b)
{
	return a.wt<b.wt;
}

void Swap(struct node* a,struct node* b)
{
    //First swap the weights
    int temp=a->wt;
    a->wt=b->wt;
    b->wt=temp;
    //Second swap the parent
    temp=a->u;
    a->u=b->u;
    b->u=temp;
    //Third swap the destination
    temp=a->v;
    a->v=b->v;
    b->v=temp;
    
}

int findPar(int u,vector<int>& parent)
{
	if(parent[u]==u)
	return u;
	return parent[u]=findPar(parent[u],parent);
}

void Union(int u,int v,vector<int>& parent,vector<int>& rank)
{
	u=findPar(u,parent);
	v=findPar(v,parent);
	if(rank[u]<rank[v])
	{
		parent[u]=v;
	}
	else if(rank[u]>rank[v])
	{
		parent[v]=u;
	}
	else
	{
		parent[v]=u;
		rank[u]++;
	}
	
}

int partition(vector<node>& edges,int l,int r)
{
    int pivot=edges[r].wt;
    int i=l-1;
    for(int j=l;j<r;j++)
    {
        if(edges[j].wt<pivot)
        {
            i++;
            Swap(&edges[i],&edges[j]);
        }
    }
    Swap(&edges[i+1],&edges[r]);
    return i+1;
}

void QuickSort(vector<node>& edges,int l,int r)
{
    if(l<r)
    {
        int pi=partition(edges,l,r);
        QuickSort(edges,l,pi-1);
        QuickSort(edges,pi+1,r);
    }
}
int main()
{
  ifstream infile;
  infile.open("kk.txt",ios::in);
	int n,m;
	cout<<"Enter the number of vertices and number of edges"<<"\n";
	infile>>n>>m;
	vector<node> edges;
	int i;
	cout<<"Enter the all edges and their adjacent vertices and weight"<<"\n";
	for(i=0;i<m;i++)
	{
		int u,v,wt;
		infile>>u>>v>>wt;
		edges.push_back(node(u,v,wt));
	}
	
	vector<int> parent;
	for(i=0;i<n;i++)
	{
		parent.push_back(i);
	}
	for(i=0;i<n;i++)
	parent[i]=i;
	
	vector<int> rank(n);
	QuickSort(edges,0,m-1);
	
	for(i=0;i<n;i++)
	rank[i]=0;
	
	int res=0;

  vector<Pair> mst;
	
	for(i=0;i<m;i++)
	{
		if(findPar(edges[i].u,parent)!=findPar(edges[i].v,parent))
		{
			res+=edges[i].wt;
			Union(edges[i].u,edges[i].v,parent,rank);
			mst.push_back(Pair(edges[i].u,edges[i].v));
		}
	}
	cout<<"The cost of the spanning tree is"<<"\n";
	cout<<res<<"\n";
	cout<<"The tree is"<<"\n";
	for(i=0;i<mst.size();i++)
	{
		cout<<mst[i].first<<" "<<mst[i].second<<"\n";
	}
}