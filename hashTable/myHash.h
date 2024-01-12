#ifndef MYHASH_H
#define MYHASH_H
#include <string>

using std::string;

template <class T>
class myHash{
private:
    const static int HASHSIZE = 266333;
    T* hash;
    int size;
public:
    int compares = 0;
    myHash();
    ~myHash();
    void insert(T item);
    bool find(T item);
    int getSize() {
        return size;
    }
    int findHash(string word);
};
#endif