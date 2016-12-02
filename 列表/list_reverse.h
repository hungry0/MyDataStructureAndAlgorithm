#pragma once
#include "list.h"
#include <set>

/*
 * 置反方法一
 */

template <typename T>
void List<T>::reverse() const
{
	if (_size < 2)
		return;

	ListNodePosi(T) h = header;
	ListNodePosi(T) t = trailer;
	

	for (int i = 1; i < _size; i += 2)
	{
		std::swap((h = h->succ)->data, (t = t->pred)->data);
	}
}

