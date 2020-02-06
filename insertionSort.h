#pragma once
#include "algotest.h"

namespace algos
{
	template <class T>
	void insertionSortA(T arr[], int length)
	{
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

	template <class T>
	void insertionSortB(T arr[], int length)
	{
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

	template <class T>
	void insertionSortB(T arr[], int l, int r)
	{
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