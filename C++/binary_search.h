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

			Node(Key key, Value value) {
				this->key = key;
				this->value = value;
				this->left = nullptr;
				this->right = nullptr;
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
			return node;
		}

		//迭代方式
		void removeMinI(Node* node) {
			while (node->left->left != nullptr) {
				node = node->left;
			}
			Node* ri = node->left->right;
			delete node->left;
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
			return node;
		}

		void removeMaxI(Node* node) {
			while (node->right->right != nullptr) {
				node = node->right;
			}
			Node* le = node->right->left;
			delete node->right;
			__iSize--;
			node->right = le;
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
	};
}