#include <iostream>
#include "List.h"
#include "Node.h"

using namespace std;

template <class T>
List<T>::List() {
	head = nullptr;
	current = nullptr;
	tmp = nullptr;
	deletion = nullptr;
	size = 0;
    compares = 0;
}

template <class T>
List<T>::~List() {
	current = head;
	while (current != nullptr) {
		delete current;
		current = current->next;
	}
}

template <class T>
void List<T>::addNode(T item) {
	Node<T>* n = new Node<T>(item);
	n->data = item;
	n->next = head;
	head = n;
	size++;
}

template <class T>
void List<T>::remove() {
	Node<T>* n = nullptr;
	if (head != nullptr) {
		n = head;
		head = n->next;
		cout << "Deleted: " << n->data << endl;
		delete n;
		size--;
	}
}
template <class T>
void List<T>::printList() {
	current = head;
	while (current != nullptr) {
		cout << current->data << endl;
		current = current->next;
	}
}

template <class T>
bool List<T>::find(T item) {
    Node<T>* n = nullptr;
    for (n = head; n != nullptr; n = n->next){
        if (n->data == item) {
            return true;
        }
    }
    return false;
}

template <class T>
int List<T>::getSize() {
	return size;
}

template <class T>
Node<T>* List<T>::getHead() {
	return head;
}