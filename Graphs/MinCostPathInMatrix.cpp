/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description: https://www.geeksforgeeks.org/min-cost-path-dp-6/
***********************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;

template <typename T>
void swap(T *a, T *b) { T t = *a; *a = *b; *b = t;}

void printVec(vi v){for(int i = 0; i < v.size(); i++) cout<<v[i]<<" "; cout<<endl;}

int min(int x, int y, int z)
{
	if (x < y)
		return x < z ? x : z;
	else
		return y < z ? y : z;
}

int minCostPath(vector< vector<int> > cost)
{
	int C = cost.size();
	int R = cost[0].size();

	int tc[R][C];

	tc[0][0] = cost[0][0];

	for (int i = 1; i < C; i++)
		tc[0][i] = tc[0][i-1] + cost[0][i];

	for (int i = 1; i < R; i++)
		tc[i][0] = tc[i-1][0] + cost[i][0];

	for (int i = 1; i < C; i++)
	{
		for (int j = 1; j < R; j++)
		{
			tc[i][j] = cost[i][j] + min(tc[i-1][j], tc[i][j-1], tc[i-1][j-1]);
		}
	}

	return tc[R-1][C-1];
}

int main()
{
	freopen("D://inputf.in", "r", stdin);
	freopen("D://outputf.in", "w", stdout);

	int R = 3, C = 3;
	int cost[R][C] = { {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} }; 

    vector< vector<int> > adj;
    for (int i = 0; i < C; i++)
    {
    	vector<int> row;
    	for (int j = 0; j < R; j++)
    	{
    		row.push_back(cost[i][j]);
    	}
    	adj.push_back(row);
    }

    cout<<minCostPath(adj);

	return 0;
}