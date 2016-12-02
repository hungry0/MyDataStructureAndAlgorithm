#pragma once
#include "listnode.h"
#include "list.h"

template <typename T>
T& List<T>::operator[](Rank r) const
{
	ListNodePosi(T) p = first();

	while (r-- > 0)
	{
		p = p->succ;
	}

	return p->data;
}

