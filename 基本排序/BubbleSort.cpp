#include <iostream>

using namespace std;

//冒泡排序
static void bubbleSort(int* lists, int length)
{
	bool isSorted = true;

	for (size_t i = length; i > 0; i--)
	{
		for (int j = 0; j < i-1; j++)
		{
			if (lists[j] > lists[j + 1])
			{
				swap(lists[j], lists[j + 1]);
				isSorted = false;
			}
		}

		if (!isSorted)
			break;
	}

	for (size_t i = 0; i < length; i++)
	{
		cout << lists[i] << " ";
	}
}

void main()
{
	int lists[] = {4,345,35,232,53,1,20,33,18,90};
	
	bubbleSort(lists,sizeof(lists) / sizeof(lists[0]));
	
	system("pause");
}