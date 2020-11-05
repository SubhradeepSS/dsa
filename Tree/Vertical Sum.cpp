// C++ program to find Vertical Sum in 
// a given Binary Tree 
#include<bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int data; 
	struct Node *left, *right; 
}; 

// A utility function to create a new 
// Binary Tree node 
Node* newNode(int data) 
{ 
	Node *temp = new Node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

void util(Node* node,map<int,int> &Map,int hd){
    if(!node)
        return;
    util(node->left,Map,hd-1);
    Map[hd]+=node->data;
    util(node->right,Map,hd+1);
}

void verticalSum(Node* root){
    map<int,int> Map;
    util(root,Map,0);
    for(auto it=Map.begin();it!=Map.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}
// Driver program to test above functions 
int main() 
{ 
	// Create binary tree as shown in above figure 
	Node *root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->left = newNode(6); 
	root->right->right = newNode(7); 
	root->right->left->right = newNode(8); 
	root->right->right->right = newNode(9); 

	cout << "Following are the values of vertical"
			" sums with the positions of the "
			"columns with respect to root\n"; 
	verticalSum(root); 

	return 0; 
} 
// This code is contributed by Aditi Sharma 
