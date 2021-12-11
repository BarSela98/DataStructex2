//
// Created by bar sela on 08/12/2021.
//

#include "Heap.h"
Heap::Heap(int max) {
    maxSize = max;
    heapSize = 0;
    allocated = 1;
}
Heap::~Heap() {
    for (int i = 0; i < heapSize; i++)
    {
        delete data[i];
    }
}
int Heap::Parent(int node){
    return (node-1)/2;
}
int Heap::Left(int node){
    return (2*node+1);
}
int Heap::Right(int node){
    return (2*node+2);
}
void Heap::swap(Pair& p1 , Pair& p2)
{
    Pair temp;
    temp.setData(p1.getData());
    temp.setPriority(p1.getPriority());
    temp.setIndex(p1.getIndex());

    p1.setData(p2.getData());
    p1.setPriority(p2.getPriority());
    p1.setIndex(p2.getIndex());

    p2.setData(temp.getData());
    p2.setPriority(temp.getPriority());
    p2.setIndex(temp.getIndex());
}