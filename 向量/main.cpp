#include <iostream>
#include "vector.h"
#include "vector_insert.h"
#include "vector_expand.h"
#include "vector_remove.h"
#include "vector_print.h"
#include "vector_find.h"

using namespace std;

void main()
{
	Vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.insert(i);
	}

	int i = v.search(20);

	cout << i << endl;

	system("pause");
}