/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description: https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
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

/* Link list node */
struct Node { 
    int data; 
    struct Node* next; 
}; 

/* Function to print linked list */
void printList(struct Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data << " "; 
        node = node->next; 
    } 
} 
  
struct Node* newNode(int key) 
{ 
    struct Node* temp = new Node(); 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 

void detectAndRemoveLoop(Node *head)
{
	Node *slow = head, *fast = head, *temp = head;
	bool loopFound = false;

	while(slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			loopFound = true;
			break;
		}
	}

	if (!loopFound)
	{
		printf("No loop in linked list\n");
		return;
	}

	fast = head;

	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	//printf("loop found at node: %d\n", slow->data);
	bool firstPass = true;
	while (1)
	{
		if (temp->next == slow && !firstPass)
			break;

		if (temp->next == slow)
			firstPass = false;

		temp = temp->next;
	}

	temp->next = NULL;

	printf("Loop Removed\n");
	printf("List after removing loop: ");
	printList(head);
}

int main()
{
	freopen("D://inputf.in", "r", stdin);
	freopen("D://outputf.in", "w", stdout);

	struct Node* head = newNode(50); 
    head->next = newNode(20); 
    head->next->next = newNode(15); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(10); 
  
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next; 
  
    detectAndRemoveLoop(head); 

	return 0;
}