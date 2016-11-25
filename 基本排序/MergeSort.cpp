#include <iostream>

using namespace std;

static void merge(int* lists, int lo, int mi, int hi)
{
	int* A = lists + lo;
	
	int lb = mi - lo;

	int* B = new int[lb];

	for (size_t i = 0; i < lb; B[i] = A[i++]);

	int lc = hi - mi;

	int* C = lists + mi;

	for (int i = 0, j = 0, k = 0; j < lb || k < lc;)
	{
		if ((j < lb) && (!(k < lc) || (B[j] <= C[k])))
			A[i++] = B[j++];
		if ((k < lc) && (!(j < lb) || C[k] < B[j]))
			A[i++] = C[k++];
	}

	delete[] B;
}

static void _mergeSort(int* lists, int lo, int hi)
{
	if (hi - lo < 2)
		return;

	int mi = (lo + hi) / 2;

	_mergeSort(lists, lo, mi);
	_mergeSort(lists, mi, hi);

	merge(lists, lo, mi, hi);
}

//¹é²¢ÅÅÐò
static void mergeSort(int* lists, int length)
{
	_mergeSort(lists,0,length);
}

void main()
{
	int lists[] = {4,345,35,232,53,1,20,33,18,90};
	
	mergeSort(lists, sizeof(lists) / sizeof(lists[0]));
	
	for (size_t i = 0; i < sizeof(lists) / sizeof(lists[0]); i++)
		cout << lists[i] << " ";
	
	system("pause");
}