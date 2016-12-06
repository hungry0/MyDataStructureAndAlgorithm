#pragma once
#include "pq_complheap.h"
#include "pq_complheap_macro.h"

template <typename T>
void PQ_ComplHeap<T>::heapify(Rank n)
{
	for (i = LastInternal(n); InHeap(n,i); i--)
	{
		percolateDown(n, i);

//		for (int k = 0; k < n; k++)
//		{
//			int kk = k;
//			while (kk > 1)
//			{
//				kk = (kk - 1) / 2;
//			}
//		}
	}
}

