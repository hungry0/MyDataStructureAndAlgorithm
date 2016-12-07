#pragma once
#include "bst.h"
#include "bst_removeat.h"
#include "bintree.h"

template <typename T>
bool BST<T>::remove(const T& e)
{
	BinNodePosi(T)& x = search(e);

	if (!x)
		return false;

	removeAt(x, _hot);

	--BinTree<T>::_size;

	BinTree<T>::updateHeightAbove(_hot);

	return true;
}

