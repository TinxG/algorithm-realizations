#pragma once
#include "algo_test.h"
#include "heap.h"

namespace algos {
	//堆排序A
	//时间复杂度O(nlogn)
	//较为缓慢，因为一次次insert和一次次extract
	template <typename T>
	void heapSortA(T arr[], int length) {
		dataStruct::MaxHeap<T> heap(length);
		for (int i = 0; i < length; i++)
			heap.insert(arr[i]);
		for (int i = 0; i < length; i++)
			arr[length - 1 - i] = heap.extractItem();
	}

	//堆排序B
	//时间复杂度O(nlogn)
	//比较缓慢
	//构造函数选用heapify增加速度
	template <typename T>
	void heapSortB(T arr[], int length) {
		dataStruct::MaxHeap<T> heap(arr, length);
		for (int i = 0; i < length; i++)
			arr[length - 1 - i] = heap.extractItem();
	}

	//原地堆排序使用的shiftDown
	//无区别
	template <typename T>
	void __shiftDown(T arr[], int length, int loc) {
		while (loc * 2 + 1 < length)
		{
			int k = loc * 2 + 1;
			if (k + 1 < length && arr[k + 1] > arr[k])
				k += 1;

			if (arr[loc] >= arr[k])
				break;

			swap(arr[loc], arr[k]);
			loc = k;
		}
	}

	//原地堆排序
	//时间复杂度O(nlogn) 空间复杂度O(1)
	//较为快速
	//省去了额外内存消耗
	template <typename T>
	void heapSort(T arr[], int length) {
		//heapify
		for (int i = (length - 2) / 2; i >= 0; i--)
			__shiftDown(arr, length, i);
		for (int i = length - 1; i > 0; i--)
		{
			swap(arr[0], arr[i]);
			__shiftDown(arr, i, 0);
		}
	}
}