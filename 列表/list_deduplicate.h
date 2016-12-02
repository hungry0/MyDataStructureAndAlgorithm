#pragma once
#include "list.h"

/*
 *	从前往后遍历，不过是从该元素前面的元素中寻找重复的
 */

template <typename T>
int List<T>::deduplicate()
{
	if (_size < 2)
		return;

	int oldSize = _size;

	ListNodePosi(T) p = header;

	Rank r = 0;

	while (trailer != (p = p->succ))
	{
		ListNodePosi(T) q = find(p->data, r, p);	//此处find是从p的r个前驱中查找data

		q ? remove(q) : r++;
	}

	return oldSize - _size;
}

