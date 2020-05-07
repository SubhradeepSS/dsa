 #include <bits/stdc++.h> 
using namespace std; 

/* Linked list node */
class Node 
{ 
	public: 
	int data; 
	Node* next; 
}; 

/* Function to create a new node with given data */
Node *newNode(int data) 
{ 
	Node *new_node = new Node(); 
	new_node->data = data; 
	new_node->next = NULL; 
	return new_node; 
} 

/* Function to insert a node at the 
beginning of the Singly Linked List */
void push(Node** head_ref, int new_data) 
{ 
	/* allocate node */
	Node* new_node = newNode(new_data); 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Adds contents of two linked lists and 
return the head node of resultant list */
Node* addTwoLists (Node* first, Node* second) 
{ 
    int sum,carry=0;
    Node *result,*prev=NULL;
    while(first||second){
        sum=carry+(first?first->data:0)+(second?second->data:0);
        carry=(sum>=10)?1:0;
        sum=sum%10;
        Node *t=newNode(sum);
        if(!prev){
            result=t;
        }
        else{
            prev->next=t;
        }
        prev=t;
        if(first)
            first=first->next;
        if(second)
            second=second->next;
    }
    if(carry>0)
        prev->next=newNode(carry);
    return result;
} 

// A utility function to print a linked list 
void printList(Node *node) 
{ 
	while(node != NULL) 
	{ 
		cout << node->data << " "; 
		node = node->next; 
	} 
	cout<<endl; 
} 

/* Driver code */
int main(void) 
{ 
	Node* res = NULL; 
	Node* first = NULL; 
	Node* second = NULL; 

	// create first list 7->5->9->4->6 
	push(&first, 6); 
	push(&first, 4); 
	push(&first, 9); 
	push(&first, 5); 
	push(&first, 7); 
	printf("First List is "); 
	printList(first); 

	// create second list 8->4 
	push(&second, 4); 
	push(&second, 8); 
	cout<<"Second List is "; 
	printList(second); 

	// Add the two lists and see result 
	res = addTwoLists(first, second); 
	cout<<"Resultant list is "; 
	printList(res); 

return 0; 
} 

// This code is contributed by rathbhupendra 
