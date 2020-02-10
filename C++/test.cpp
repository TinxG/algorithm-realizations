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
	bst.insert(0, 5).insert(3, 12).insert(5, 12).insert(2, 11).insert(55, 33);
	bst.levelOrder();
	bst.inOrder();
	bst.removeMin();
	bst.removeMax();
	bst.levelOrder();
	cout << bst.getSize() << endl;
	system("pause");
	return 0;
}