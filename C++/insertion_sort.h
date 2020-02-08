#pragma once
#include "algo_test.h"

namespace algos {
	//插入排序A
	//时间复杂度O(n^2)
	//比较慢
	template <typename T>
	void insertionSortA(T arr[], int length) {
		for (int i = 1; i < length; i++)
		{
			for (int j = i; j > 0; j--)
			{
				if (arr[j] < arr[j - 1])
					swap(arr[j], arr[j - 1]);
				else
					break;
			}
		}
	}

	//插入排序B
	//时间复杂度O(n^2)
	//通过不使用交换函数加快速度
	//较为快速
	template <typename T>
	void insertionSortB(T arr[], int length) {
		for (int i = 1; i < length; i++)
		{
			T a = arr[i];
			int j;
			for (j = i; j > 0 && arr[j - 1] > a; j--)
			{
				arr[j] = arr[j - 1];
			}
			arr[j] = a;
		}
	}

	//插入排序B重载
	//用于O(nlogn)算法底层优化
	template <class T>
	void insertionSortB(T arr[], int l, int r) {
		for (int i = l + 1; i <= r; i++)
		{
			T a = arr[i];
			int j;
			for (j = i; j > l && arr[j - 1] > a; j--)
				arr[j] = arr[j - 1];
			arr[j] = a;
		}
	}
}