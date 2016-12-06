#pragma once
#include "pq_complheap.h"

template <typename T>
T PQ_ComplHeap<T>::getMax()
{
	return Vector<T>::_elem[0];
}

