#pragma once
#include "pq_complheap.h"
#include "pq_complheap_macro.h"

template <typename T>
Rank PQ_ComplHeap<T>::percolateDown(Rank n, Rank i)
{
	Rank j;

	while (i != (j = ProperParent(_elem,n,i)))
	{
		std::swap(_elem[i], _elem[j]);

		i = j;
	}

	return i;
}
 
