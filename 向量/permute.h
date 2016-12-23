#pragma once
#include "vector.h"
#include <cstdlib>
#include <vector>

//将列表随机打乱顺序

template<typename T>
static void permute(Vector<T> &V)
{
	for(int i = V.size(); i > 0; i--)
	{
		std::swap(V[i - 1], V[rand() % i]); //V[i-1] 与 [0,i)的某一个元素交换
	}
}
