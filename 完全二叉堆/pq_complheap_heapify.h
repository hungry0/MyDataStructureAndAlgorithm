#pragma once
#include "pq_complheap.h"
#include "pq_complheap_macro.h"
#include "pq_complheap_percolatedown.h"

template <typename T>
void PQ_ComplHeap<T>::heapify(Rank n)
{
	for (Rank i = LastInternal(n); InHeap(n,i); i--)
	{
		percolateDown(n, i);
	}
}

