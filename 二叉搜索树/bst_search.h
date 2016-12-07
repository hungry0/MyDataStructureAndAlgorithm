#pragma once
#include "bst.h"
#include "bst_searchin_recursive.h"

template <typename T>
BinNode<T>*& BST<T>::search(const T& e)
{
	return searchIn(BinTree<T>::_root, e, _hot);
}


