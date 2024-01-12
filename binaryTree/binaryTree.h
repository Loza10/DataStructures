#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Node.h"
#include <string.h>

template <class T>
class binaryTree{
private:
    int size;
    Node<T>* root;
    void insert(T item, Node<T> *&t);
    void remove(T item, Node<T> *&t);
    Node<T>* find(T x, Node<T>* t);
public:
    long long int compares;
    binaryTree();
    ~binaryTree();
    void remove(T item);
    void insert(T item);
    void clear(Node<T>* t);
    int getSize();
    Node<T>* find(T item);
    Node<T>* findMin(Node<T>* t);
    Node<T>* findMax(Node<T>* t);
};
#endif
