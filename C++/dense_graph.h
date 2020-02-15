#pragma once
#include "structure.h"
#include <vector>

namespace dataStruct {
	class DenseGraph {
	private:
		int n;
		int m;
		vector<vector<bool>> g;
		bool isDirected;
	public:
		DenseGraph(int n, bool isDirected) {
			this->n = n;
			m = 0;
			this->isDirected = isDirected;
			for (int i = 0; i < n; i++) {
				g.push_back(vector<bool>(n, false));
			}
		}

		~DenseGraph() {

		}

		int getSize() { return n; }
		int getEdge() { return m; }

		void addEdge(int v, int w) {
			assert(v >= 0 && v < n);
			assert(w >= 0 && w < n);
			if (hasEdge(v, w))
				return;
			g[v][w] = true;
			if (!isDirected)
				g[w][v] = true;
			m++;
		}

		bool hasEdge(int v, int w) {
			assert(v >= 0 && v < n);
			assert(w >= 0 && w < n);
			return g[v][w];
		}

		class adjIterator {
		private:
			DenseGraph& G;
			int v;
			int index;
		public:
			adjIterator(DenseGraph& dg, int v) :G(dg) {
				this->v = v;
				index = -1;
			}

			int begin() {
				index = -1;
				return next();
			}

			int next() {
				for (index += 1; !end(); index++) {
					if (G.g[v][index]) {
						return index;
					}
				}
				return -1;
			}

			bool end() {
				return index >= G.getSize();
			}
		};
	};
}