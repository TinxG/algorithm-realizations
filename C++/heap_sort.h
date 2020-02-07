#pragma once
#include "algo_test.h"
#include "heap.h"

namespace algos {
	//������A
	//ʱ�临�Ӷ�O(nlogn)
	//��Ϊ��������Ϊһ�δ�insert��һ�δ�extract
	template <typename T>
	void heapSortA(T arr[], int length) {
		dataStruct::MaxHeap<T> heap(length);
		for (int i = 0; i < length; i++)
			heap.insert(arr[i]);
		for (int i = 0; i < length; i++)
			arr[length - 1 - i] = heap.extractItem();
	}

	//������B
	//ʱ�临�Ӷ�O(nlogn)
	//�Ƚϻ���
	//���캯��ѡ��heapify�����ٶ�
	template <typename T>
	void heapSortB(T arr[], int length) {
		dataStruct::MaxHeap<T> heap(arr, length);
		for (int i = 0; i < length; i++)
			arr[length - 1 - i] = heap.extractItem();
	}

	//ԭ�ض�����ʹ�õ�shiftDown
	//������
	template <typename T>
	void __shiftDown(T arr[], int length, int loc) {
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

	//ԭ�ض�����
	//ʱ�临�Ӷ�O(nlogn) �ռ临�Ӷ�O(1)
	//��Ϊ����
	//ʡȥ�˶����ڴ�����
	template <typename T>
	void heapSort(T arr[], int length) {
		//heapify
		for (int i = (length - 2) / 2; i >= 0; i--)
			__shiftDown(arr, length, i);
		for (int i = length - 1; i > 0; i--)
		{
			swap(arr[0], arr[i]);
			__shiftDown(arr, i, 0);
		}
	}
}