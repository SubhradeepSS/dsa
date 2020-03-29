#include <stdio.h> 
#include <stdlib.h> 

/* A binary tree node has data, left child and right child */
struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
}; 

bool isLeaf(node* root){
    if(root->left==NULL&&root->right==NULL)
        return true;
    return false;
}

bool isSumTree(node* root){
    if(!root||isLeaf(root))
        return true;
        int ls,rs;
    if(isSumTree(root->left)&&isSumTree(root->right)){
        if(root->left==NULL)
            ls=0;
        else if(isLeaf(root->left))
            ls=root->left->data;
        else
            ls=2*(root->left->data);
        if(root->right==NULL)
            rs=0;
        else if(isLeaf(root->right))
            rs=root->right->data;
        else
            rs=2*(root->right->data);
        return (root->data==ls+rs);
    }
    return false;
}

struct node* newNode(int data) 
{ 
	struct node* node = 
		(struct node*)malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return(node); 
} 

/* Driver program to test above function */
int main() 
{ 
	struct node *root = newNode(26); 
	root->left		 = newNode(10); 
	root->right	 = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(6); 
	root->right->right = newNode(3); 
	if(isSumTree(root)) 
		printf("The given tree is a SumTree "); 
	else
		printf("The given tree is not a SumTree "); 

	getchar(); 
	return 0; 
} 
