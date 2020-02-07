#pragma once
#include "algo_test.h"

namespace algos {
	//��������A
	//ʱ�临�Ӷ�O(n^2)
	//�Ƚ���
	template <typename T>
	void insertionSortA(T arr[], int length) {
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

	//��������B
	//ʱ�临�Ӷ�O(n^2)
	//ͨ����ʹ�ý��������ӿ��ٶ�
	//��Ϊ����
	template <typename T>
	void insertionSortB(T arr[], int length) {
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

	//��������B����
	//����O(nlogn)�㷨�ײ��Ż�
	template <class T>
	void insertionSortB(T arr[], int l, int r) {
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