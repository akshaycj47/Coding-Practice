#include "LinkedList.h"

int main() {

	Node<int>* a = NULL;
	a = a->insertAtHead(a, 20);
	a = a->insertAtHead(a, 15);
	a = a->insertAtHead(a, 10);
	a = a->insertAtHead(a, 5);
	a = a->insertAtTail(a, 90);
	a = a->insertAfter(a, a->next->next, 12);
	a = a->insertAfter(a, a->next->next->next->next, 24);
	a->printList(a);
	std::cout << "Deleting 12" << std::endl;
	a = a->deleteByKey(a, 12);
	a->printList(a);
	std::cout << "Deleting 90" << std::endl;
	a = a->deleteByKey(a, 90);
	a->printList(a);
	std::cout << "Deleting 5" << std::endl;
	a = a->deleteByKey(a, 5);
	a->printList(a);
	std::cout << "Deleting 17" << std::endl;
	a = a->deleteByKey(a, 17);
	a->printList(a);
	return 0;
}