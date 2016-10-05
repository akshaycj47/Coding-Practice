#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <class T>
class Node {
public:
	T data;																// Data
	Node<T>* next;														// Next pointer
	Node();																// Default constructor
	Node(const T& item, Node<T>* nextptr = NULL);						// Parameterized constructor
	void printList(Node<T>* head);										// Print Linked List
	Node<T>* insertAtHead(Node<T>* head, T data);						// Insert a node at head of linked list
	Node<T>* insertAtTail(Node<T>* head, T data);						// Insert a node at tail of linked list
	Node<T>* insertAfter(Node<T>* head, Node<T>* prevNode, T data);		// Insert a node after a given node
	Node<T>* deleteByKey(Node<T>* head, T key);							// Delete node at a given key
	int lengthOfList(Node<T>* head);									// Find length of linked list
	int lengthOfListRecursive(Node<T>* head);							// Find length of linked list recursively
	bool searchElement(Node<T>* head, T key);							// Find if an element is present in the list or not
	bool searchElementRecursive(Node<T>* head, T key);					// Find if an element is present in the list or not in a recursive manner
};

/**
* Default constructor which allows us to create object
* with no initialization
*/
template<class T>
Node<T>::Node() {

}

/**
* Parameterized constructor which allows us to create object
* with initialization
* @params <T> item - Data to initialize node with
* @params <Node<T>*> nextptr - Pointer to the next node
*/
template<class T>
Node<T>::Node(const T& item, Node<T>* nextptr) {

	this->data = item;
	this->next = nextptr;
}

/**
* Function that prints the entire linked list
* @params <Node<T>*> head - Head pointer of linked list
*/
template<class T>
void Node<T>::printList(Node<T>* head) {

	Node<T>* curr = head;
	while (curr != NULL) {
		std::cout << curr->data << "\t";
		curr = curr->next;
	}
	std::cout << std::endl;
}

/**
* Function that inserts a node at the head of linked list
* @params <Node<T>*> head - Head pointer of linked list
* @params <T> data - Data to be inserted at head of linked list
* @return <Node<T>*> head - Head pointer of linked list
*/
template<class T>
Node<T>* Node<T>::insertAtHead(Node<T>* head, T data) {
	
	Node<T>* curr = new Node(data, head);
	return curr;
}

/**
* Function that inserts a node at the tail of linked list
* @params <Node<T>*> head - Head pointer of linked list
* @params <T> data - Data to be inserted at tail of linked list
* @return <Node<T>*> head - Head pointer of linked list
*/
template<class T>
Node<T>* Node<T>::insertAtTail(Node<T>* head, T data) {

	if (head == NULL) {
		head = new Node<T>(data);
		return head;
	}
	else {
		Node<T>* temp = new Node<T>(data);
		Node<T>* curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = temp;
		return head;
	}
}

/**
* Function that inserts a node after a given node
* @params <Node<T>*> head - Head pointer of linked list
* @params <Node<T>*> prevNode - Pointer to previous node
* @params <T> data - Data to be inserted after previous node
* @return <Node<T>*> head - Head pointer of linked list
*/
template<class T>
Node<T>* Node<T>::insertAfter(Node<T>* head, Node<T>* prevNode, T data) {

	if (prevNode == NULL) {
		std::cout << "Previous node cannot be NULL" << std::endl;
		return head;
	}

	// Previous node's next pointer becomes current node's next pointer,
	// and current becomes previous node's next pointer
	Node<T>* curr = new Node<T>(data, prevNode->next);
	prevNode->next = curr;
	return head;
}

/**
* Function that deletes a node in linked list at a given key
* @params <Node<T>*> head - Head pointer of linked list
* @params <T> key - Node to be deleted from linked list
* @return <Node<T>*> head - Head pointer of linked list
*/
template<class T>
Node<T>* Node<T>::deleteByKey(Node<T>* head, T key) {

	// If the head is not present, we cannot delete anything
	if (head == NULL) {
		std::cout << "Node cannote be deleted" << std::endl;
		return head;
	}

	// If node to be deleted is the head node
	else if (head != NULL && head->data == key) {
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		return head;
	}

	// If node is to be deleted elsewhere in the list
	else {
		Node<T>* curr = head;
		while (curr->next != NULL) {
			Node<T>* nextNode = curr->next;
			if (nextNode->data == key) {
				curr->next = nextNode->next;
				delete nextNode;
				return head;
			}
			curr = nextNode;
		}
		return head;
	}
}

/**
* Function that finds length of linked list in an iterative manner
* @params <Node<T>*> head - Head pointer of linked list
* @return <int> Length of linked list
*/
template<class T>
int Node<T>::lengthOfList(Node<T>* head) {

	if (head == NULL) {
		return 0;
	}
	Node<T>* curr = head;
	int length = 1;
	while (curr->next != NULL) {
		length++;
		curr = curr->next;
	}
	return length;
}

/**
* Function that finds length of linked list using recursion
* @params <Node<T>*> head - Head pointer of linked list
* @return <int> Length of linked list
*/
template<class T>
int Node<T>::lengthOfListRecursive(Node<T>* head) {

	if (head == NULL) {
		return 0;
	}
	return 1 + lengthOfListRecursive(head->next);
}

/**
* Function that checks whether an element is present in 
* linked list or not (in an iterative manner)
* @params <Node<T>*> head - Head pointer of linked list
* @params <T> key - Value to be searched in linked list
* @return <bool> If element is found, return true
* If element is not found, return false
*/
template<class T>
bool Node<T>::searchElement(Node<T>* head, T key) {

	if (head == NULL) {
		return false;
	}
	Node<T>* curr = head;
	while (curr != NULL) {
		if (curr->data == key) {
			return true;
		}
		curr = curr->next;
	}
	return false;
}

/**
* Function that checks whether an element is present in
* linked list or not (in a recursive manner)
* @params <Node<T>*> head - Head pointer of linked list
* @params <T> key - Value to be searched in linked list
* @return <bool> If element is found, return true
* If element is not found, return false
*/
template<class T>
bool Node<T>::searchElementRecursive(Node<T>* head, T key) {

	if (head == NULL) {
		return false;
	}
	if (head->data == key) {
		return true;
	}
	return searchElementRecursive(head->next, key);
}

#endif // LINKEDLIST_H