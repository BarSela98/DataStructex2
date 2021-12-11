
#ifndef UNTITLED_MAXHEAP_H
#define UNTITLED_MAXHEAP_H

#include "Heap.h"
class MaxHeap : public Heap
{
public:
    MaxHeap(int size) :Heap(size) {};
    Pair& Max();
    Pair deleteMax();
    void FixMaxHeap(int node);
    virtual void Insert(Pair* item);
    Pair Delete(int index);
};



#endif //UNTITLED_MAXHEAP_H
