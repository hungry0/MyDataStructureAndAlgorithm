#pragma once
#include "vector_expand.h"

template <typename T>
T& Vector<T>::operator[](Rank i) const
{
	return _elem[i];
}

