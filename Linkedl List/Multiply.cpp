#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int data; 
	struct Node* next; 
}; 

struct Node* newNode(int data) 
{ 
	struct Node* new_node = 
		(struct Node*)malloc(sizeof(struct Node)); 
	new_node->data = data; 
	new_node->next = NULL; 
	return new_node; 
} 

void push(struct Node** head_ref, int new_data) 
{ 
	
	struct Node* new_node = newNode(new_data); 

	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

int reverse(struct Node** head_ref) 
{ 
  int l=0;
  Node *prev=NULL,*curr=*head_ref,*next;
  while(curr){
      l++;
      next=curr->next;
      curr->next=prev;
      prev=curr;
      curr=next;
  }
  *head_ref=prev;
  return l;
} 

struct Node* make_empty_list(int size) 
{ 
    Node *head=NULL;
    while(size--){
        push(&head,0);
    }
    return head;
} 

struct Node* multiplyTwoLists(struct Node* first, 
						struct Node* second) 
{ 
    int m=reverse(&first),n=reverse(&second);
    Node *result=make_empty_list(m+n+1);
    Node *first_ptr,*second_ptr=second,*result_ptr1=result,*result_ptr2;
    while(second_ptr){
        int carry=0;
        result_ptr2=result_ptr1;
        first_ptr=first;
        while(first_ptr){
            int mul_value=first_ptr->data*second_ptr->data+carry;
            result_ptr2->data+=mul_value%10;
            carry=mul_value/10+result_ptr2->data/10;
            result_ptr2->data%=10;
            first_ptr=first_ptr->next;
            result_ptr2=result_ptr2->next;
        }
        if(carry>0){
            result_ptr2->data+=carry;
        }
        result_ptr1=result_ptr1->next;
        second_ptr=second_ptr->next;
    }
    reverse(&result);
    reverse(&first);
    reverse(&second);
    while(result->data==0){
        Node *t=result;
        result=result->next;
        free(t);
    }
    return result;
} 
void printList(struct Node* Node) 
{ 
	while (Node != NULL) { 
		cout << Node->data; 
		if (Node->next) 
			cout<<"->"; 
		Node = Node->next; 
	} 
	cout << endl; 
} 
int main(void) 
{ 
	struct Node* first = NULL; 
	struct Node* second = NULL; 

	// create first list 9->9->9->4->6->9 
	push(&first, 9); 
	push(&first, 6); 
	push(&first, 4); 
	push(&first, 9); 
	push(&first, 9); 
	push(&first, 9); 
	cout<<"First List is: "; 
	printList(first); 

	// create second list 9->9->8->4->9 
	push(&second, 9); 
	push(&second, 4); 
	push(&second, 8); 
	push(&second, 9); 
	push(&second, 9); 
	cout<<"Second List is: "; 
	printList(second); 

	
	struct Node* result = multiplyTwoLists(first, second); 
	cout << "Resultant list is: "; 
	printList(result); 

	return 0; 
} 
