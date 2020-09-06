// C++ program to check if all leaves 
// are at same level 
#include <bits/stdc++.h> 
using namespace std; 

// A binary tree node 
struct Node 
{ 
	int data; 
	struct Node *left, *right; 
}; 

// A utility function to allocate 
// a new tree node 
struct Node* newNode(int data) 
{ 
	struct Node* node = (struct Node*) malloc(sizeof(struct Node)); 
	node->data = data; 
	node->left = node->right = NULL; 
	return node; 
}

bool util(Node* root,int level,int *leaflevel){
    if(!root)
        return true;
    if(root->left==NULL&&root->right==NULL){
        if(*leaflevel==0){
            *leaflevel=level;
            return true;
        }
        return (level==*leaflevel);
    }
    return util(root->left,level+1,leaflevel)&&util(root->right,level+1,leaflevel);
}

bool check(Node* root){
    int level=0,leaflevel=0;
    return util(root,level,&leaflevel);
}

int main()
{ 
	// Let us create tree shown in third example 
	struct Node *root = newNode(12); 
	root->left = newNode(5); 
	root->left->left = newNode(3); 
	root->left->right = newNode(9); 
	root->left->left->left = newNode(1); 
	root->left->right->left = newNode(1); 
	if (check(root)) 
		cout << "Leaves are at same level\n"; 
	else
		cout << "Leaves are not at same level\n"; 
	//getchar(); 
	return 0; 
} 

// This code is contributed 
// by Akanksha Rai 
