#pragma once
#include "list.h"
#include "list_clear.h"

template <typename T>
List<T>::~List()
{
	clear();

	delete trailer;
	delete header;
}

