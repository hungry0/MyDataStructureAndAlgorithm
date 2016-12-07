#pragma once
#include "binnode.h"
#include "bintree.h"

template <typename T>
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>* & S)
{
	if (x->lc = S->_root)
		x->lc->parent = x;

	_size += S->_size;

	this.updateHeightAbove(x);

	S->_root = nullptr;

	S->_size = 0;

	//	release(S);

	S = nullptr;

	return x;
}

template <typename T>
BinNode<T>* BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>* & S)
{
	if (x->rc = S->_root)
		x->rc->parent = x;

	_size += S->size();

	this.updateHeightAbove(x);

	S->_root = nullptr;

	S->_size = 0;

	//	relase(S);

	S = nullptr;

	return x;
}
