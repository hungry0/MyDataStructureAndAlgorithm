#include <iostream>
#include "list.h"
#include "list_destructor.h"
#include "list_insert.h"
#include "list_printAll.h"

using namespace std;

void main()
{
	List<int> L;

	L.insertAsFirst(0);

	L.insertA(L.first(), 1);

	L.printAll();

	system("pause");
}