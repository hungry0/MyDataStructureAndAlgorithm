#pragma once
#include "vector.h"

template <typename T>
Rank Vector<T>::find(T const& e, Rank io, Rank hi) const
{
	while (io < hi-- && (e != _elem[hi]));

	return hi;

	//Ê§°ÜÊ±£¬·µ»Ølo-1
}

