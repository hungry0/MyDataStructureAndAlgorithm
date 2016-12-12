#include <iostream>
#include "pq_complheap.h"

using namespace std;

void main()
{
	int* a = new int[5]{1,2,3,4,5};

	PQ_ComplHeap<int>* PQ = new PQ_ComplHeap<int>(a,5);

	PQ->insert(10);

	cout << PQ->delMax();

	system("pause");
}