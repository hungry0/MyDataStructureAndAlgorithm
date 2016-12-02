#pragma once
#include "list.h"
#include "list_remove.h"

template <typename T>
int List<T>::clear()
{
	int oldSize = _size;

	while (_size > 0)
		remove(first());

	return oldSize;
}

