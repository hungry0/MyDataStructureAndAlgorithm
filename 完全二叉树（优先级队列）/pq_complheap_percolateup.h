#pragma once
#include "pq_complheap.h"
#include "pq_complheap_macro.h"

/**************************************************************

Author：hungry
Date:2016.12.10
Description:上滤操作

Analysis:
① 只和父节点比较
② 直到小于父节点为止，否则交换两元素的值

**************************************************************/

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

