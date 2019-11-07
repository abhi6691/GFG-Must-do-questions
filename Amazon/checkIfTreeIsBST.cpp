/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description: https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
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

class Node  
{  
    public: 
    int data;  
    Node* left;  
    Node* right;  
      
    /* Constructor that allocates  
    a new node with the given data 
    and NULL left and right pointers. */
    Node(int data) 
    { 
        this->data = data; 
        this->left = NULL; 
        this->right = NULL; 
    } 
}; 

bool isBSTUtil(Node *node, int min, int max)
{
	if (node == nullptr)
		return true;

	if (node->data < min || node->data > max)
		return false;

	return isBSTUtil(node->left, min, node->data - 1) && isBSTUtil(node->right, node->data + 1, max);
}

bool isBST(Node *node)
{
	return isBSTUtil(node, INT_MIN, INT_MAX);
}

int main()
{
	freopen("D://inputf.in", "r", stdin);
	freopen("D://outputf.in", "w", stdout);

	Node *root = new Node(11);  
    root->left = new Node(8);  
    root->right = new Node(23);  
    root->left->left = new Node(4);  
    root->left->right = new Node(13);
    root->right->left = new Node(12);
    root->right->right = new Node(25);  
      
    if(isBST(root))  
        cout<<"Is BST";  
    else
        cout<<"Not a BST"; 

	return 0;
}