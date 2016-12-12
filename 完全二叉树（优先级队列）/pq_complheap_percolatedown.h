#pragma once
#include "pq_complheap.h"
#include "pq_complheap_macro.h"

/**************************************************************

Author：hungry
Date:2016.12.10
Description:下滤操作

Analysis:
① 调用ProperParent找到元素值最大的元素的下标
② 交换两元素，把当前元素赋值给i
③ 直到i = j为止，即i为当前三元素中最大值的下标

**************************************************************/

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
 
