/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description: https://www.geeksforgeeks.org/find-number-of-islands/
***********************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define NL printf("\n")
#define PRD(t) printf("%d ", t)
#define SCD(t) scanf("%d",&t)
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,a,b) for (int i = (a); i >= (b); i--)
#define ITER(it, m) for (it = m.begin(); it != m.end(); it++)
#define PB push_back
typedef vector <int> vi;

template <typename T>
void swap(T *a, T *b) { T t = *a; *a = *b; *b = t;}

void printVec(vi v){for(int i = 0; i < v.size(); i++) cout<<v[i]<<" "; cout<<endl;}

#define ROW 5
#define COL 5

bool isSafe(int M[][COL], int r, int c, bool visited[][COL])
{
	return ((r >= 0) && (r < ROW) && 
		(c >= 0) && (c < COL) && 
		(M[r][c] == 1) && 
		!visited[r][c]);
}

void DFS(int M[][COL], int r, int c, bool visited[][COL])
{
	//printf("DFS called for M[%d][%d]\n", r, c);
	int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};

	visited[r][c] = true;

	FOR(i,0,8)
	{
		if (isSafe(M, r + rowNbr[i], c + colNbr[i], visited))
		{
			//printf("Exploring neighbor M[%d][%d]\n", r + rowNbr[i], c + colNbr[i]);
			DFS(M, r + rowNbr[i], c + colNbr[i], visited);
		}
	}
}

int countIslands(int M[][COL])
{
	bool visited[ROW][COL];
	memset(visited, 0, sizeof(visited));

	int numOfIslands = 0;

	FOR(i,0,ROW)
	{
		FOR(j,0,COL)
		{
			if (M[i][j] == 1 && !visited[i][j])
			{
				DFS(M, i, j, visited);

				numOfIslands++;
			}
		}
	}

	return numOfIslands;
}

int main()
{
	freopen("D://inputf.in", "r", stdin);
	freopen("D://outputf.in", "w", stdout);

	int M[ROW][COL] = { { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } }; 

    cout << "Number of islands is: " << countIslands(M); 

	return 0;
}