#pragma once
#include "algotest.h"

namespace algos
{
	template <class T>
	void selectionSort(T arr[], int length)
	{
		for (int i = 0; i < length; i++)
		{
			int minindex = i;
			for (int j = i; j < length; j++)
			{
				if (arr[j] < arr[minindex])
					minindex = j;
			}
			swap(arr[minindex], arr[i]);
		}
	}
}