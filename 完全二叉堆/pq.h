#pragma once

/**************************************************************

Author：hungry
Date:2016.12.10
Description:优先级队列

Analysis:
① 有插入方法，会将该值插入到既定的位置
② 内部按照树状结构排列，父节点大于左右孩子节点
③ 这样保证了根节点永远是最大的
④ 删除方法会删除根节点

**************************************************************/

template<typename T>
struct PQ
{
public:
	virtual ~PQ()
	{
	}

	virtual void insert(T) = 0;
	virtual T getMax() = 0;
	virtual T delMax() = 0;
};
