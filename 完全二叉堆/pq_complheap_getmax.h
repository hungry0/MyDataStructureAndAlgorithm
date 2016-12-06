#pragma once
#include "pq_complheap.h"

template <typename T>
T PQ_ComplHeap<T>::getMax()
{
	return _elem[0];
}

