#include <bits/stdc++.h> 
#include <inttypes.h> 
using namespace std; 

class Node 
{ 
	public: 
	int data; 
	Node* npx; /* XOR of next and previous node */
};
Node* XOR (Node *a, Node *b) 
{ 
    return (Node*)((uintptr_t)(a)^(uintptr_t)(b));
}
void insert(Node **head_ref, int data) 
{ 
	Node *n=new Node();
	n->data=data;
	n->npx=XOR(NULL,*head_ref);
	if(*head_ref!=NULL){
	    Node *next=XOR((*head_ref)->npx,NULL);
	    (*head_ref)->npx=XOR(n,next);
	}
	*head_ref=n;
}
void printList (Node *head) 
{ 
 Node *prev=NULL,*curr=head,*next;
 while(curr){
     cout<<curr->data<<" ";
     next=XOR(prev,curr->npx);
     prev=curr;
     curr=next;
 }
} 

int main () 
{ 
	Node *head = NULL; 
	insert(&head, 10); 
	insert(&head, 20); 
	insert(&head, 30); 
	insert(&head, 40); 
 
	printList (head); 

	return (0); 
}
