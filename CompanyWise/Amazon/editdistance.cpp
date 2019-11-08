/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description: https://www.geeksforgeeks.org/edit-distance-dp-5/
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

int min3(int x, int y, int z)
{
	return min(min(x,y), z);
}

int editDistance(string str1, string str2)
{
	int m = str1.size(), n = str2.size();

	int dp[m+1][n+1];

	FOR(i,0,m+1)
	{
		FOR(j,0,n+1)
		{
			if (i == 0)
				dp[i][j] = j;

			else if (j == 0)
				dp[i][j] = i;

			else if (str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j-1];

			else
				dp[i][j] = 1 + min3(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]);
		}
	}

	return dp[m][n];
}

int main()
{
	freopen("D://inputf.in", "r", stdin);
	freopen("D://outputf.in", "w", stdout);

	string str1 = "sunday";
	string str2 = "saturday";

	PRD(editDistance(str1, str2));

	return 0;
}