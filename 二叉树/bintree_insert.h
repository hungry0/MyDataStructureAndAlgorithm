#pragma once
#include "bintree.h"
#include "binree_updateheight.h"

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRoot(T const& e)
{
	_size = 1;
	return _root = new BinNode<T>(e);
}


template <typename T>
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const& e)
{
	_size++;

	x->insertAsLC(e);

	this->updateHeightAbove(x);

	return x->lc;
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const& e)
{
	_size++;

	x->insertAsRC(e);

	this->updateHeightAbove(x);

	return x->rc;
}
