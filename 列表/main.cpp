#include <iostream>
#include "list.h"
#include "list_destructor.h"
#include "list_insert.h"
#include "list_printAll.h"
#include "list_clear.h"
#include "list_uniquify.h"
#include "list_reverse.h"


using namespace std;

void main()
{
	List<int> L;

	L.insertAsFirst(0);

	L.insertA(L.first(), 1);

	L.printAll();

	L.reverse();

	L.printAll();

	system("pause");
}