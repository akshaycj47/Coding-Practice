#include "LinkedList.h"

int main() {
	
	Node<char>* p = new Node<char>('A');
	Node<char>* q = new Node<char>('B', p);
	std::cout << "q_data: " << q->data << std::endl;
	std::cout << "p_data: " << q->next->data << std::endl;

	Node<int>* c = new Node<int>(3);
	Node<int>* b = new Node<int>(2, c);
	Node<int>* a = new Node<int>(1, b);
	a->printList(a);
	b->printList(b);
	c->printList(c);
	Node<int>* d = NULL;
	d->printList(d);
	return 0;
}