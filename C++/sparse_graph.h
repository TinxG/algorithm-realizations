#pragma once
#include "structure.h"
#include <vector>

class SparseGraph {
private:
	int n, m;
	bool isDirected;
	vector<vector<int>> g;
public:
	SparseGraph(int n, bool isDirected) {
		this->n = n;
		m = 0;
		this->isDirected = isDirected;
		for (int i = 0; i < n; i++) {
			g.push_back(vector<int>());
		}
	}

	~SparseGraph() {

	}

	int geiSize() { return n; }
	int getEdge() { return m; }

	void addEdge(int v, int w) {
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		g[v].push_back(w);
		/*
		if (hasEdge(v, w)) {
			return;
		}
		*/
		if (v != w && !isDirected) {
			g[w].push_back(v);
		}
	}

	bool hasEdge(int v, int w) {
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		vector<int>::iterator it = find(g[v].begin(), g[v].end(), w);
		return it != g[v].end();
	}

	class adjIterator {
	private:
		int index;
		int v;
		SparseGraph& G;
	public:
		adjIterator(SparseGraph& sg, int v):G(sg) {
			this->v = v;
			index = 0;
		}

		int begin() {
			index = 0;
			if (G.g[v].size()) 
				return G.g[v][index];
			return -1;
		}

		int next() {
			if (!end()) {
				return G.g[v][++index];
			}
			return -1;
		}

		bool end() {
			return index >= G.g[v].size();
		}
	};
};