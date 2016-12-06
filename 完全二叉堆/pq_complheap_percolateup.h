#pragma once
#include "pq_complheap.h"
#include "pq_complheap_macro.h"

template <typename T>
Rank PQ_ComplHeap<T>::percolateUp(Rank i)
{
	while (ParentValid(i))
	{
		Rank j = Parent(i);

		if (lt(_elem[i], _elem[j]))
			break;

		std::swap(_elem[i], _elem[j]);

		i = j;
	}

	return i;
}

