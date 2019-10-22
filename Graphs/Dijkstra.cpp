/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
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

	vector< vector<int> > adjMatrix;

	int minDist(vector<bool> sptSet, vector<int> dist)
	{
		int minDist = INT_MAX, minIndex;
		for (int i = 0; i < V; i++)
		{
			if (!sptSet[i] && dist[i] < minDist)
			{
				minDist = dist[i];
				minIndex = i;
			}
		}

		return minIndex;
	}

public:
	Graph(int v, vector< vector<int> > adjMatrix)
	{
		this->V = v;
		this->adjMatrix = adjMatrix; 
	}

	void Dijkstra(int s);
};

void Graph::Dijkstra(int s)
{
	vector<bool> sptSet(V, false);
	vector<int> dist(V, INT_MAX);

	dist[s] = 0;

	for (int count = 0; count < V-1; count++)
	{
		int u = minDist(sptSet, dist);

		sptSet[u] = true;
		for (int v = 0; v < V; v++)
		{
			if (!sptSet[v] && adjMatrix[u][v] && dist[u] != INT_MAX
			 && dist[u] + adjMatrix[u][v] < dist[v])
				dist[v] = dist[u] + adjMatrix[u][v];
		}
	}

	for (int i = 0; i < V; i++)
		printf("%d ", dist[i]);
}

int main()
{
	freopen("D://inputf.in", "r", stdin);
	freopen("D://outputf.in", "w", stdout);

	int V = 9;
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 

    vector< vector<int> > adj;
    for (int i = 0; i < V; i++)
    {
    	vector<int> row;
    	for (int j = 0; j < V; j++)
    	{
    		row.push_back(graph[i][j]);
    	}
    	adj.push_back(row);
    }

    Graph g(V, adj);
    g.Dijkstra(0);

	return 0;
}