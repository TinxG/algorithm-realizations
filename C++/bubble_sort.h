#pragma once
#include "algo_test.h"

namespace algos {
	
	//函数bubble_sort
	//冒泡排序，时间复杂度O(n^2)
	template <class T>
	void bubble_sort(T arr[], int length) {
		int k = length - 1; //用于内层j的循环条件
		for (int i = 0; i < (length - 1); i++)
		{
			bool flag = false; //bool类型的flag记录是否排序过
			int pos = 0; //记录最后一次排序位置
			for (int j = 0; j < k; j++)
			{
				if (arr[j] > arr[j + 1])
					swap(arr[j], arr[j + 1]);
				flag = true;
				pos = j;
			}
			if (!flag)
				return;
			k = pos;
		}
	}
}