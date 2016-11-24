#pragma once
#include "vector.h"

/*
	二分查找，前提是排好序的vector
*/

template<typename T>
static Rank Bin_Search(T* A, T const& e, Rank lo, Rank hi)
{
	while (lo < hi)
	{
		Rank mi = (lo + hi) >> 1;

		if (e < A[mi])					//[lo,mi)
			hi = mi;
		else if (e > A[mi])				//(mi,hi)
			lo = mi + 1;
		else
			return mi;
	}
}
