#pragma once
#include "algotest.h"
#include "heap.h"

namespace algos
{
	template <class T>
	void heapSortA(T arr[], int length)
	{
		dataStruct::MaxHeap<T> heap(length);
		for (int i = 0; i < length; i++)
			heap.insert(arr[i]);
		for (int i = 0; i < length; i++)
			arr[length - 1 - i] = heap.extract();
	}

	template <class T>
	void heapSortB(T arr[], int length)
	{
		dataStruct::MaxHeap<T> heap(arr, length);
		for (int i = 0; i < length; i++)
			arr[length - 1 - i] = heap.extract();
	}

	template <class T>
	void __shiftDown(T arr[], int length, int loc)
	{
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
	template <class T>
	void heapSort(T arr[], int length)
	{
		//heapify
		for (int i = (length - 2) / 2; i >= 0; i--)
			__shiftDown(arr, length, i);
		for (int i = length - 1; i > 0; i--)
		{
			swap(arr[0], arr[i]);
			__shiftDown(arr, i, 0);
		}
	}

	template <class T, int n>
	T* qianN(T arr[], int length)
	{
		dataStruct::MinHeap<T> he(arr, n);
		for (int i = n; i < length; i++)
		{
			if (he.getItem(0) < arr[i])
			{
				he.extract();
				he.insert(arr[i]);
			}
		}
		T* arra = new T[n];
		for (int i = 0; i < n; i++)
			arra[i] = he.extract();
		return arra;
	}
}