#pragma once
#include "vector.h"

template<typename T>
Vector<T>& Vector<T>::operator= (Vector<T> const& V)
{
	if (_elem)
		delete []_elem;			//删除旧的_elem所占的内存空间，copyFrom会重新new

	copyFrom(V,0,V._size);

	return *this;				//*this是取引用
}
