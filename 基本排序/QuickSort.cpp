#include <iostream>

using namespace std;

/**************************************************************

Author：hungry
Date:2016.11.30
Description:快速排序

Analysis:
① 

**************************************************************/


static int partition(int* lists, int lo, int hi)
{
	swap(lists[lo],lists[lo + rand() % (hi - lo + 1)]);

	auto pivot = lists[lo];

	while (lo < hi)
	{
		while ((lo < hi) && pivot <= lists[hi])
			hi--;
		lists[lo] = lists[hi];

		while ((lo < hi) && pivot >= lists[lo])
			lo++;
		lists[hi] = lists[lo];
	}

	lists[lo] = pivot;

	return lo;
}

static void _quickSort(int* lists, int lo, int hi)
{
	if (hi - lo < 2) return;

	int mi = partition(lists, lo, hi-1);

	_quickSort(lists, lo, mi);		// [lo,mi)
	_quickSort(lists, mi + 1, hi);	// (mi,hi)
}

static void quickSort(int* lists, int length)
{
	_quickSort(lists,0,length);
}

void main()
{
	int lists[] = {4,345,35,232,53,1,20,33,18,90};
	
	quickSort(lists, sizeof(lists) / sizeof(lists[0]));
	
	for (size_t i = 0; i < sizeof(lists) / sizeof(lists[0]); i++)
		cout << lists[i] << " ";
	
	system("pause");
	
}