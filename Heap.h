
#ifndef UNTITLED_HEAP_H
#define UNTITLED_HEAP_H
#define SIZE 100

#include "Pair.h"
class Heap {
protected:
    Pair* data[SIZE];
    int maxSize;
    int heapSize;
    int allocated;
    static int Left(int node);
    static int Right(int node);
    static int Parent(int node);
    static void swap(Pair& p1 , Pair& p2);

public:
Heap(int max);
~Heap();
virtual void Insert(Pair* item) = 0;
int getSize()const { return heapSize; }

/*
void print() {
    for (int i = 0; i < heapSize; i++)
    {
        cout << "(" << *data[i] << ") ";
    }
}*/

};


#endif //UNTITLED_HEAP_H



