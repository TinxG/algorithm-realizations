#pragma once
#include "structure.h"

namespace dataStruct {

	class UnF {
	public:
		virtual int find(int p) = 0;
		virtual bool isConnected(int p, int q) = 0;
		virtual void unionElements(int p, int q) = 0;
	};

	namespace UF1 {
		class UnionFind:public UnF {
		private:
			int* id;
			int sz;
		public:
			UnionFind(int sz) {
				this->sz = sz;
				id = new int[sz];
			}

			~UnionFind() {
				delete[] id;
			}

			int find(int p) {
				assert(p >= 0 && p < sz);
				return id[p];
			}

			bool isConnected(int p, int q) {
				assert(p >= 0 && p < sz);
				assert(q >= 0 && q < sz);
				return id[p] == id[q];
			}

			void unionElements(int p, int q) {
				assert(p >= 0 && p < sz);
				assert(q >= 0 && q < sz);
				int pId = id[p];
				int qId = id[q];
				for (int i = 0; i < sz; i++) {
					if (id[i] == pId) {
						id[i] = qId;
					}
				}
			}
		};
	}

	namespace UF2 {
		class UnionFind {
		private:
			int* parent;
			int sz;
		public:
			UnionFind(int sz) {
				parent = new int[sz];
				this->sz = sz;
				for (int i = 0; i < sz; i++) {
					parent[i] = i;
				}
			}

			~UnionFind() {
				delete[] parent;
			}

			int find(int p) {
				assert(p >= 0 && p < sz);
				/*
				if (p == parent[p]) {
					return p;
				}
				return find(parent[p]);
				*/
				while (p != parent[p]) {
					p = parent[p];
				}
				return p;
			}

			bool isConnected(int p, int q) {
				assert(p >= 0 && p < sz);
				assert(q >= 0 && q < sz);
				return find(p) == find(q);
			}

			void unionElements(int p, int q) {
				assert(p >= 0 && p < sz);
				assert(q >= 0 && q < sz);
				int rootP = find(p);
				int rootQ = find(q);
				if (rootP == rootQ) {
					return;
				}
				parent[rootP] = rootQ;
			}
		};
	}
}