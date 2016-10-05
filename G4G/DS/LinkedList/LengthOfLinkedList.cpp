#include "LinkedList.h"
#include <cassert>
#include <string>

int main() {

	Node<int>* a = NULL;
	a = a->insertAtHead(a, 20);
	a = a->insertAtHead(a, 15);
	a = a->insertAtHead(a, 10);
	a = a->insertAtHead(a, 5);
	a = a->insertAtTail(a, 90);
	a = a->insertAfter(a, a->next->next, 12);
	a = a->insertAfter(a, a->next->next->next->next, 24);
	assert(a->lengthOfList(a) == 7);
	assert(a->lengthOfListRecursive(a) == 7);

	Node <double>* b = NULL;
	b = b->insertAtTail(b, 3.33);
	b = b->insertAtTail(b, 1.25);
	b = b->insertAtHead(b, 0.99);
	b = b->insertAtTail(b, 4.78);
	b = b->insertAtHead(b, 5.61);
	assert(b->lengthOfList(b) == 5);
	assert(b->lengthOfListRecursive(b) == 5);

	Node<char>* c = NULL;
	assert(c->lengthOfList(c) == 0);
	assert(c->lengthOfListRecursive(c) == 0);

	Node<std::string>* d = NULL;
	d = d->insertAtTail(d, "Akshay");
	assert(d->lengthOfList(d) == 1);
	assert(d->lengthOfListRecursive(d) == 1);
}