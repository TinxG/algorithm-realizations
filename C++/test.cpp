#include "bubble_sort.h"
#include "heap.h"
#include "quick_sort.h"
#include "binary_search.h"
#include "union_test.h"
#include "union_find.h"
#include "sparse_graph.h"
#include "dense_graph.h"

using namespace std;
using namespace algos;
using namespace testhelper;
using namespace dataStruct;

int main() {
	//在此添加测试代码
	int N = 20;
	int M = 100;
	srand(time(NULL));
	SparseGraph g(N, false);
	for (int i = 0; i < M; i++) {
		int v = rand() % N;
		int w = rand() % N;
		g.addEdge(v, w);
	}

	for (int v = 0; v < N; v++) {
		cout << v << ":";
		SparseGraph::adjIterator adji(g, v);
		for (int w = adji.begin(); !adji.end(); w = adji.next()) {
			cout << w << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	DenseGraph dg(N, false);
	for (int i = 0; i < M; i++) {
		int v = rand() % N;
		int w = rand() % N;
		dg.addEdge(v, w);
	}
	
	for (int v = 0; v < N; v++) {
		cout << v << ":";
		DenseGraph::adjIterator dadji(dg, v);
		for (int w = dadji.begin(); !dadji.end(); w = dadji.next()) {
			cout << w << " ";
		}
		cout << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}