
// C++ program to detect and remove loop 
#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int key; 
	struct Node* next; 
}; 

Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->next = NULL; 
	return temp; 
} 

// A utility function to print a linked list 
void printList(Node* head) 
{ 
	while (head != NULL) { 
		cout << head->key << " "; 
		head = head->next; 
	} 
	cout << endl; 
} 

// Function to detect and remove loop 
// in a linked list that may contain loop 
void detectAndRemoveLoop(Node* head) 
{ 
	if(head==NULL||head->next==NULL)
	    return;
	Node *f=head,*s=head;
	f=f->next->next;s=s->next;
	while(f&&f->next){
	    if(f==s)
	        break;
	    f=f->next->next;
	    s=s->next;
	}
	if(f==s){
	    s=head;
	    while(s->next!=f->next)
	        {
	            s=s->next;f=f->next;
	        }
	        f->next=NULL;
	}
} 

/* Driver program to test above function*/
int main() 
{ 
	Node* head = newNode(50); 
	head->next = head; 
	head->next = newNode(20); 
	head->next->next = newNode(15); 
	head->next->next->next = newNode(4); 
	head->next->next->next->next = newNode(10); 

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next->next; 

	detectAndRemoveLoop(head); 

	printf("Linked List after removing loop \n"); 
	printList(head); 

	return 0; 
} 
