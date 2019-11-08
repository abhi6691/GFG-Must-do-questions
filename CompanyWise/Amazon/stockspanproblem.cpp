/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description:
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

void stockspan(vi v)
{
	int n = v.size();
	stack<int> s;
	vi h(n);

	FOR(i,0,n)
	{
		if (s.empty())
		{
			h[i] = -1;
			s.push(i);
		}
		else
		{
			int top = s.top();
			while (top != -1 && v[top] <= v[i])
			{
				s.pop();
				top = s.empty() ? -1 : s.top();
			}
			h[i] = top;
			s.push(i);
		}
	}

	FOR(i,0,n)
	{
		h[i] = i - h[i];
	}

	printVec(h);
}

int main()
{
	freopen("D://inputf.in", "r", stdin);
	freopen("D://outputf.in", "w", stdout);

	int t; SCD(t);
	while (t--)
	{
		int n; vi v;
		SCD(n);
		FOR(i,0,n)
		{
			int t;
			SCD(t); v.PB(t);
		}

		stockspan(v);
	}
	return 0;
}