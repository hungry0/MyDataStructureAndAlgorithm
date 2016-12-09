#pragma once
#include "pq_complheap.h"
#include "pq_complheap_macro.h"
#include "pq_complheap_percolatedown.h"

template <typename T>
void PQ_ComplHeap<T>::heapify(Rank n)				//从最末端的开始建立，保证建立父顺序时子已经有序
{
	for (Rank i = LastInternal(n); InHeap(n,i); i--)
	{
		percolateDown(n, i);
	}
}

