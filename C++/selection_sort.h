#pragma once
#include "algo_test.h"

namespace algos {
	//选择排序
	//时间复杂度O(n^2)
	template <typename T>
	void selectionSort(T arr[], int length) {
		for (int i = 0; i < length; i++)
		{
			int minindex = i;
			for (int j = i; j < length; j++)
			{
				if (arr[j] < arr[minindex])
					minindex = j;
			}
			swap(arr[minindex], arr[i]);
		}
	}
}