/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description:
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

	void topologicalSortUtil(int src, vector<bool> &visited, stack<int> &stk);
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

	void topologicalSort();
};

void Graph::topologicalSort()
{
	vector<bool> visited(V, false);
	stack<int> Stack;

	for (int i = 0; i < V; i++)
		if (!visited[i])
			topologicalSortUtil(i, visited, Stack);

	while (!Stack.empty())
	{
		printf("%d ", Stack.top());
		Stack.pop();
	}
}

void Graph::topologicalSortUtil(int s, std::vector<bool> &visited, stack<int> &Stack)
{
	visited[s] = true;

	list<int>::iterator it;
	for (it = adj[s].begin(); it != adj[s].end(); it++)
		if (!visited[*it])
			topologicalSortUtil(*it, visited, Stack);

	Stack.push(s);
}

int main()
{
	freopen("D://inputf.in", "r", stdin);
	freopen("D://outputf.in", "w", stdout);

	Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 

    g.topologicalSort();

	return 0;
}