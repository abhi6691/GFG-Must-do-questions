/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description: https://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-4/
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

// Structure for tree and linked list 
struct Node 
{ 
    int data; 
    Node *left, *right; 
}; 

// Utility function for allocating node for Binary 
// Tree. 
Node* newNode(int data) 
{ 
    Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 

void convertBTToDLLUtil(Node *root, Node **head_ref)
{
	if (root == nullptr)
		return;

	convertBTToDLLUtil(root->right, head_ref);

	root->right = *head_ref;

	if (*head_ref != nullptr)
		(*head_ref)->left = root;

	*head_ref = root;

	convertBTToDLLUtil(root->left, head_ref);
}

Node* convertBTToDLL(Node *root)
{
	Node *head = nullptr;

	convertBTToDLLUtil(root, &head);

	return head;
}

void printList(Node *head)
{
	Node *t = head, *last = head;

	while (t)
	{
		PRD(t->data);
		last = t;
		t = t->right;
	}
	NL;

	while (last)
	{
		PRD(last->data);
		last = last->left;
	}
}

int main()
{
	freopen("D://inputf.in", "r", stdin);
	freopen("D://outputf.in", "w", stdout);

	/* Constructing below tree 
               5 
             /   \ 
            3     6 
           / \     \ 
          1   4     8 
         / \       / \ 
        0   2     7   9  */
    Node* root = newNode(5); 
    root->left = newNode(3); 
    root->right = newNode(6); 
    root->left->left = newNode(1); 
    root->left->right = newNode(4); 
    root->right->right = newNode(8); 
    root->left->left->left = newNode(0); 
    root->left->left->right = newNode(2); 
    root->right->right->left = newNode(7); 
    root->right->right->right = newNode(9); 
   
    Node *head = convertBTToDLL(root);
    printList(head);
    
	return 0;
}