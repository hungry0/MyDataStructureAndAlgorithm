#pragma once
#include "pq_complheap.h"
#include "pq_complheap_percolatedown.h"

/**************************************************************

Author：hungry
Date:2016.12.10
Description:删除最大值

Analysis:
① 最大值的秩是0
② 将最末节点放在0的位置
③ 执行下滤操作，将该节点放置到合适的位置

**************************************************************/

template <typename T>
T PQ_ComplHeap<T>::delMax()
{
	T maxElem = _elem[0];

	_elem[0] = _elem[--_size];

	percolateDown(_size, 0);

	return maxElem;
}

