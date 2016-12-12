#pragma once
#include "pq_complheap.h"
#include "pq_complheap_macro.h"
#include "pq_complheap_percolatedown.h"

/**************************************************************

Author：hungry
Date:2016.12.10
Description:建立优先级队列

Analysis:
① 找到末节点的父节点，开始建立规则
② 节点自减一，即上一颗子树

**************************************************************/

template <typename T>
void PQ_ComplHeap<T>::heapify(Rank n)				//从最末端的开始建立，保证建立父顺序时子已经有序
{
	for (Rank i = LastInternal(n); InHeap(n,i); i--)
	{
		percolateDown(n, i);
	}
}

