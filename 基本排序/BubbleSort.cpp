#include <iostream>

using namespace std;

/**************************************************************

Author：hungry
Date:2016.11.30
Description:冒泡排序

Analysis:
	① 从前往后依次遍历，经过一次交换，最大的在后一位
	② 第二轮交换的时候，不用考虑最后一位
	③ 设置临时变量isSorted，如果一轮没有一次交换，则已排好序

**************************************************************/


static void bubbleSort(int* lists, int length)
{
	auto isSorted = true;

	for (size_t i = length; i > 0; i--)
	{
		for (size_t j = 0; j < i - 1; j++)
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