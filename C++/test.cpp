#include "algo_test.h"
#include "bubble_sort.h"
#include "heap.h"
#include "binary_search.h"

using namespace std;
using namespace algos;
using namespace testhelper;
using namespace dataStruct;

int main() {
	//在这里添加你想要的测试代码
	const int length = 14;
	int arr[length] = { 1,2,3,4,5,8,8,8,8,8,8,9,9,10 };
	cout << binarySearchFloor(arr, length, 8) << endl;
	system("pause");
	return 0;
}