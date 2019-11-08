/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description: https://www.geeksforgeeks.org/maximum-difference-between-node-and-its-ancestor-in-binary-tree/
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

struct Node 
{ 
    int key; 
    struct Node* left, *right; 
}; 
  
/* To create a newNode of tree and return pointer */
struct Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return (temp); 
} 

int maxDiffUtil(Node *root, int *res)
{
	if (root == nullptr)
		return INT_MAX;

	if (root->left == nullptr && root->right == nullptr)
		return root->key;

	int val = min(maxDiffUtil(root->left, res), maxDiffUtil(root->right, res));

	*res = max(*res, root->key - val);

	return min(val, root->key);
}

int maxDiff(Node *root)
{
	int res = INT_MIN;

	maxDiffUtil(root, &res);

	return res;
}

int main()
{
	freopen("D://inputf.in", "r", stdin);
	freopen("D://outputf.in", "w", stdout);

	Node* root; 
    root = newNode(8); 
    root->left = newNode(3); 
  
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->left->right->left = newNode(4); 
    root->left->right->right = newNode(7); 
  
    root->right = newNode(10); 
    root->right->right = newNode(14); 
    root->right->right->left = newNode(13); 
  
    printf("Maximum difference between a node and"
           " its ancestor is : %d\n", maxDiff(root)); 

	return 0;
}