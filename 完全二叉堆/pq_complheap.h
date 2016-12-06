#pragma once
#include "vector.h"
#include "vector_constructor_by_copying.h"
#include "pq.h"

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

	void insert(T);
	T getMax();
	T delMax();
};
