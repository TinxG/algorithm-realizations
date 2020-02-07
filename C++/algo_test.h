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

	//结构体RangeArr
	//用于指定区间[rangeL,rangeR]
	struct RangeArr {
		int rangeL;
		int rangeR;
	};

	//函数make_range
	//使用rangeL和rangeR初始化一个RangeArr并返回
	RangeArr make_range(int rangeL, int rangeR) {
		RangeArr range;
		range.rangeL = rangeL;
		range.rangeR = rangeR;
		return range;
	}

	//函数random_array
	//指定长度和区间，随机生成一个int型的数组并返回
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

	//函数generate_NOA
	//NOA=Nearly Ordered Array
	//先生成length长度的升序（本项目中升序为有序）数组，并随机交换其中元素swaptimes次
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

	//函数print_array
	//打印数组
	template <class T>
	void print_array(T arr[], int length) {
		for (int i = 0; i < length; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	//函数is_sorted
	//判断某数组是否有序
	template<class T>
	bool is_sorted(T arr[], int length) {
		for (int i = 0; i < length - 1; i++)
		{
			if (arr[i] > arr[i + 1])
				return false;
		}
		return true;
	}

	//函数copy_array
	//复制数组
	template<class T>
	T* copy_array(T* arr, int length) {
		T* copyArr = new T[length];
		for (int i = 0; i < length; i++)
			copyArr[i] = arr[i];
		return copyArr;
	}

	//函数test_sortA_base
	//测试排序
	//因为在实践中不明原因的模板类型无法自动识别的错误
	//这里声明为test_sortA_base
	//在文件开头声明宏：test_sortA
	//相当于test_sortA_base<int>
	//加入自动化元素
	//可自动进行repeat次测试，每次测试数据增加addlen
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

	//函数test_sortB_base
	//测试排序
	//无自动化
	//但是可以自己声明数组作为参数传进来
	//不必要用randomArray
	template<class T>
	void test_sortB_base(string sortName, void(*sort)(T[], int), T* arr, int length) {
		clock_t startTime = clock();
		sort(arr, length);
		clock_t endTime = clock();
		assert(is_sorted(arr, length));
		cout << sortName << " length " << length << " time:" << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
	}
}
