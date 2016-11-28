#pragma once

#include "list.h"
#include <locale.h>

template <typename T>
void List<T>::init()
{
	header = new ListNode<T>();
	trailer = new ListNode<T>();

	header->succ = trailer;
	header->pred = NULL;

	trailer->pred = header;
	trailer->succ = NULL;

	_size = 0;
}

