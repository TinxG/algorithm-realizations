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
		class UnionFind:public UnF {
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

	namespace UF3 {
		class UnionFind:public UnF {
		private:
			int* parent;
			int* count;
			int sz;
		public:
			UnionFind(int sz) {
				parent = new int[sz];
				count = new int[sz];
				this->sz = sz;
				for (int i = 0; i < sz; i++) {
					parent[i] = i;
					count[i] = 1;
				}
			}

			~UnionFind() {
				delete[] parent;
				delete[] count;
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
				if (count[rootP] < count[rootQ]) {
					parent[rootP] = rootQ;
					count[rootQ] += count[rootP];
				}
				else {
					parent[rootQ] = rootP;
					count[rootP] += count[rootQ];
				}
			}
		};
	}

	namespace UF4 {
		class UnionFind :public UnF {
		private:
			int* parent;
			int* rank;
			int sz;
		public:
			UnionFind(int sz) {
				parent = new int[sz];
				rank = new int[sz];
				this->sz = sz;
				for (int i = 0; i < sz; i++) {
					parent[i] = i;
					rank[i] = 1;
				}
			}

			~UnionFind() {
				delete[] parent;
				delete[] rank;
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
				if (rank[rootP] < rank[rootQ]) {
					parent[rootP] = rootQ;
				}
				else if(rank[rootP] > rank[rootQ]) {
					parent[rootQ] = rootP;
				}
				else {
					parent[rootP] = rootQ;
					rank[rootQ] += 1;
				}
			}
		};
	}

	namespace UF5 {
		class UnionFind :public UnF {
		private:
			int* parent;
			int* rank;
			int sz;
		public:
			UnionFind(int sz) {
				parent = new int[sz];
				rank = new int[sz];
				this->sz = sz;
				for (int i = 0; i < sz; i++) {
					parent[i] = i;
					rank[i] = 1;
				}
			}

			~UnionFind() {
				delete[] parent;
				delete[] rank;
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
					parent[p] = parent[parent[p]];
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
				if (rank[rootP] < rank[rootQ]) {
					parent[rootP] = rootQ;
				}
				else if (rank[rootP] > rank[rootQ]) {
					parent[rootQ] = rootP;
				}
				else {
					parent[rootP] = rootQ;
					rank[rootQ] += 1;
				}
			}
		};
	}

	namespace UF6 {
		class UnionFind :public UnF {
		private:
			int* parent;
			int* rank;
			int sz;
		public:
			UnionFind(int sz) {
				parent = new int[sz];
				rank = new int[sz];
				this->sz = sz;
				for (int i = 0; i < sz; i++) {
					parent[i] = i;
					rank[i] = 1;
				}
			}

			~UnionFind() {
				delete[] parent;
				delete[] rank;
			}

			int find(int p) {
				assert(p >= 0 && p < sz);
				
				if (p != parent[p]) {
					parent[p] = find(parent[p]);
				}
				return parent[p];
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
				if (rank[rootP] < rank[rootQ]) {
					parent[rootP] = rootQ;
				}
				else if (rank[rootP] > rank[rootQ]) {
					parent[rootQ] = rootP;
				}
				else {
					parent[rootP] = rootQ;
					rank[rootQ] += 1;
				}
			}
		};
	}
}