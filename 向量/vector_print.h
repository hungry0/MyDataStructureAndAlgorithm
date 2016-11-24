#pragma once
#include "vector.h"
#include <iostream>

template <typename T>
void Vector<T>::printAll()
{
	for (int i = 0; i < _size; i++)
		std::cout << _elem[i] << " ";
}

