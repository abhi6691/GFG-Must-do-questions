/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description:
***********************************************************************************/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

typedef vector <int> vi;

template <typename T>
void swap(T *a, T *b) { T t = *a; *a = *b; *b = t;}

void printVec(vi v){for(int i = 0; i < v.size(); i++) cout<<v[i]<<" "; cout<<endl;}

class Graph
{
	int V;

	list<int> *adj;

	void DFSUtil(int src, vector<bool> &visited);

public:
	Graph(int v)
	{
		V = v;
		adj = new list<int>[V];
	}

	void addEdge(int src, int dest)
	{
		adj[src].push_back(dest);		
	}

	void DFS(int src);
};

void Graph::DFSUtil(int src, vector<bool> &visited)
{
	printf("%d ", src);
	visited[src] = true;

	list<int>::iterator it;
	for (it = adj[src].begin(); it != adj[src].end(); it++)
		if (!visited[*it])
			DFSUtil(*it, visited);
}

void Graph::DFS(int src)
{
	vector<bool> visited(V, false);

	DFSUtil(src, visited);
}

int main()
{
	freopen("D://inputf.in", "r", stdin);
	freopen("D://outputf.in", "w", stdout);

	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(2,4);
	g.DFS(0);
	return 0;
}