#pragma once
#include "heap_sort.h"
#include "algo_test.h"

namespace algos {
	//利用最小堆实现的从length长度的数组中取出最大的前N个元素
	//时间复杂度O(nlogM)M为常数
	template <typename T, int n>
	T* qianN(T arr[], int length) {
		dataStruct::MinHeap<T> he(arr, n);
		for (int i = n; i < length; i++)
		{
			if (he.getItem(0) < arr[i])
			{
				he.extractItem();
				he.insert(arr[i]);
			}
		}
		//后面操作不算在总时间内
		//因为这些操作不在算法要求范围内
		//这里只是把堆放到数组里
		T* arra = new T[n];
		for (int i = 0; i < n; i++)
			arra[i] = he.extractItem();
		return arra;
	}
}