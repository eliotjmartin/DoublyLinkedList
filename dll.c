#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data; // data is integers 
	struct node *next; // link to the next element in list
	struct node *prev; // link to previous element in list	
} Node;


void print(Node *theList) {
	/*
	 * argument: sentinel of linked list
	 *
	 * prints the data from each node in a 
	 * linked list
	 */
	Node *p; // for the current element

	for (p=theList->next; p!=theList; p=p->next) { // while p is not sentinel
		printf("%d\n", p->data); // print p's data
	}
}

void printReversed(Node *theList) {
	/*
	 * argument: sentinel of linked list
	 *
	 * prints the data from each node in a 
	 * linked list in reversed order
	 */
	Node *p; // for the current element

	for (p=theList->prev; p!=theList; p=p->prev) { // while p is not sentinel
		printf("%d\n", p->data); // print p's data
	}
}


void freeList(Node *theList) {
	Node *p = theList->next; // have p start at first element after sentinel

	while (p != theList){  // while p is not the sentinel
		Node *q = p->next; // remember we need a q node for when we delete p
		free(p);  // free p
		p = q;  // increment p
	}
}

void link(Node *before, Node *p, Node *after){
	p->next = after; // p next points to element that belongs after
	p->prev = before;  // p prev points to element that belongs before
	after->prev = p; // element after prev points to p
	before->next=p; // element before next points to p
}


int main() {
	Node *sentinel = malloc(sizeof(Node)); // create sentinel
	sentinel->next = sentinel; // make sentinel point to itself initially
	sentinel->prev = sentinel;

	Node *p; // pointers to nodes we will use
	int n, i; // size and counter, respectively

	printf("Enter The Desired List Size: ");
	scanf("%d", &n); // read in size of list

	for (i=0;i<n; i++){
		int option;
		p=malloc(sizeof(Node)); // put the node on the heap!!
		printf("What integer should I store? ");
		scanf("%d", &p->data); // read an integer from stdin
		printf("Enter 1 to insert data at head of list and 0 for insertion at tail: ");
		scanf("%d", &option); // read integer option

		if(sentinel->next==sentinel){ // if true, list is empty
			p->next = sentinel; // make p and sentinel point at each other
			p->prev = sentinel;
			sentinel->prev = p;
			sentinel->next = p;
		}
		else  {// list is NOT empty
			if (!option) // insert at tail
			       	link(sentinel->prev, p, sentinel);
			else
				link(sentinel, p, sentinel->next);
		}
	}
	printf("\n");
	printf("The list: \n");
	print(sentinel); // print elements in list

	printf("\n");
	printf("The reversed list: \n");
	printReversed(sentinel); // print elements in list reverse order

	freeList(sentinel); //free evrything but sentinel (free elements)
	free(sentinel); //free sentinel
	return 1;

}
