#pragma once
#include "list.h"

template <typename T>
ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p) const
{
	while (n--)
	{
		if (e == (p = p->pred)->data)
			return p;
	}

	return nullptr;
}

