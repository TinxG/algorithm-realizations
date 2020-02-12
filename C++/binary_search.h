#pragma once
#include "algo_test.h"
#include <queue>

namespace algos {
	//二分查找法（迭代）
	//数组arr必须为升序有序数组
	template <typename T>
	int binarySearchA(T arr[], int length, T target) {
		//查找区间[l,r]
		int l = 0, r = length - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (arr[mid] == target) {
				return mid;
			}
			else if (arr[mid] > target) {
				r = mid - 1;
				continue;
			}
			else {
				l = mid + 1;
				continue;
			}
		}
		return -1;
	}

	//递归函数
	template <typename T>
	int __binarySearch(T arr[], int l, int r, T target) {
		if (l > r)
			return -1;
		int mid = (r - l) / 2 + l;
		if (target == arr[mid])
			return mid;
		else if (target < arr[mid])
			return __binarySearch(arr, l, mid - 1, target);
		else
			return __binarySearch(arr, mid + 1, r, target);
	}

	//采用递归的二分查找法
	//数组arr必须为升序有序数组
	template <typename T>
	int binarySearchB(T arr[], int length, T target) {
		return __binarySearch(arr, 0, length - 1, target);
	}

	//ceil，二分查找法的变种
	//有重复目标元素时，查找到的是最后一个
	//不存在目标时，查找到的是比目标大的最小元素
	template <typename T>
	int binarySearchCeil(T arr[], int length, T target) {
		//区间[l,r)
		int l = 0, r = length;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (arr[mid] <= target) {
				l = mid + 1;
				continue;
			}
			else {
				r = mid;
				continue;
			}
		}
		assert(l == r);
		if (r - 1 >= 0 && arr[r - 1] == target)
			return r - 1;
		return r;
	}

	//floor，二分查找法的变种
	//有重复目标元素时，查找到的是第一个
	//不存在目标时，查找到的是比目标小的最后一个
	template <typename T>
	int binarySearchFloor(T arr[], int length, T target) {
		//区间(l,r]
		int l = -1, r = length - 1;
		while (l < r) {
			int mid = l + (r - l + 1) / 2;
			if (arr[mid] >= target) {
				r = mid - 1;
				continue;
			}
			else {
				l = mid;
				continue;
			}
		}
		assert(l == r);
		if (l + 1 < length && arr[l + 1] == target)
			return l + 1;
		return l;
	}

	
}

namespace dataStruct {
	//BinarySearchTree，二分查找树
	//每个节点都大于左子节点，小于右子节点
	//不必要是一棵完全二叉树
	template <typename Key, typename Value>
	class BST {
	private:
		struct Node {
			Key key;
			Value value;
			Node* left;
			Node* right;
			int n;
			int height;

			Node(Key key, Value value) {
				this->key = key;
				this->value = value;
				n = 1;
				height = 1;
				this->left = nullptr;
				this->right = nullptr;
			}

			Node(const Node* node) {
				this->key = node->key;
				this->value = node->value;
				this->left = node->left;
				this->right = node->right;
				this->n = node->n;
				this->height = node->height;
			}

			~Node() {
				/*
				if (left != nullptr)
					delete left;
				if (right != nullptr)
					delete right;
				*/
			}
		};

		Node* root;
		int __iSize;

		int size(Node* node) {
			if (node == nullptr) {
				return 0;
			}
			return node->n;
		}

		Node* insert(Node* node, Key key, Value value) {
			if (node == nullptr) {
				__iSize++;
				return new Node(key, value);
			}

			if (node->key == key) {
				node->value = value;
			}
			else if (node->key > key) {
				node->left = insert(node->left, key, value);
			}
			else {
				node->right = insert(node->right, key, value);
			}

			node->n = size(node->left) + size(node->right) + 1;

			return node;
		}

		bool isContain(Node* node, Key key) {
			if (node == nullptr)
				return false;

			if (node->key == key)
				return true;
			else if (node->key > key)
				return isContain(node->left, key);
			else
				return isContain(node->right, key);
		}

		Value search(Node* node, Key key) {
			if (node == nullptr) {
				return NULL;
			}

			if (node->key == key)
				return node->value;
			else if (node->key > key)
				return search(node->left, key);
			else
				return search(node->right, key);
		}

		void preOrder(Node* node) {
			if (node != nullptr) {
				cout << node->key << endl;
				preOrder(node->left);
				preOrder(node->right);
			}
		}

		void inOrder(Node* node) {
			if (node != nullptr) {
				inOrder(node->left);
				cout << node->key << endl;
				inOrder(node->right);
			}
		}

		void postOrder(Node* node) {
			if (node != nullptr) {
				postOrder(node->left);
				postOrder(node->right);
				cout << node->key << endl;
			}
		}

		void destroy(Node* node) {
			if (node != nullptr) {
				destroy(node->left);
				destroy(node->right);
				delete node;
			}
		}

		void levelOrder(Node* node) {
			queue<Node*> q;
			q.push(root);
			while (!q.empty()) {
				Node* n = q.front();
				q.pop();
				cout << n->key << endl;
				if (n->left != nullptr)
					q.push(n->left);
				if (n->right != nullptr)
					q.push(n->right);
			}
		}

		Node* minimum(Node* node) {
			if (node->left == nullptr)
				return node;
			return minimum(node->left);
		}

		//迭代方式
		Node* minimumI(Node* node) {
			while (node->left != nullptr) {
				node = node->left;
			}
			return node;
		}

		Node* maximum(Node* node) {
			if (node->right == nullptr)
				return node;
			return maximum(node->right);
		}

		//迭代方式
		Node* maximumI(Node* node) {
			while (node->right != nullptr) {
				node = node->right;
			}
			return node;
		}

		Node* removeMin(Node* node) {
			if (node->left == nullptr) {
				Node* ri = node->right;
				delete node;
				__iSize--;
				return ri;
			}

			node->left = removeMin(node->left);
			node->n = size(node->left) + size(node->right) + 1;
			return node;
		}

		//迭代方式
		void removeMinI(Node* node) {
			while (node->left->left != nullptr) {
				node->n--;
				node = node->left;
			}
			Node* ri = node->left->right;
			delete node->left;
			node->n--;
			__iSize--;
			node->left = ri;
		}

		Node* removeMax(Node* node) {
			if (node->right == nullptr) {
				Node* le = node->left;
				delete node;
				__iSize--;
				return le;
			}

			node->right = removeMax(node->right);
			node->n = size(node->left) + size(node->right) + 1;
			return node;
		}

		void removeMaxI(Node* node) {
			while (node->right->right != nullptr) {
				node->n--;
				node = node->right;
			}
			Node* le = node->right->left;
			delete node->right;
			node->n--;
			__iSize--;
			node->right = le;
		}

		Node* remove(Node* node, Key key) {
			if (node == nullptr) {
				return nullptr;
			}

			if (key < node->key) {
				node->left = remove(node->left, key);
				
			}
			else if (key > node->key) {
				node->right = remove(node->right, key);
				
			}
			else {
				Node* successor = new Node(minimum(node->right));
				__iSize++;

				successor->right = removeMin(node->right);
				successor->left = node->left;

				delete node;
				__iSize--;
				successor->n = size(successor->left) + size(successor->right) + 1;
				return successor;
			}
			node->n = size(node->left) + size(node->right) + 1;
			return node;
		}

		//使用前驱节点的Hubbard Deletion
		Node* removeP(Node* node, Key key) {
			if (node == nullptr) {
				return nullptr;
			}

			if (key < node->key) {
				node->left = remove(node->left, key);
				
			}
			else if (key > node->key) {
				node->right = remove(node->right, key);
				
			}
			else {
				Node* predeccesor = new Node(maximum(node->left));
				__iSize++;
				
				predeccesor->left = removeMax(node->left);
				predeccesor->right = node->right;

				delete node;
				__iSize--;

				predeccessor = size(predecessor->left) + size(predeccessor->right) + 1;
				return predeccesor;
			}
			node->n = size(n->left) + size(n->right) + 1;
			return node;
		}

		Node* floor(Node* node, Key key) {
			if (node == nullptr) {
				return node;
			}

			if (key < node->key) {
				return floor(node->left, key);
			}
			else if (key == node->key) {
				return node;
			}
			else {
				Node* temp = floor(node->right, key);
				return temp != nullptr ? temp : node;
			}

		}

		Node* ceil(Node* node, Key key) {
			if (node == nullptr) {
				return nullptr;
			}

			if (key > node->key) {
				return floor(node->right, key);
			}
			else if (key == node->key) {
				return node;
			}
			else {
				Node* temp = floor(node->left, key);
				return temp != nullptr ? temp : node;
			}
		}

		int rank(Node* node, Key key) {
			if (node == nullptr) {
				return NULL;
			}

			if (key < node->key) {
				return rank(node->left, key);
			}
			else if (key > node->key) {
				return rank(node->right, key) + size(node->left) + 1;
			}
			else {
				return size(node->left) + 1;
			}
		}

		Node* select(Node* node, int rank) {
			if (node == nullptr) {
				return NULL;
			}

			if (rank <= size(node->left)) {
				return select(node->left, rank);
			}
			else {
				if (rank == size(node->left) + 1) {
					return node;
				}
				else {
					return select(node->right, rank - size(node->left) - 1);
				}
			}
		}

	public:
		BST() {
			root = nullptr;
			__iSize = 0;
		}

		~BST() {
			//delete root;
			destroy(root);
		}

		int getSize() {
			return __iSize;
		}

		bool isEmpty() {
			return __iSize == 0;
		}

		BST& insert(Key key, Value value) {
			root = insert(root, key, value);
			return *this;
		}

		bool isContain(Key key) {
			return isContain(root, key);
		}

		Value operator[](Key key) {
			assert(isContain(key));
			return search(root, key);
		}

		void preOrder() {
			preOrder(root);
		}

		void inOrder() {
			inOrder(root);
		}

		void postOrder() {
			postOrder(root);
		}

		void levelOrder() {
			levelOrder(root);
		}

		Key minimum() {
			assert(__iSize != 0);
			Node* minNode = minimum(root);
			return minNode->key;
		}

		Key maximum() {
			assert(__iSize != 0);
			Node* maxNode = maximum(root);
			return maxNode->key;
		}

		void removeMin() {
			if (root != nullptr) {
				root = removeMin(root);
			}
		}

		void removeMax() {
			if (root != nullptr) {
				root = removeMax(root);
			}
		}

		void remove(Key key) {
			root = remove(root, key);
		}

		Key floor(Key key) {
			if (isEmpty() || minimum() > key) {
				return NULL;
			}
			return floor(root, key)->key;
		}

		Key ceil(Key key) {
			if (isEmpty() || maximum() < key) {
				return NULL;
			}
			return ceil(root, key)->key;
		}

		int rank(Key key) {
			if (!isContain(key)) {
				return NULL;
			}
			return rank(root, key);
		}

		Key select(int rank) {
			if (rank > __iSize) {
				return NULL;
			}
			return select(root, rank)->key;
		}
	};
}