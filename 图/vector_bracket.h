#pragma once

template <typename T>
T& Vector<T>::operator[](Rank i) const
{
	return _elem[i];
}

