#pragma once

/*
 * 优先级队列
 */

template<typename T>
struct PQ
{
public:
	virtual void insert(T) = 0;
	virtual T getMax() = 0;
	virtual T delMax() = 0;
};
