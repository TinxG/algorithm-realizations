#pragma once
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cassert>
#define test_sortA test_sortA_base<int>
#define test_sortB test_sortB_base<int>

using namespace std;

namespace algos { }

namespace testhelper {

	//�ṹ��RangeArr
	//����ָ������[rangeL,rangeR]
	struct RangeArr {
		int rangeL;
		int rangeR;
	};

	//����make_range
	//ʹ��rangeL��rangeR��ʼ��һ��RangeArr������
	RangeArr make_range(int rangeL, int rangeR) {
		RangeArr range;
		range.rangeL = rangeL;
		range.rangeR = rangeR;
		return range;
	}

	//����random_array
	//ָ�����Ⱥ����䣬�������һ��int�͵����鲢����
	int* random_array(int length, RangeArr range) {
		assert(range.rangeR >= range.rangeL);
		int* arr = new int[length];
		srand(time(NULL));
		for (int i = 0; i < length; i++)
		{
			arr[i] = rand() % (range.rangeR - range.rangeL + 1) + range.rangeL;
		}
		return arr;
	}

	//����generate_NOA
	//NOA=Nearly Ordered Array
	//������length���ȵ����򣨱���Ŀ������Ϊ�������飬�������������Ԫ��swaptimes��
	int* generate_NOA(int length, int swapTimes) {
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

	//����print_array
	//��ӡ����
	template <class T>
	void print_array(T arr[], int length) {
		for (int i = 0; i < length; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	//����is_sorted
	//�ж�ĳ�����Ƿ�����
	template<class T>
	bool is_sorted(T arr[], int length) {
		for (int i = 0; i < length - 1; i++)
		{
			if (arr[i] > arr[i + 1])
				return false;
		}
		return true;
	}

	//����copy_array
	//��������
	template<class T>
	T* copy_array(T* arr, int length) {
		T* copyArr = new T[length];
		for (int i = 0; i < length; i++)
			copyArr[i] = arr[i];
		return copyArr;
	}

	//����test_sortA_base
	//��������
	//��Ϊ��ʵ���в���ԭ���ģ�������޷��Զ�ʶ��Ĵ���
	//��������Ϊtest_sortA_base
	//���ļ���ͷ�����꣺test_sortA
	//�൱��test_sortA_base<int>
	//�����Զ���Ԫ��
	//���Զ�����repeat�β��ԣ�ÿ�β�����������addlen
	template<class T>
	void test_sortA_base(string sortName, void(*sort)(T[], int), int addlen, int repeat,RangeArr range) {
		for (int i = 0; i < repeat; i++)
		{
			int length = (i + 1) * addlen;
			T* arr = random_array(length, range);
			clock_t startTime = clock();
			sort(arr, length);
			clock_t endTime = clock();
			assert(is_sorted(arr, length));
			cout << sortName << i + 1 << " length " << length << " time:" << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
		}
		return;
	}

	//����test_sortB_base
	//��������
	//���Զ���
	//���ǿ����Լ�����������Ϊ����������
	//����Ҫ��randomArray
	template<class T>
	void test_sortB_base(string sortName, void(*sort)(T[], int), T* arr, int length) {
		clock_t startTime = clock();
		sort(arr, length);
		clock_t endTime = clock();
		assert(is_sorted(arr, length));
		cout << sortName << " length " << length << " time:" << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
	}
}
