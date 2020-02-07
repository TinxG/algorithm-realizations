#pragma once
#include "algo_test.h"
//reverse number pairs
//求某数组中倒序数对个数

namespace algos {
	//rnp的merge并求倒序数对函数
	template <typename T>
	long long __mergeG(T arr[], int l, int mid, int r) {
		T* aux = new T[r - l + 1];
		int i = l, j = mid + 1;
		long long rnpCount = 0L;
		for (int a = l; a <= r; a++)
		{
			aux[a - l] = arr[a];
		}
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
			else    //aux[i-l]>aux[j-l]
			{
				arr[k] = aux[j - l];
				j++;
				rnpCount += (long long)mid - i + 1;
			}
		}
		return (long long)rnpCount;
	}
	
	//rnp的递归函数
	template <typename T>
	long long __getRNP(T arr[], int l,int r) {
		long long rnpCount = 0L;
		if (l >= r)
			return rnpCount;

		int mid = (l + r) / 2;
		rnpCount += __getRNP(arr, l, mid);
		rnpCount += __getRNP(arr, mid + 1, r);
		rnpCount += __mergeG(arr, l, mid, r);
		return (long long)rnpCount;
	}

	//计算倒序数对函数
	//时间复杂度O(nlogn)
	//基于递归的归并排序
	template <typename T>
	long long getRNP(T arr[],int length) {
		return (long long)__getRNP(arr, 0, length - 1);
	}
}