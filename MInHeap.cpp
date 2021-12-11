#include "MinHeap.h"
void MinHeap::FixMinHeap(int node)
{
    int min;
    int left = Left(node);
    int right = Right(node);

    if (left < heapSize && data[left]->getPriority() < data[node]->getPriority())
        min = left;
    else
        min = node;
    if (right < heapSize && data[right]->getPriority() < data[node]->getPriority())
        min = right;

    if (min != node)
    {
        Pair* temp = data[min];
        data[min] = data[node];
        data[node] = temp;
       // swap(data[node], data[min]);
        FixMinHeap(min);
    }
}

Pair MinHeap::deleteMin()
{
    if (heapSize < 1)
    {
       // cout << "could not delete item";
        return Pair();
    }

    Pair min = *data[0];
    heapSize--;
    data[0] = data[heapSize];
    data[heapSize] = nullptr;
    if (heapSize > 0)
    {
        data[0]->setIndex(0);
        FixMinHeap(0);
    }
    return min;
}

void MinHeap::Insert(Pair* item)
{
    if (heapSize == maxSize)
    {
       // cout << "overflow: could not insert item";
        return;
    }
    int i = heapSize;
    heapSize++;

    while (i > 0 && data[Parent(i)]->getPriority() > item->getPriority())
    {
        data[i] = data[Parent(i)];
        data[i]->setIndex(i);
        i = Parent(i);
    }
    item->setIndex(i);
    data[i] = item;
}

Pair& MinHeap::Min() {
    return *data[0];
}


Pair MinHeap::Delete(int index)
{
    Pair val = *data[index];
    delete data[index];
    data[index] = data[heapSize - 1];
    data[heapSize - 1] = nullptr;
    heapSize--;
    if (index == heapSize)
        return val;

    data[index]->setIndex(index);

  /*  if (data[index]->getPriority() < data[Right(index)]->getPriority() &&
        data[index]->getPriority() < data[Left(index)]->getPriority() &&
        data[index]->getPriority() >= data[Parent(index)]->getPriority())
        return val; //finish

    else */
        
        if (data[index]->getPriority() < data[Parent(index)]->getPriority()) /// up
    {
        ////
        int i = heapSize;
        heapSize++;

        while (i > 0 && data[Parent(i)]->getPriority() > data[index]->getPriority())
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
        FixMinHeap(index);
    }
    return val;
}
