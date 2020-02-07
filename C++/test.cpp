#include "algo_test.h"
#include "bubble_sort.h"

using namespace std;
using namespace algos;
using namespace testhelper;

int main() {
	test_sortA("Bubble Sort", bubble_sort, 10000, 3, make_range(0, 10000));
	return 0;
}