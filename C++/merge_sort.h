#pragma once
#include "insertion_sort.h"
#include "algo_test.h"

namespace algos {
	//merge函数
	//归并两个数组
	template <typename T>
	void __merge(T arr[], int l, int mid, int r) {
		vector<T> aux(r - l + 1);
		for (int i = l; i <= r; i++)
			aux[i - l] = arr[i];

		int i = l, j = mid + 1;
		for (int k = l; k <= r; k++)
		{
			if (i > mid)
			{
				arr[k] = aux[j - l];
				j++;
			}
			else if (j > r)
			{
				arr[k] = aux[i - l];
				i++;
			}
			else if (aux[i - l] < aux[j - l])
			{
				arr[k] = aux[i - l];
				i++;
			}
			else
			{
				arr[k] = aux[j - l];
				j++;
			}
		}

	}

	//从底到顶归并排序A
	//无优化
	//时间复杂度O(nlogn)
	//较为缓慢
	template <typename T>
	void mergeSortBUA(T arr[], int length) {
		for (int sz = 1; sz <= length; sz += sz)
		{
			for (int i = 0; i + sz < length; i += sz + sz)
			{
				__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, length - 1));
			}
		}
	}

	//从底到顶归并排序B
	//底层用归并排序B
	//时间复杂度O(nlogn)
	//很快
	template <typename T>
	void mergeSortBUB(T arr[], int length) {
		for (int i = 0; i < length; i += 16)
		{
			insertionSortB(arr, i, i + 15);
		}
		for (int sz = 16; sz <= length; sz += sz)
		{
			for (int i = 0; i + sz < length; i += sz + sz)
			{
				if (arr[i + sz - 1] > arr[i + sz])
					__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, length - 1));
			}
		}
	}

	//递归实现的归并排序递归函数A
	template <typename T>
	void __mergeSortA(T arr[], int l, int r) {
		if (l >= r)
			return;

		int mid = (r - l) / 2 + l;
		__mergeSortA(arr, l, mid);
		__mergeSortA(arr, mid + 1, r);
		__merge(arr, l, mid, r);
	}

	//递归实现的归并排序A
	//无优化
	//时间复杂度O(nlogn)
	//很慢
	template <typename T>
	void mergeSortA(T arr[], int length) {
		__mergeSortA(arr, 0, length - 1);
	}

	//递归实现的归并排序递归函数B
	template <typename T>
	void __mergeSortB(T arr[], int l, int r) {
		//if (l >= r)
		//	return;
		if (r - l <= 15)
		{
			insertionSortB(arr, l, r);
			return;
		}
		int mid = (r - l) / 2 + l;
		__mergeSortB(arr, l, mid);
		__mergeSortB(arr, mid + 1, r);
		if (arr[mid] > arr[mid + 1])
			__merge(arr, l, mid, r);
	}

	//递归实现的归并排序B
	//有优化
	//时间复杂度O(nlogn)
	//较快
	template <typename T>
	void mergeSortB(T arr[], int length) {
		__mergeSortB(arr, 0, length - 1);
	}

	//TODO:K路归并排序
	//这个太难了
	//目前做不出来
	//基于堆的
	/*
	template <typename T>
	void __mergeK(T arr[], int l, int r, int k, int len) {
		T* aux = new T[r - l + 1];
		for (int i = l; i <= r; i++)
			aux[l - i] = arr[i];

		dataStruct::IndexMinHeap<T> heap(k);
		for (int i = 0; i < k; i++)
			heap.insert(i, aux[l + i * len]);
		for (int i = 0; i < (r - l + 1 - k); i++)
		{
			
		}
	}
	template <typename T>
	void __mergeSortK(T arr[], int l, int r, int k) {
		if (l >= r)
			return;
		int len = (l - r + k) / k;
		for (int i = 0; i < k; i++)
		{
			__mergeSortK(arr, l + i * len, min(r, l + i * len + len - 1), int k);
		}
		__mergeK(arr, l, r, k, len);
	}

	template <typename T, int k>
	void mergeSortK(T arr[], int length) {
		__mergeSortK(T arr[], 0, length - 1, k);
	}
	*/
}