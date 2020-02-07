#pragma once
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cassert>
#define testSortA testSortA_base<int>
#define testSortB testSortB_base<int>

using namespace std;

namespace algos { }

namespace testhelper {

	//�ṹ��RangeArr
	//����ָ������[rangeL,rangeR]
	struct RangeArr {
		int rangeL;
		int rangeR;
	};

	//����makeRange
	//ʹ��rangeL��rangeR��ʼ��һ��RangeArr������
	RangeArr makeRange(int rangeL, int rangeR) {
		RangeArr range;
		range.rangeL = rangeL;
		range.rangeR = rangeR;
		return range;
	}

	//����randomArray
	//ָ�����Ⱥ����䣬�������һ��int�͵����鲢����
	int* randomArray(int length, RangeArr range) {
		assert(range.rangeR >= range.rangeL);
		int* arr = new int[length];
		srand(time(NULL));
		for (int i = 0; i < length; i++)
		{
			arr[i] = rand() % (range.rangeR - range.rangeL + 1) + range.rangeL;
		}
		return arr;
	}

	//����generateNOA
	//NOA=Nearly Ordered Array
	//������length���ȵ����򣨱���Ŀ������Ϊ�������飬�������������Ԫ��swaptimes��
	int* generateNOA(int length, int swapTimes) {
		int* arr = new int[length];
		for (int i = 0; i < length; i++)
			arr[i] = i;

		srand(time(NULL));
		for (int i = 0; i < swapTimes; i++)
		{
			int posx = rand() % length; //random range:[0,length)
			int posy = rand() % length;
			swap(arr[posx], arr[posy]);
		}
		return arr;
	}

	//����printArray
	//��ӡ����
	template <typename T>
	void printArray(T arr[], int length) {
		for (int i = 0; i < length; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	//����isSorted
	//�ж�ĳ�����Ƿ�����
	template <typename T>
	bool isSorted(T arr[], int length) {
		for (int i = 0; i < length - 1; i++)
		{
			if (arr[i] > arr[i + 1])
				return false;
		}
		return true;
	}

	//����copyArray
	//��������
	template <typename T>
	T* copyArray(T* arr, int length) {
		T* copyArr = new T[length];
		for (int i = 0; i < length; i++)
			copyArr[i] = arr[i];
		return copyArr;
	}

	//����testSortA_base
	//��������
	//��Ϊ��ʵ���в���ԭ���ģ�������޷��Զ�ʶ��Ĵ���
	//��������ΪtestSortA_base
	//���ļ���ͷ�����꣺testSortA
	//�൱��testSortA_base<int>
	//�����Զ���Ԫ��
	//���Զ�����repeat�β��ԣ�ÿ�β�����������addlen
	template <typename T>
	void testSortA_base(string sortName, void(*sort)(T[], int), int addlen, int repeat,RangeArr range) {
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

	//����testSortB_base
	//��������
	//���Զ���
	//���ǿ����Լ�����������Ϊ����������
	//����Ҫ��randomArray
	template <typename T>
	void testSortB_base(string sortName, void(*sort)(T[], int), T* arr, int length) {
		clock_t startTime = clock();
		sort(arr, length);
		clock_t endTime = clock();
		assert(isSorted(arr, length));
		cout << sortName << " length " << length << " time:" << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
	}
}
