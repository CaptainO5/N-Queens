#include"Stack.h"

bool stack :: isEmpty() {
	if(!top)
		return true;
	else
		return false;
}

int stack :: push(struct position data) {
	struct node * newNode = (struct node *) malloc (sizeof(struct node));
	if(!newNode)
		return 1;
		
	newNode -> data = data;
	newNode -> next = top;
	top = newNode;
		
	return 0;	
}

int stack :: pop(struct position * data) {
	if(isEmpty())
		return 1;
		
	struct node * temp = top;
	* data = top -> data;
	top = top -> next;
	free(temp);
	return 0;
}
