#pragma once
#include "vector.h"

/**************************************************************

Author：hungry
Date:2016.11.30
Description:已排序向量中相同元素的剔除

Analysis:
① 首先指定两个秩，一个是从前往后遍历的秩，一个是指向不同元素末位的秩
② 当碰到相同元素时，j一直往后遍历，而i原地不同
③ 直到不相等时，把j的元素放到++i的位置

**************************************************************/

template <typename T>
int Vector<T>::uniquify()
{
	Rank i = 0;
	Rank j = 0;

	while (++j < _size)
	{
		if (_elem[i] != _elem[j])
			_elem[++i] = _elem[j];
	}

	_size = ++i;

	shrink();

	return j - i;
}

