#pragma once
#include "algo_test.h"
#include "insertion_sort.h"

namespace algos {
	//单路partition
	template <typename T>
	int __partitionA(T arr[], int l, int r) {
		swap(arr[l], arr[(r - l) / 2 + l]);
		T v = arr[l];
		int j = l;
		for (int i = l+1;i <= r; i++)
		{
			if (arr[i] < v)
			{
				swap(arr[i], arr[j + 1]);
				j++;
			}
		}
		swap(arr[l], arr[j]);
		return j;
	}

	//双路partition
	template <typename T>
	int __partitionB(T arr[], int l, int r) {
		swap(arr[l], arr[(r - l) / 2 + l]);

		T v = arr[l];
		int i = l + 1, j = r;
		while (true)
		{
			while (i <= r && arr[i] < v)i++;
			while (j > l && arr[j] > v)j--;
			if (i > j)break;
			swap(arr[i++], arr[j--]);
		}
		swap(arr[l], arr[j]);
		return j;
	}

	//单路快排的递归函数
	template <typename T>
	void __quickSortA(T arr[], int l, int r) {
		if (r - l <= 15)
		{
			insertionSortB(arr, l, r);
			return;
		}

		int p = __partitionA(arr, l, r);
		__quickSortA(arr, l, p - 1);
		__quickSortA(arr, p + 1, r);
	}

	//单路快排
	//时间复杂度O(nlogn)
	//对于重复数组退化为O(n^2)
	template <typename T>
	void quickSortA(T arr[], int length) {
		__quickSortA(arr, 0, length - 1);
	}
	
	//双路快排的递归函数
	template <typename T>
	void __quickSortB(T arr[], int l, int r) {
		if (r - l <= 15)
		{
			insertionSortB(arr, l, r);
			return;
		}

		int p = __partitionB(arr, l, r);
		__quickSortB(arr, l, p - 1);
		__quickSortB(arr, p + 1, r);
	}

	//三路快排的递归函数，内置partition
	template <typename T>
	void __quickSortC(T arr[], int l, int r) {
		if (r - l <= 15)
		{
			insertionSortB(arr, l, r);
			return;
		}

		//partition开始
		swap(arr[l], arr[(r + l) / 2]);
		T v = arr[l];

		int lt = l, gt = r + 1, i = l + 1;
		while (i < gt)
		{
			if (arr[i] < v)
			{
				swap(arr[i], arr[lt + 1]);
				lt++;
				i++;
			}
			else if (arr[i] > v)
			{
				swap(arr[i], arr[gt-1]);
				gt--;
			}
			else
			{
				i++;
			}
		}
		swap(arr[l], arr[lt]);

		__quickSortC(arr, l, lt - 1);
		__quickSortC(arr, gt, r);
	}

	//双路快排
	//时间复杂度O(nlogn)
	//对于重复数组已经可以较快地处理了
	template <typename T>
	void quickSortB(T arr[], int length) {
		__quickSortB(arr, 0, length - 1);
	}

	//三路快排
	//时间复杂度O(nlogn)
	//对于重复数组可以极快地处理完成
	//对于一般数组也可以加快速度
	template <typename T>
	void quickSortC(T arr[], int length) {
		__quickSortC(arr, 0, length - 1);
	}
}
