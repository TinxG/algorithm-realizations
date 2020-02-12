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
	bst.insert(0, 0).levelOrder();
	bst.insert(3, 0).levelOrder();
	bst.insert(5, 0).levelOrder();
	bst.insert(2, 0).levelOrder();
	bst.insert(55, 0).levelOrder();
	bst.remove(3);
	bst.inOrder();
	system("pause");
	return 0;
}