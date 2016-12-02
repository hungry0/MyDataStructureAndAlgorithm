#pragma once
#include "listnode.h"
#include "list.h"
#include "listnode_insert_as_pred.h"	
#include "listnode_insert_as_succ.h"

template <typename T>
ListNode<T>* List<T>::insertAsFirst(T const& e)
{
	_size++;

	return header->insertAsSucc(e);
}

template <typename T>
ListNode<T>* List<T>::insertAsLast(T const& e)
{
	_size++;

	return trailer->insertAsPred(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertA(ListNodePosi(T) p, T const& e)
{
	_size++;

	return p->insertAsSucc(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertB(ListNodePosi(T) p, T const& e)
{
	_size++;
	
	return p->insertAsPred(e);
}


