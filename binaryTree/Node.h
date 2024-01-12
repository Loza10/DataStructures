#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
public:
	T data;
    Node<T>* left;
    Node<T>* right;
	Node() {
        left = nullptr;
        right = nullptr;
	}
	Node(T item) {
		data = item;
        left = nullptr;
        right = nullptr;
	}
};
#endif