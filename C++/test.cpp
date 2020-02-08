#include "algo_test.h"
#include "bubble_sort.h"
#include "heap.h"

using namespace std;
using namespace algos;
using namespace testhelper;
using namespace dataStruct;

int main() {
	//在这里添加你想要的测试代码
	MaxMinHeap<int> mmh(20);
	mmh.insert(15, 111).insert(14, 123).insert(13, 155).insert(1, 22).insert(8, 88).insert(7, 76).printAsArray(MaxIndex);
	mmh.printAsArray(MinIndex);
	IndexItem<int> ii = mmh.extractMax();
	cout << "index:" << ii.index << " item:" << ii.item << endl;
	mmh.change(14, 156).printAsArray(MaxIndex);
	mmh.printAsArray(MinIndex);
	system("pause");
	return 0;
}