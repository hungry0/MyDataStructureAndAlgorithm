#pragma once
#include "pq_complheap.h"
#include "pq_complheap_percolatedown.h"

template <typename T>
T PQ_ComplHeap<T>::delMax()
{
	T maxElem = _elem[0];

	_elem[0] = _elem[--_size];

	percolateDown(_size, 0);

	return maxElem;
}

