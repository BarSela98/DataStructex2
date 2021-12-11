#pragma once
#include "MaxHeap.h"
#include "MInHeap.h"
#include <string>

class heapsManager
{
private:
	MaxHeap lowestMax;
	MaxHeap highestMax;
	MinHeap lowestMin;
	MinHeap highestMin;
public:
	heapsManager(int size) :lowestMax(size), highestMax(size), lowestMin(size), highestMin(size) {}
	Pair& Max();
	Pair DeleteMax();
	Pair& Min();
	Pair DeleteMin();
	void CreateEmpty();
	void Insert(int p , string val);
	Pair& Median();



};

