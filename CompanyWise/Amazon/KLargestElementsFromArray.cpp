/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description: https://practice.geeksforgeeks.org/problems/k-largest-elements/0
***********************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define PRD(t) printf("%d ", t)
#define SCD(t) scanf("%d",&t)
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,a,b) for (int i = (a); i >= (b); i--)
#define PB push_back
typedef vector <int> vi;

template <typename T>
void swap(T *a, T *b) { T t = *a; *a = *b; *b = t;}

void printVec(vi v){for(int i = 0; i < v.size(); i++) cout<<v[i]<<" "; cout<<endl;}

void minheapify(vi &v, int n, int ind)
{
	//printf("minheapify called for index: %d\n", ind);
	int smallest = ind;
	int left = 2*ind + 1;
	int right = 2*ind + 2;

	if (left < n && v[left] < v[smallest])
		smallest = left;

	if (right < n && v[right] < v[smallest])
		smallest = right;

	if (smallest != ind)
	{
		swap(&v[smallest], &v[ind]);
		minheapify(v, n, smallest);
	}
}

void printKLargest(vi &v, int k)
{
	RFOR(i, k/2-1, 0)
	{
		minheapify(v, k, i);
	}

	FOR(i, k, v.size())
	{
		if (v[i] > v[0])
		{
			swap(&v[i], &v[0]);
			minheapify(v, k, 0);
		}
	}

	sort(v.begin(), v.begin()+k, greater<int>());

	FOR(i, 0, k)
		PRD(v[i]);
}

int main()
{
	freopen("D://inputf.in", "r", stdin);
	freopen("D://outputf.in", "w", stdout);

	int n, k;
	SCD(n);
	vi v;
	FOR(i, 0, n)
	{
		int t; SCD(t); v.PB(t);
	}
	SCD(k);

	printKLargest(v, k);
	return 0;
}