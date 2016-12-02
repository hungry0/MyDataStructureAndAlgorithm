#pragma once
#include "list.h"
#include "list_copynodes.h"

template <typename T>
List<T>::List(List<T> const& L)
{
	copyNodes(L, L._size);
}

template <typename T>
List<T>::List(List<T> const& L, Rank r, int n)
{
	copyNodes(L[r], n);
}

template <typename T>
List<T>::List(ListNodePosi(T) p, int n)
{
	copyNodes(p, n);
}




