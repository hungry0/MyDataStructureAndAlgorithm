#pragma once
#include "vector.h"

template <typename T>
void Vector<T>::copyFrom(T const* A, Rank io, Rank hi)
{
	_elem = new T[_capacity = (hi - io) << 1];	//容量是当前数值的2倍
	_size = 0;

	while (io < hi)
	{
		_elem[_size++] = A[io++];
	}
}

