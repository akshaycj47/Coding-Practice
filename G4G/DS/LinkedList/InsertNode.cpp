#include "LinkedList.h"

int main() {

	Node<int>* a = NULL;
	a = a->insertAtHead(a, 20);
	a = a->insertAtHead(a, 15);
	a = a->insertAtHead(a, 10);
	a = a->insertAtHead(a, 5);
	a->printList(a);

	Node<double>* b = NULL;
	b = b->insertAtTail(b, 3.33);
	b = b->insertAtTail(b, 1.25);
	b = b->insertAtHead(b, 0.99);
	b = b->insertAtTail(b, 4.78);
	b = b->insertAtHead(b, 5.61);
	b->printList(b);

	a = a->insertAfter(a, a->next->next, 12);
	a = a->insertAfter(a, a->next->next->next->next, 24);
	a->printList(a);
	return 0;
}