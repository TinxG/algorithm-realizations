#pragma once
#include "algo_test.h"

namespace algos {
	//二分查找法（迭代）
	//数组arr必须为升序有序数组
	template <typename T>
	int binarySearchA(T arr[], int length, T target) {
		//查找区间[l,r]
		int l = 0, r = length - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (arr[mid] == target) {
				return mid;
			}
			else if (arr[mid] > target) {
				r = mid - 1;
				continue;
			}
			else {
				l = mid + 1;
				continue;
			}
		}
		return -1;
	}

	//递归函数
	template <typename T>
	int __binarySearch(T arr[], int l, int r, T target)
	{
		if (l > r)
			return -1;
		int mid = (r - l) / 2 + l;
		if (target == arr[mid])
			return mid;
		else if (target < arr[mid])
			return __binarySearch(arr, l, mid - 1, target);
		else
			return __binarySearch(arr, mid + 1, r, target);
	}

	//采用递归的二分查找法
	//数组arr必须为升序有序数组
	template <typename T>
	int binarySearchB(T arr[], int length, T target)
	{
		return __binarySearch(arr, 0, length - 1, target);
	}
}