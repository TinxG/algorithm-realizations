#pragma once
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <vector>
#define testSortA testSortA_base<int>
#define testSortB testSortB_base<int>

using namespace std;

namespace algos
{
	
}

namespace testhelper
{
	struct rangearr
	{
		int rangeL;
		int rangeR;
	};

	rangearr makerange(int rangeL, int rangeR)
	{
		rangearr range;
		range.rangeL = rangeL;
		range.rangeR = rangeR;
		return range;
	}

	int* randomArray(int length, rangearr range)
	{
		assert(range.rangeR >= range.rangeL);
		int* arr = new int[length];
		srand(time(NULL));
		for (int i = 0; i < length; i++)
		{
			arr[i] = rand() % (range.rangeR - range.rangeL + 1) + range.rangeL;
		}
		return arr;
	}

	int* generateNOA(int length, int swaptimes)
	{
		int* arr = new int[length];
		for (int i = 0; i < length; i++)
			arr[i] = i;

		srand(time(NULL));
		for (int i = 0; i < swaptimes; i++)
		{
			int posx = rand() % length;
			int posy = rand() % length;
			swap(arr[posx], arr[posy]);
		}
		return arr;
	}

	template <class T>
	void printArray(T arr[], int length)
	{
		for (int i = 0; i < length; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	template<class T>
	bool isSorted(T arr[], int length)
	{
		for (int i = 0; i < length - 1; i++)
		{
			if (arr[i] > arr[i + 1])
				return false;
		}
		return true;
	}

	template<class T>
	T* copyArray(T* arr, int length)
	{
		T* copyArr = new T[length];
		for (int i = 0; i < length; i++)
			copyArr[i] = arr[i];
		return copyArr;
	}

	template<class T>
	void testSortA_base(string sortName, void(*sort)(T[], int), int addlen, int repeat,rangearr range)
	{
		for (int i = 0; i < repeat; i++)
		{
			int length = (i + 1) * addlen;
			T* arr = randomArray(length, range);
			clock_t startTime = clock();
			sort(arr, length);
			clock_t endTime = clock();
			assert(isSorted(arr, length));
			cout << sortName << i + 1 << " length " << length << " time:" << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
		}
		return;
	}

	template<class T>
	void testSortB_base(string sortName, void(*sort)(T[], int), T* arr, int length)
	{
		clock_t startTime = clock();
		sort(arr, length);
		clock_t endTime = clock();
		assert(isSorted(arr, length));
		cout << sortName << " length " << length << " time:" << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
	}
}
