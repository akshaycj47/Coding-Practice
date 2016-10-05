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
	assert(a->searchElement(a, 90) == true);
	assert(a->searchElementRecursive(a, 56) == false);

	Node <double>* b = NULL;
	b = b->insertAtTail(b, 3.33);
	b = b->insertAtTail(b, 1.25);
	b = b->insertAtHead(b, 0.99);
	b = b->insertAtTail(b, 4.78);
	b = b->insertAtHead(b, 5.61);
	assert(b->searchElement(b, 1.75) == false);
	assert(b->searchElementRecursive(b, 3.33) == true);

	Node<char>* c = NULL;
	assert(c->searchElement(c, 'e') == false);
	assert(c->searchElement(c, 'a') == false);

	Node<std::string>* d = NULL;
	d = d->insertAtTail(d, "Akshay");
	assert(d->searchElement(d, "Akshay") == true);
	assert(d->searchElement(d, "Sawant") == false);
}