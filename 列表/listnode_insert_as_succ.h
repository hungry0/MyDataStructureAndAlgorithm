#pragma once
#include "listnode.h"

template <typename T>
ListNode<T>* ListNode<T>::insertAsSucc(T const& e)
{
	ListNodePosi(T) x = new ListNode(e, this,succ);

	succ->pred = x;

	succ = x;
}

