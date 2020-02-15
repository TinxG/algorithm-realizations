#include "bubble_sort.h"
#include "heap.h"
#include "quick_sort.h"
#include "binary_search.h"
#include "union_test.h"
#include "union_find.h"

using namespace std;
using namespace algos;
using namespace testhelper;
using namespace dataStruct;

int main() {
	//在此添加测试代码
	//testUF1(10000);
	//testUF2(100000);
	testUF3(1000000);
	testUF4(1000000);
	testUF5(1000000);
	testUF6(1000000);
	system("pause");
	return 0;
}