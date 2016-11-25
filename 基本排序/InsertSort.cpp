#include <iostream>

using namespace std;

//≤Â»Î≈≈–Ú
static void insertSort(int* lists,int length)
{
	for (size_t i = 1; i < length; i++)
	{
		int temp = lists[i];

		size_t j;

		for (j = i; j > 0 && lists[j-1] > temp; j--)
			lists[j] = lists[j - 1];

		lists[j] = temp;
	}

	for (size_t i = 0; i < length; i++)
		cout << lists[i] << " ";
}

void main()
{
	int lists[] = {4,345,35,232,53,1,20,33,18,90};
	
	insertSort(lists, sizeof(lists) / sizeof(lists[0]));
	
	system("pause");
	
}