#pragma once
#include "binnode.h"

template<typename T>
int BinNode<T>::size()
{
	int s = 1;

	if (lc)
		s += lc->size();
	if (rc)
		s += rc->size();

	return s;
}
