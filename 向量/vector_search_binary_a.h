#pragma once
#include "vector.h"

/**************************************************************

Author：hungry
Date:2016.11.30
Description:二分查找

Analysis:
① 对[lo,hi)区间的元素进行二分查找
② 首先取这两个秩的中间元素（如果是奇数个则正好为中间元素，如果是偶数个，则为算得取中数的后面一个元素）
③ 如果待查找元素小于中间元素，则将区间缩小到[lo,mi)
④ 如果待查找元素大于中间元素，则将区间缩小到(mi,hi)
⑤ 如果相等，则直接返回该秩
⑥ 查找失败，返回-1

**************************************************************/

template<typename T>
static Rank Bin_Search(T* A, T const& e, Rank lo, Rank hi)
{
	while (lo < hi)
	{
		Rank mi = (lo + hi) >> 1;		//取中

		if (e < A[mi])					//[lo,mi)
			hi = mi;
		else if (e > A[mi])				//(mi,hi)
			lo = mi + 1;
		else
			return mi;
	}

	return -1;							//找不到则返回-1
}
