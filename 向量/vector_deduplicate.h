#pragma once
#include "vector.h"

/**************************************************************

Author：hungry
Date:2016.11.30
Description:二分查找

Analysis:
① 从后往前遍历，如果找到相同的元素，则剔除（剔除一个相当于i++）
② 如果找不到相同的元素，则i++

**************************************************************/

template <typename T>
int Vector<T>::deduplicate()	//无序数组中删除重复元素（高效）
{
	int oldSize = _size;

	Rank i = 1;

	while (i < _size)
	{
		find(_elem[i], 0, i) < 0 ? i++ : remove(i);
	}

	return oldSize - _size;
}

