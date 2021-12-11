//
// Created by bar sela on 08/12/2021.
//

#ifndef UNTITLED_MINHEAP_H
#define UNTITLED_MINHEAP_H


#include "Heap.h"
class MinHeap : public Heap
{
public:
    MinHeap(int size) :Heap(size) {};
    Pair& Min();
    Pair deleteMin();
    void FixMinHeap(int node);
    virtual void Insert(Pair* item);
    Pair Delete(int index);

};


#endif //UNTITLED_MINHEAP_H
