#include <iostream>

using namespace std;

/*
 * 基本思想为：从后往前，寻得最大的和后面的交换
 */

static int max(int* lists, int length)
{
	int maxIndex = length;

	while (length--)
		if (lists[length] > lists[maxIndex])
			maxIndex = length;

	return maxIndex;
}

//选择排序
static void selectionSort(int* lists, int length)
{
	while (--length)
		swap(lists[max(lists,length)],lists[length]);

	for (size_t i = 0; i < 6; i++)
	{
		cout << lists[i] << " ";
	}
}

void main()
{
	int lists[] = {4,345,35,232,53,1,20,33,18,90};
	
	selectionSort(lists, sizeof(lists) / sizeof(lists[0]));

}