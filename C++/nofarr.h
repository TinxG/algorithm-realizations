#pragma once
#include "algo_test.h"
//我取名技术太差了
//nofarr = the Nth of an array

namespace algos {
	//用于得到第N小元素算法的partition操作函数
	template <typename T>
	int __partitionG(T arr[], int l, int r) {
		swap(arr[l], arr[(r + l) / 2]);

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

	//getTheN的递归函数
	template <typename T>
	T __getTheN(T arr[], int l, int r, int rank) {
		if (l >= r)
			return arr[l];
		int p = __partitionG(arr, l, r);
		if (p > rank)
		{
			return __getTheN(arr, l, p - 1, rank);
		}
		else if (p < rank)
		{
			return __getTheN(arr, p + 1, r, rank);
		}
		else
		{
			return arr[p];
		}
	}

	//基于快速排序的获得第N小元素的算法getTheN
	//时间复杂度O(nlogn)
	template <typename T>
	T getTheN(T arr[], int length, int rank) {
		return __getTheN(arr, 0, length - 1, rank - 1);
	}
}