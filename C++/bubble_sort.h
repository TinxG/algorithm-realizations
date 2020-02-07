#pragma once
#include "algotest.h"

namespace algos
{
	template <class T>
	void bubbleSort(T arr[], int length)
	{
		for (int i = 0; i < (length - 1); i++)
		{
			for (int j = 0; j < (length - i - 1); j++)
			{
				if (arr[j] > arr[j + 1])
					swap(arr[j], arr[j + 1]);
			}
			if (testhelper::isSorted(arr, length))
				break;
		}
	}
}
// 其实可以通过省略排序过的项增加效率的