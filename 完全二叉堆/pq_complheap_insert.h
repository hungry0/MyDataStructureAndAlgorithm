#pragma once
#include "pq_complheap.h"

template <typename T>
void PQ_ComplHeap<T>::insert(T e)
{
	Vector<T>::insert(e);

	percolateUp(Vector<T>::_size - 1);
}

