#pragma once
#include "heap_sort.h"
#include "algo_test.h"

namespace algos {
	//������С��ʵ�ֵĴ�length���ȵ�������ȡ������ǰN��Ԫ��
	//ʱ�临�Ӷ�O(nlogM)MΪ����
	template <typename T, int n>
	T* qianN(T arr[], int length) {
		dataStruct::MinHeap<T> he(arr, n);
		for (int i = n; i < length; i++)
		{
			if (he.getItem(0) < arr[i])
			{
				he.extractItem();
				he.insert(arr[i]);
			}
		}
		//���������������ʱ����
		//��Ϊ��Щ���������㷨Ҫ��Χ��
		//����ֻ�ǰѶѷŵ�������
		T* arra = new T[n];
		for (int i = 0; i < n; i++)
			arra[i] = he.extractItem();
		return arra;
	}
}