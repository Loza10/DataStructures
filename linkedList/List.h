#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include "string.h"

template <class T>
class List {
private:
	int size;
	Node<T>* head;
	Node<T>* current;
	Node<T>* tmp;
	Node<T>* deletion;
public:
    int compares;
	List();
	~List();
	void addNode(T item);
	void remove();
	void printList();
    bool find(T item);
	int getSize();
	Node<T>* getHead();
};


#endif
