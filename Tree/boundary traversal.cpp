#include<bits/stdc++.h>
using namespace std;

struct node { 
	int data; 
	struct node *left, *right; 
}; 

// A simple function to print leaf nodes of a binary tree 
void printLeaves(struct node* root) 
{ 
    if(!root)
        return;
    printLeaves(root->left);
    if(!(root->left)&&!(root->right))
        cout<<root->data<<" ";
    printLeaves(root->right);
} 

// A function to print all left boundary nodes, except a leaf node. 
// Print the nodes in TOP DOWN manner 
void printBoundaryLeft(struct node* root) 
{ 
    if(!root)
        return;
    if(root->left){
        cout<<root->data<<" ";
        printBoundaryLeft(root->left);
    }
    else if(root->right){
        cout<<root->data<<" ";
        printBoundaryLeft(root->right);
    }
} 

// A function to print all right boundary nodes, except a leaf node 
// Print the nodes in BOTTOM UP manner 
void printBoundaryRight(struct node* root) 
{ 
	if(!root)
	    return;
	if(root->right){
	    printBoundaryRight(root->right);
	    cout<<root->data<<" ";
	}
	else if(root->left){
	    printBoundaryRight(root->left);
	    cout<<root->data<<" ";
	}
} 

// A function to do boundary traversal of a given binary tree 
void printBoundary(struct node* root) 
{ 
    if(!root)
        return;
    cout<<root->data<<" ";
    printBoundaryLeft(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printBoundaryRight(root->right);
} 

// A utility function to create a node 
struct node* newNode(int data) 
{ 
	struct node* temp = (struct node*)malloc(sizeof(struct node)); 

	temp->data = data; 
	temp->left = temp->right = NULL; 

	return temp; 
} 

// Driver program to test above functions 
int main() 
{ 
	// Let us construct the tree given in the above diagram 
	struct node* root = newNode(20); 
	root->left = newNode(8); 
	root->left->left = newNode(4); 
	root->left->right = newNode(12); 
	root->left->right->left = newNode(10); 
	root->left->right->right = newNode(14); 
	root->right = newNode(22); 
	root->right->right = newNode(25); 

	printBoundary(root); 

	return 0; 
} 
