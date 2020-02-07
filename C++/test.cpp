#include "algo_test.h"
#include "bubble_sort.h"

using namespace std;
using namespace algos;
using namespace testhelper;

int main() {
	testSortA("Bubble Sort", bubbleSort, 10000, 3, makeRange(0, 10000));
	system("pause");
	return 0;
}