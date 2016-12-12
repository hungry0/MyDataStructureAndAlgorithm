#pragma once
#include "vector.h"
#include "vector_constructor_by_copying.h"
#include "pq.h"

/**************************************************************

Author：hungry
Date:2016.12.10
Description:完全二叉树的实现

Analysis:
① 此处有Floyd算法构建优先级队列
② 上虑和下虑的排序方法

**************************************************************/

template<typename T>
class PQ_ComplHeap : public PQ<T> , public Vector<T>
{
protected:

	Rank percolateDown(Rank n, Rank i);		//下虑
	Rank percolateUp(Rank i);				//上虑
	void heapify(Rank n);					//Floyd算法建堆

public:
	PQ_ComplHeap(){}
	PQ_ComplHeap(T* A,Rank n)
	{
		copyFrom(A,0,n);
		heapify(n);
	}

	void insert(T) override;				//插入数值
	T getMax() override;					//获得最大值
	T delMax() override;					//删除最大值
};

#include "pq_complheap_heapify.h"
#include "pq_complheap_delmax.h"
#include "pq_complheap_insert.h"
#include "pq_complheap_getmax.h"
