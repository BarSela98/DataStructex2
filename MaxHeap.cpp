#include "MaxHeap.h"

void MaxHeap::FixMaxHeap(int node)
{
    int max;
    int left = Left(node);
    int right = Right(node);

    if (left < heapSize && data[left]->getPriority() > data[node]->getPriority())
        max = left;
    else
        max = node;
    if (right < heapSize && data[right]->getPriority() > data[node]->getPriority())
        max = right;

    if (max != node)
    {
        Pair* temp = data[max];
        data[max] = data[node];
        data[node] = temp;
        //swap(data[node], data[max]);
        FixMaxHeap(max);
    }
}

Pair MaxHeap::deleteMax()
{
    if (heapSize < 1)
    {
        //cout << "could not delete item";
        return Pair();
    }

    Pair max = *data[0];
    heapSize--;
    data[0] = data[heapSize];
    data[heapSize] = nullptr;
    if (heapSize > 0)
    {
        data[0]->setIndex(0);
        FixMaxHeap(0);
    }
    return max;
}

void MaxHeap::Insert(Pair* item)
{
    if (heapSize == maxSize)
    {
        //cout << "overflow: could not insert item";
        return;
    }
    int i = heapSize;
    heapSize++;

    while (i > 0 && data[Parent(i)]->getPriority() < item->getPriority())
    {
        data[i] = data[Parent(i)];
        data[i]->setIndex(i);
        i = Parent(i);
    }
    item->setIndex(i);
    data[i] = item; 
}

Pair& MaxHeap::Max() {
    return *data[0];
}

Pair MaxHeap::Delete(int index)
{
    int left = Left(index);
    int right = Right(index);
    int parent = Parent(index);


    Pair val = *data[index];
    delete data[index];
    data[index] = data[heapSize - 1];
    data[heapSize - 1] = nullptr;
    heapSize--;
    if (index == heapSize)
        return val;

    data[index]->setIndex(index);


     if (Parent(index) && data[index]->getPriority() > data[parent]->getPriority()) /// up
    {
        ////
        int i = heapSize;
        heapSize++;

        while (i > 0 && data[Parent(i)]->getPriority() < data[index]->getPriority())
        {
            data[i] = data[Parent(i)];
            data[i]->setIndex(i);
            i = Parent(i);
        }
        data[i] = data[index];
        data[i]->setIndex(i);

        ////
    }
    else //down
    {
        FixMaxHeap(index);
    }
    return val;
}