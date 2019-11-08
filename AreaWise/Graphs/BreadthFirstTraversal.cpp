/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description: https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
***********************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;

template <typename T>
void swap(T *a, T *b) { T t = *a; *a = *b; *b = t;}

void printVec(vi v){for(int i = 0; i < v.size(); i++) cout<<v[i]<<" "; cout<<endl;}

class Graph
{
	int V;

	list<int> *adj;

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

	void addEdgeBi(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void BFS(int src);
};

void Graph::BFS(int s)
{
	vector<bool> visited(V, false);

	list<int> queue;
	list<int>::iterator it;

	queue.push_back(s);
	while (!queue.empty())
	{
		s = queue.front();
		queue.pop_front();

		printf("%d ", s);

		for (it = adj[s].begin(); it != adj[s].end(); it++)
			if (!visited[*it])
				queue.push_back(*it);
	}
}

int main()
{
	freopen("D://inputf.in", "r", stdin);
	freopen("D://outputf.in", "w", stdout);

	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(2, 4);
	g.BFS(0);
	return 0;
}