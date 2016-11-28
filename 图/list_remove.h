#pragma once
#include "list.h"

template <typename T>
T List<T>::remove(ListNode<T>* p)
{
	T e = p->data;

	p->pred->succ = p->succ;
	p->succ->pred = p->pred;

	delete p;

	_size--;

	return e;
}

