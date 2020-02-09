#include "bubble_sort.h"
#include "heap.h"
#include "binary_search.h"

using namespace std;
using namespace algos;
using namespace testhelper;
using namespace dataStruct;

int main() {
	//在此添加测试代码
	BST<int, int> bst;
	bst.insertA(0, 5).insertB(4, 11).insertA(3,12).insertA(4, 12);
	cout << bst[0] << "," << bst[4] << endl;
	system("pause");
	return 0;
}