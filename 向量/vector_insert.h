#pragma once
#include "vector.h"

template <typename T>
Rank Vector<T>::insert(Rank r, T const& e)
{
	expand();

	for (int i = _size; i > r; i--)
		_elem[i] = _elem[i - 1];

	_elem[r] = e;
	_size++;
	
	return r;
}

