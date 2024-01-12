#include "myHash.h"

template <class T>
myHash<T>::myHash() {
    hash = new T[HASHSIZE];
    size = 0;
    for (int i = 0; i < HASHSIZE; i++) {
        hash[i] = "";
    }
}

template <class T>
void myHash<T>::insert(T item) {
    int key = findHash(item);
    if (hash[key].empty()) {
        hash[key] = item;
    } else {
        bool entered = false;
        while (!entered) {
            key++;
            if (hash[key].empty()) {
                hash[key] = item;
                entered = true;
            }
            if (key == HASHSIZE) {
                key = 0;
            }
        }
    }
    size++;
}

template <class T>
bool myHash<T>::find(T item) {
    int key = findHash(item);
    if (hash[key].compare(item) == 0) {
        compares++;
        return true;
    } else if (hash[key].empty()) {
        compares++;
        return false;
    } else {
        bool found = false;
        while (!found) {
            key++;
            compares++;
            if (hash[key].compare(item) == 0) {
                return true;
            } else if (hash[key].empty()) {
                return false;
            }
            if (key == HASHSIZE) {
                key = 0;
            }
        }
    }
    return false;
}

template <class T>
int myHash<T>::findHash(string word) {
    int value = 0;
    for (int i = 0; i < word.size(); i++) {
        value += ((int) word.at(i) * (i + 1)) * 257;
    }
    return value % HASHSIZE;
}

template <class T>
myHash<T>::~myHash() {
    delete [] hash;
}
