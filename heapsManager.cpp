#include "heapsManager.h"

void heapsManager::CreateEmpty()
{

}

Pair& heapsManager::Max()
{
	if (highestMax.getSize() == 0)
		return lowestMax.Max();
	return highestMax.Max();
}
Pair& heapsManager::Min()
{
	return lowestMin.Min();
}
Pair& heapsManager::Median()
{
	return lowestMax.Max();
}

Pair heapsManager::DeleteMin()
{
	Pair y_max = lowestMax.deleteMax();
	Pair y_min = lowestMin.Delete(y_max.getPointer()->getIndex());

	if (highestMax.getSize() != lowestMax.getSize())
	{
		Pair* z_min = new Pair(highestMin.deleteMin());
		Pair* z_max = new Pair(highestMax.Delete(z_min->getPointer()->getIndex()));
		z_min->setPointer(z_max);
		z_max->setPointer(z_min);

		lowestMax.Insert(z_max);
		lowestMin.Insert(z_min);
	}

	return y_max;
}




Pair heapsManager::DeleteMax()
{
	if (highestMax.getSize() == 0)
	{
		Pair y_max = lowestMax.deleteMax();
		Pair y_min = lowestMin.Delete(y_max.getPointer()->getIndex());
		return y_max;
	}
	Pair y_max = highestMax.deleteMax();
	Pair y_min = highestMin.Delete(y_max.getPointer()->getIndex());

	if (highestMax.getSize()+2 == lowestMax.getSize())
	{
		Pair* z_max = new Pair (lowestMax.deleteMax());
		Pair* z_min = new Pair(lowestMin.Delete(z_max->getPointer()->getIndex()));
		z_min->setPointer(z_max);
		z_max->setPointer(z_min);

		highestMax.Insert(z_max);
		highestMin.Insert(z_min);
	}

	return y_max;
}

void heapsManager::Insert(int p, string val)
{
	Pair* x_max = new Pair(p, val);
	Pair* x_min = new Pair(p, val,x_max);

	x_max->setPointer(x_min);

	if (highestMax.getSize() == 0 && lowestMax.getSize() == 0)
	{
		lowestMax.Insert(x_max);
		lowestMin.Insert(x_min);
	}

	else if (p > Median().getPriority())
	{
		highestMax.Insert(x_max);
		highestMin.Insert(x_min);

		if (highestMax.getSize() == lowestMax.getSize())
			return;

		else
		{
			Pair* y_min = new Pair(highestMin.deleteMin());
			Pair* y_max = new Pair(highestMax.Delete(y_min->getPointer()->getIndex()));
			y_min->setPointer(y_max);
			y_max->setPointer(y_min);
			lowestMax.Insert(y_max);
			lowestMin.Insert(y_min);
		}
	}

	else {
		lowestMax.Insert(x_max);
		lowestMin.Insert(x_min);

		if (highestMax.getSize()+1 == lowestMax.getSize())
			return;
		else 
		{
			Pair* z_min = new Pair(lowestMax.deleteMax());
			Pair* z_max = new Pair(lowestMin.Delete(z_min->getPointer()->getIndex()));
			z_min->setPointer(z_max);
			z_max->setPointer(z_min);

			highestMax.Insert(z_max);
			highestMin.Insert(z_min);
		}
	}
}