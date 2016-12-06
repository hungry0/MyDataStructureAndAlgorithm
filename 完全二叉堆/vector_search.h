#pragma once
#include "vector.h"
#include "vector_search_binary_a.h"

template <typename T>
Rank Vector<T>::search(T const& e, Rank io, Rank hi)
{
	return Bin_Search(_elem, e, io, hi);
}

