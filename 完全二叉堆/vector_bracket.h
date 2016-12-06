#pragma once
#include "vector.h"

template <typename T>
T& Vector<T>::operator[](Rank i) const
{
	return _elem[i];
}

