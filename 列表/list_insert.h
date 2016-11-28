#pragma once
#include "listnode.h"
#include "list.h"

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
ListNode<T>* List<T>::insertA(ListNode<T>* p, T const& e)
{
	_size++;

	return p->insertAsSucc(e);
}

template <typename T>
ListNode<T>* List<T>::insertB(ListNode<T>* p, T const& e)
{
	_size++;
	
	return p->insertAsPred(e);
}


