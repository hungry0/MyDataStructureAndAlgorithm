#pragma once
#include "vector.h"
#include "vector_constructor_by_copying.h"

template <typename T>
Vector<T>& Vector<T>::operator= (Vector<T> const& V)
{
	if (_elem)
		delete[]_elem;

	copyFrom(V._elem, 0, V._size);

	return *this;
}


