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
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << arr[binarySearchB(arr, 10, 8)] << endl;
	system("pause");
	return 0;
}