#include "binaryTree.h"

template <class T>
binaryTree<T>::binaryTree(){
    root = nullptr;
    compares = 0;
    size = 0;
}

template <class T>
binaryTree<T>::~binaryTree(){
    clear(root);
}

template <class T>
Node<T>* binaryTree<T>::find(T item) {
    return find(item, root);
}
template <class T>
void binaryTree<T>::insert(T item) {
    insert(item, root);
}
template <class T>
Node<T>* binaryTree<T>::find(T x, Node<T>* t){
    if (t == nullptr) {
        return nullptr;
    } else if (x.compare(t->data) < 0){
        compares++;
        return find(x, t->left);
    } else if (x.compare(t->data) > 0) {
        compares++;
        return find(x, t->right);
    } else {
        return t;
    }
}
template <class T>
Node<T>* binaryTree<T>::findMin(Node<T>* t) {
    if (t == nullptr) {
        return nullptr;
    } else if (t->left == nullptr) {
        return t;
    } else {
        return findMin(t->left);
    }
}
template <class T>
Node<T>* binaryTree<T>::findMax(Node<T>* t) {
    if (t == nullptr){
        return nullptr;
    } else if (t->right == nullptr) {
        return t;
    } else {
        return findMin(t->right);
    }
}
template <class T>
void binaryTree<T>::insert(T item, Node<T> *&t) {
    if (t == nullptr) {
        size++;
        t = new Node<T>(item);
    } else if(item.compare(t->data) < 0) {
        insert(item, t->left);
    } else if (item.compare(t->data) > 0) {
        insert(item, t->right);
    } else {
        ;
    }
}
template <class T>
void binaryTree<T>::remove(T item, Node<T> *&t){
    if (t == nullptr) {
        return;
    }
    if (item.compare(t->data) < 0) {
        remove(item, t->left);
    } else if (item.compare(t->data) > 0) {
        remove(item, t->right);
    } else {
        Node<T> oldNode;
        if (t->left == nullptr) {
            oldNode = t;
            t = t->right;
            delete oldNode;
            return;
        } else if (t->right == nullptr) {
            oldNode = t;
            t = t->left;
            delete oldNode;
            return;
        }
        oldNode = findMin(t->right);
        t->data = oldNode->data;
        remove(t->data, t->right);
    }
}
template <class T>
void binaryTree<T>::clear(Node<T> *t){
    if (t == nullptr) {
        return;
    } else {
        clear(t->left);
        clear(t->right);
        delete(t);
    }
}
template <class T>
int binaryTree<T>::getSize() {
    return size;
}