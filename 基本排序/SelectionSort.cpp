#include <iostream>

using namespace std;

/**************************************************************

Author：hungry
Date:2016.11.30
Description:选择排序

Analysis:
① 从后往前遍历，选取最大值
② 将选择的最大值与最后一位进行交换
③ 第二轮时将最后一位往前推一位
④ 遍历到最后，即可完成排序

**************************************************************/

static int max(int* lists, int length)
{
	auto maxIndex = length;

	while (length--)
		if (lists[length] > lists[maxIndex])
			maxIndex = length;

	return maxIndex;
}

static void selectionSort(int* lists, int length)
{
	while (--length)
		swap(lists[max(lists,length)],lists[length]);
}

void main()
{
	int lists[] = {4,345,35,232,53,1,20,33,18,90};
	
	selectionSort(lists, sizeof(lists) / sizeof(lists[0]));

	for (size_t i = 0; i < sizeof(lists) / sizeof(lists[0]); i++)
	{
		cout << lists[i] << " ";
	}

	system("pause");
}