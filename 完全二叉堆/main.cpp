#include <iostream>
#include "pq_complheap.h"

using namespace std;

void main()
{
	int* a = new int[5]{1,2,3,4,5};

	PQ_ComplHeap<int> PQ(a,5);


	system("pause");
}