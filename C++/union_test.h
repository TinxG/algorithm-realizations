#pragma once
#include "algo_test.h"
#include "union_find.h"

namespace testhelper {
	void testUF1(int sz) {
		dataStruct::UF1::UnionFind uf(sz);
		srand(time(NULL));
		clock_t start = clock();
		for (int i = 0; i < sz; i++) {
			int p = rand() % sz;
			int q = rand() % sz;
			uf.unionElements(p, q);
		}
		for (int i = 0; i < sz; i++) {
			int p = rand() % sz;
			int q = rand() % sz;
			uf.unionElements(p, q);
		}
		clock_t end = clock();
		cout << "UF1 TEST:" << sz << " ELEMENTS , " << (double)(end - start) / CLOCKS_PER_SEC << " s" << endl;
	}

	void testUF2(int sz) {
		dataStruct::UF2::UnionFind uf(sz);
		srand(time(NULL));
		clock_t start = clock();
		for (int i = 0; i < sz; i++) {
			int p = rand() % sz;
			int q = rand() % sz;
			uf.unionElements(p, q);
		}
		for (int i = 0; i < sz; i++) {
			int p = rand() % sz;
			int q = rand() % sz;
			uf.unionElements(p, q);
		}
		clock_t end = clock();
		cout << "UF2 TEST:" << sz << " ELEMENTS , " << (double)(end - start) / CLOCKS_PER_SEC << " s" << endl;
	}
}