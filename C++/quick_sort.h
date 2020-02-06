#pragma once
#include "algotest.h"

namespace algos
{
	template <class T>
	int __partitionA(T arr[], int l, int r)
	{
		swap(arr[l], arr[(r + l) / 2]);
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

	template <class T>
	int __partitionB(T arr[], int l, int r)
	{
		swap(arr[l], arr[(r+l)/2]);

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

	template <class T>
	void __quickSortA(T arr[], int l, int r)
	{
		if (r - l <= 15)
		{
			insertionSortB(arr, l, r);
			return;
		}

		int p = __partitionA(arr, l, r);
		__quickSortA(arr, l, p - 1);
		__quickSortA(arr, p + 1, r);
	}

	template <class T>
	void quickSortA(T arr[], int length)
	{
		__quickSortA(arr, 0, length - 1);
	}

	template <class T>
	void __quickSortB(T arr[], int l, int r)
	{
		if (r - l <= 15)
		{
			insertionSortB(arr, l, r);
			return;
		}

		int p = __partitionB(arr, l, r);
		__quickSortB(arr, l, p - 1);
		__quickSortB(arr, p + 1, r);
	}

	template <class T>
	void __quickSortC(T arr[], int l, int r)
	{
		if (r - l <= 15)
		{
			insertionSortB(arr, l, r);
			return;
		}

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

	template <class T>
	void quickSortB(T arr[], int length)
	{
		__quickSortB(arr, 0, length - 1);
	}

	template <class T>
	void quickSortC(T arr[], int length)
	{
		__quickSortC(arr, 0, length - 1);
	}
}
