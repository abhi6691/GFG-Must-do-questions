/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description: https://www.geeksforgeeks.org/print-a-binary-tree-in-vertical-order-set-3-using-level-order-traversal/
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

// Structure for a binary tree node 
struct Node 
{ 
    int key; 
    Node *left, *right; 
}; 
  
// A utility function to create a new node 
Node* newNode(int key) 
{ 
    Node* node = new Node; 
    node->key = key; 
    node->left = node->right = NULL; 
    return node; 
} 

void printVerticalOrder(Node *root)
{
	if (!root)
		return;

	map<int, vector<int> > m;
	int hd = 0;
	queue<pair<Node*, int> > q;
	q.push(make_pair(root, hd));

	while (!q.empty())
	{
		pair<Node*, int> temp = q.front();
		q.pop();
		Node *cur = temp.first;
		int thd = temp.second;
		
		m[thd].PB(cur->key);
		if (cur->left)
			q.push(make_pair(cur->left, thd-1));
		if (cur->right)
			q.push(make_pair(cur->right, thd+1));
	}

	map<int, vector<int> >::iterator it;
	ITER(it, m)
	{
		FOR(i, 0, it->second.size())
		{
			PRD(it->second[i]);
		}
		NL;
	}
}

int main()
{
	freopen("D://inputf.in", "r", stdin);
	freopen("D://outputf.in", "w", stdout);

	Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 
    root->right->right->left= newNode(10); 
    root->right->right->left->right= newNode(11); 
    root->right->right->left->right->right= newNode(12); 
    cout << "Vertical order traversal is \n"; 
    printVerticalOrder(root); 

	return 0;
}