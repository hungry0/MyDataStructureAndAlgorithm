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

	v.find(20);

	v.printAll();

	system("pause");
}