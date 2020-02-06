#pragma once
#include "structure.h"

namespace dataStruct
{
	template <class Item>
	struct IndexItem
	{
		int index;
		Item item;
	};

	template <class Item>
	class MaxHeap
	{
	private:
		void shiftUp(int loc)
		{
			while (loc > 1 && __Data[loc] > __Data[loc / 2])
			{
				swap(__Data[loc], __Data[loc / 2]);
				loc /= 2;
			}
		}

		void shiftDown(int loc)
		{
			while (loc * 2 <= __iSize)
			{
				int k = loc * 2;
				if (k + 1 <= __iSize && __Data[k + 1] > __Data[k])
					k += 1;

				if (__Data[loc] >= __Data[k])
					break;

				swap(__Data[loc], __Data[k]);
				loc = k;
			}
		}

		Item* __Data;
		int __iSize;
		int __iCapacity;

	public:
		MaxHeap(int capacity)
		{
			__Data = new Item[capacity + 1];
			__iSize = 0;
			__iCapacity = capacity;
		}

		MaxHeap(Item arr[], int length)
		{
			__Data = new Item[length + 1];
			__iCapacity = length;
			for (int i = 0; i < length; i++)
				__Data[i + 1] = arr[i];
			__iSize = length;
			for (int i = __iSize / 2; i >= 1; i--)
				shiftDown(i);
		}

		~MaxHeap()
		{
			delete[] __Data;
		}

		Item getItem(int index)
		{
			assert(index + 1 >= 1 && index + 1 <= __iSize);
			return __Data[index + 1];
		}

		int size()
		{
			return __iSize;
		}

		bool isEmpty()
		{
			return __iSize == 0;
		}

		MaxHeap& insert(Item item)
		{
			assert(__iSize + 1 <= __iCapacity);
			__Data[++__iSize] = item;
			shiftUp(__iSize);
			return *this;
		}

		void printAsArray()
		{
			for (int i = 1; i <= __iSize; i++)
			{
				cout << __Data[i] << " ";
			}
			cout << endl;
		}

		Item extract()
		{
			assert(!isEmpty());
			Item ext = __Data[1];
			__Data[1] = __Data[__iSize--];
			shiftDown(1);
			return ext;
		}
	};

	template <class Item>
	class MinHeap
	{
	private:
		void shiftUp(int loc)
		{
			while (loc > 1 && __Data[loc] < __Data[loc / 2])
			{
				swap(__Data[loc], __Data[loc / 2]);
				loc /= 2;
			}
		}

		void shiftDown(int loc)
		{
			while (loc * 2 <= __iSize)
			{
				int k = loc * 2;
				if (k + 1 <= __iSize && __Data[k + 1] < __Data[k])
					k += 1;

				if (__Data[loc] <= __Data[k])
					break;

				swap(__Data[loc], __Data[k]);
				loc = k;
			}
		}

		Item* __Data;
		int __iSize;
		int __iCapacity;

	public:
		MinHeap(int capacity)
		{
			__Data = new Item[capacity + 1];
			__iSize = 0;
			__iCapacity = capacity;
		}

		MinHeap(Item arr[], int length)
		{
			__Data = new Item[length + 1];
			__iCapacity = length;
			for (int i = 0; i < length; i++)
				__Data[i + 1] = arr[i];
			__iSize = length;
			for (int i = __iSize / 2; i >= 1; i--)
				shiftDown(i);
		}

		~MinHeap()
		{
			delete[] __Data;
		}

		Item getItem(int index)
		{
			assert(index + 1 >= 1 && index + 1 <= __iSize);
			return __Data[index + 1];
		}

		int size()
		{
			return __iSize;
		}

		bool isEmpty()
		{
			return __iSize == 0;
		}

		MinHeap& insert(Item item)
		{
			assert(__iSize + 1 <= __iCapacity);
			__Data[++__iSize] = item;
			shiftUp(__iSize);
			return *this;
		}

		void printAsArray()
		{
			for (int i = 1; i <= __iSize; i++)
			{
				cout << __Data[i] << " ";
			}
			cout << endl;
		}

		Item extract()
		{
			assert(!isEmpty());
			Item ext = __Data[1];
			__Data[1] = __Data[__iSize--];
			shiftDown(1);
			return ext;
		}
	};

	template <class Item>
	class IndexMinHeap
	{
	private:
		void shiftUp(int loc)
		{
			while (loc > 1 && __Data[__Index[loc]] < __Data[__Index[loc / 2]])
			{
				swap(__Index[loc], __Index[loc / 2]);
				__Rev[__Index[loc]] = loc;
				__Rev[__Index[loc / 2]] = loc / 2;
				loc /= 2;
			}
		}

		void shiftDown(int loc)
		{
			while (loc * 2 <= __iSize)
			{
				int k = loc * 2;
				if (k + 1 <= __iSize && __Data[__Index[k + 1]] < __Data[__Index[k]])
					k += 1;

				if (__Data[__Index[loc]] <= __Data[__Index[k]])
					break;

				swap(__Index[loc], __Index[k]);
				__Rev[__Index[loc]] = loc;
				__Rev[__Index[k]] = k;
				loc = k;
			}
		}

		Item* __Data;
		int* __Index;
		int* __Rev;
		int __iSize;
		int __iCapacity;

	public:
		IndexMinHeap(int capacity)
		{
			__Data = new Item[capacity + 1];
			__Index = new int[capacity + 1];
			__Rev = new int[capacity + 1];
			for (int i = 0; i <= __iCapacity; i++)
				__Rev[i] = 0;
			__iSize = 0;
			__iCapacity = capacity;
		}
		
		~IndexMinHeap()
		{
			delete[] __Data;
			delete[] __Index;
			delete[] __Rev;
		}

		int size()
		{
			return __iSize;
		}

		bool isEmpty()
		{
			return __iSize == 0;
		}

		IndexMinHeap& insert(int index,	Item item)
		{
			assert(__iSize + 1 <= __iCapacity);
			assert(index + 1 >= 1 && index + 1 <= __iCapacity);
			index++;
			__Data[index] = item;
			__Index[++__iSize] = index;
			__Rev[index] = __iSize;
			shiftUp(__iSize);
			return *this;
		}

		void printAsArray()
		{
			for (int i = 1; i <= __iSize; i++)
			{
				cout << __Data[__Index[i]] << " ";
			}
			cout << endl;
		}

		Item extractItem()
		{
			assert(!isEmpty());
			Item ext = __Data[__Index[1]];
			swap(__Index[1], __Index[__iSize--]);
			__Rev[__Index[1]] = 1;
			__Rev[__Index[__iSize + 1]] = 0;
			shiftDown(1);
			return ext;
		}

		int extractIndex()
		{
			assert(!isEmpty());
			int ext = __Index[1] - 1;
			swap(__Index[1], __Index[__iSize--]);
			__Rev[__Index[1]] = 1;
			__Rev[__Index[__iSize + 1]] = 0;
			shiftDown(1);
			return ext;
		}

		IndexItem<Item> extractIndexItem()
		{
			assert(!isEmpty());
			Item exti = __Data[__Index[1]];
			int ext = __Index[1] - 1;
			swap(__Index[1], __Index[__iSize--]);
			__Rev[__Index[1]] = 1;
			__Rev[__Index[__iSize + 1]] = 0;
			shiftDown(1);
			return { ext,exti };
		}

		bool isContain(int index)
		{
			assert(index + 1 >= 1 && index + 1 <= __iCapacity);
			return __Rev[index + 1] != 0;
		}

		Item getItem(int index)
		{
			assert(isContain(index));
			return __Data[index + 1];
		}

		IndexMinHeap& change(int index, Item ni)
		{
			assert(isContain(index));
			__Data[++index] = ni;
			/*
			for (int i = 1; i <= __iSize; i++)
			{
				if (__Index[i] == index)
				{
					shiftUp(i);
					shiftDown(i);
				}
			}
			*/
			int i = __Rev[index];
			shiftUp(i);
			shiftDown(i);
			return *this;
		}
	};

	template <class Item>
	class IndexMaxHeap
	{
	private:
		void shiftUp(int loc)
		{
			while (loc > 1 && __Data[__Index[loc]] > __Data[__Index[loc / 2]])
			{
				swap(__Index[loc], __Index[loc / 2]);
				__Rev[__Index[loc]] = loc;
				__Rev[__Index[loc / 2]] = loc / 2;
				loc /= 2;
			}
		}

		void shiftDown(int loc)
		{
			while (loc * 2 <= __iSize)
			{
				int k = loc * 2;
				if (k + 1 <= __iSize && __Data[__Index[k + 1]] > __Data[__Index[k]])
					k += 1;

				if (__Data[__Index[loc]] >= __Data[__Index[k]])
					break;

				swap(__Index[loc], __Index[k]);
				__Rev[__Index[loc]] = loc;
				__Rev[__Index[k]] = k;
				loc = k;
			}
		}

		Item* __Data;
		int* __Index;
		int* __Rev;
		int __iSize;
		int __iCapacity;

	public:
		IndexMaxHeap(int capacity)
		{
			__Data = new Item[capacity + 1];
			__Index = new int[capacity + 1];
			__Rev = new int[capacity + 1];
			for (int i = 0; i <= __iCapacity; i++)
				__Rev[i] = 0;
			__iSize = 0;
			__iCapacity = capacity;
		}

		~IndexMaxHeap()
		{
			delete[] __Data;
			delete[] __Index;
			delete[] __Rev;
		}

		int size()
		{
			return __iSize;
		}

		bool isEmpty()
		{
			return __iSize == 0;
		}

		IndexMaxHeap& insert(int index, Item item)
		{
			assert(__iSize + 1 <= __iCapacity);
			assert(index + 1 >= 1 && index + 1 <= __iCapacity);
			index++;
			__Data[index] = item;
			__Index[++__iSize] = index;
			__Rev[index] = __iSize;
			shiftUp(__iSize);
			return *this;
		}

		void printAsArray()
		{
			for (int i = 1; i <= __iSize; i++)
			{
				cout << __Data[__Index[i]] << " ";
			}
			cout << endl;
		}

		Item extractItem()
		{
			assert(!isEmpty());
			Item ext = __Data[__Index[1]];
			swap(__Index[1], __Index[__iSize--]);
			__Rev[__Index[1]] = 1;
			__Rev[__Index[__iSize + 1]] = 0;
			shiftDown(1);
			return ext;
		}

		int extractIndex()
		{
			assert(!isEmpty());
			int ext = __Index[1] - 1;
			swap(__Index[1], __Index[__iSize--]);
			__Rev[__Index[1]] = 1;
			__Rev[__Index[__iSize + 1]] = 0;
			shiftDown(1);
			return ext;
		}

		bool isContain(int index)
		{
			assert(index + 1 >= 1 && index + 1 <= __iCapacity);
			return __Rev[index + 1] != 0;
		}

		Item getItem(int index)
		{
			assert(isContain(index));
			return __Data[index + 1];
		}

		IndexMaxHeap& change(int index, Item ni)
		{
			assert(isContain(index));
			__Data[++index] = ni;
			/*
			for (int i = 1; i <= __iSize; i++)
			{
				if (__Index[i] == index)
				{
					shiftUp(i);
					shiftDown(i);
				}
			}
			*/
			int i = __Rev[index];
			shiftUp(i);
			shiftDown(i);
			return *this;
		}
	};

	template <class Item, int k = 2>
	class KMaxHeap
	{
	public:
		KMaxHeap(int capacity)
		{
			__Data = new Item[capacity + 1];
			__iCapacity = capacity;
			__iSize = 0;
		}

		~KMaxHeap()
		{
			delete[] __Data;
		}

		KMaxHeap& insert(Item dat)
		{
			assert(__iSize + 1 >= 1 && __iSize + 1 <= __iCapacity);
			__Data[++__iSize] = dat;
			shiftUp(__iSize);
			return *this;
		}

		Item extractItem()
		{
			assert(!isEmpty());
			Item ext = __Data[1];
			swap(__Data[1], __Data[__iSize--]);
			if (isEmpty())
				return ext;
			shiftDown(1);
			return ext;
		}

		bool isEmpty()
		{
			return __iSize == 0;
		}

		void printAsArray()
		{
			for (int i = 1; i <= __iSize; i++)
				cout << __Data[i] << " ";
			cout << endl;
		}
	private:
		Item* __Data;
		int __iCapacity;
		int __iSize;

		void shiftUp(int loc)
		{
			while ((loc+k-2)/k >= 1 && __Data[loc] > __Data[(loc+k-2)/k])
			{
				swap(__Data[loc], __Data[(loc+k-2)/k]);
				loc = (loc + k - 2) / k;
			}
		}

		void shiftDown(int loc)
		{
			while (loc * k - k + 2 <= __iSize)
			{
				int l = loc * k - k + 2;
				for (int i = l + 1; i <= __iSize; i++)
				{
					if (__Data[i] > __Data[l])
						l = i;
				}
				if (__Data[loc] >= __Data[l])
					break;
				swap(__Data[loc], __Data[l]);
				loc = l;
			}
		}
	};

	template <class Item>
	class DynamicMaxHeap
	{
	private:
		Item* __Data;
		int __iCapacity;
		int __iSize;

		void shiftUp(int loc)
		{
			Item v = __Data[loc];
			while (loc / 2 >= 1 && v > __Data[loc / 2])
			{
				__Data[loc] = __Data[loc / 2];
				loc /= 2;
			}
			__Data[loc] = v;
		}

		void shiftDown(int loc) 
		{
			while (loc * 2 <= __iSize)
			{
				int k = loc * 2;
				if (k + 1 <= __iSize && __Data[k + 1] > __Data[k])
					k += 1;
				if (__Data[loc] >= __Data[k])
					break;
				swap(__Data[loc], __Data[k]);
				loc = k;
			}
		}
	public:
		DynamicMaxHeap(int capacity = 100)
		{
			__Data = new Item[capacity + 1];
			__iCapacity = capacity;
			__iSize = 0;
		}

		DynamicMaxHeap(Item arr[], int length)
		{
			__Data = new Item[length + 1];
			__iCapacity = length;
			__iSize = length;
			for (int i = 1; i <= __iSize; i++)
				__Data[i] = arr[i - 1];
			for (int i = __iSize / 2; i >= 1; i--)
			{
				shiftDown(i);
			}
		}

		~DynamicMaxHeap()
		{
			delete[] __Data;
		}

		void printAsArray()
		{
			for (int i = 1; i <= __iSize; i++)
				cout << __Data[i] << " ";
			cout << endl;
			
		}

		int getCapacity()
		{
			return __iCapacity;
		}

		int getSize()
		{
			return __iSize;
		}

		bool isEmpty()
		{
			return __iSize == 0;
		}

		void expandCapacity(int extra)
		{
			Item* temp = new Item[__iCapacity + 1 + extra];
			for (int i = 1; i <= __iSize; i++)
			{
				temp[i] = __Data[i];
			}
			delete[] __Data;
			__Data = temp;
			temp = NULL;
			__iCapacity += extra;
		}

		DynamicMaxHeap& insert(Item item)
		{
			if (__iSize + 1 > __iCapacity)
				expandCapacity(5);
			__Data[++__iSize] = item;
			shiftUp(__iSize);
			return *this;
		}

		Item extractItem()
		{
			assert(!isEmpty());
			Item ext = __Data[1];
			swap(__Data[__iSize--], __Data[1]);
			shiftDown(1);
			return ext;
		}
	};

	enum printWay
	{
		MaxIndex,
		MinIndex
	};

	//base on IndexHeap
	template <class Item>
	class MaxMinHeap
	{
	public:
		MaxMinHeap(int capacity)
		{
			__Data = new Item[capacity + 1];
			__MaxIndex = new int[capacity + 1];
			__MinIndex = new int[capacity + 1];
			__iCapacity = capacity;
			__iSize = 0;
		}

		~MaxMinHeap()
		{
			delete[] __Data;
			delete[] __MaxIndex;
			delete[] __MinIndex;
		}

		void printAsArray(printWay pw)
		{
			switch (pw)
			{
			case MaxIndex:
				for (int i = 1; i <= __iSize; i++)
					cout << getItem(__MaxIndex[i]-1) << " ";
				cout << endl;
				return;
			case MinIndex:
				for (int i = 1; i <= __iSize; i++)
					cout << getItem(__MinIndex[i]-1) << " ";
				cout << endl;
				return;
			default:
				return;
			}
		}

		Item getItem(int index)
		{
			assert(isContain(index + 1));
			return __Data[index + 1];
		}

		int getSize()
		{
			return __iSize;
		}

		int getCapacity()
		{
			return __iCapacity;
		}

		bool isEmpty()
		{
			return __iSize == 0;
		}

		bool isContain(int index)
		{
			bool flag = false;
			for (int i = 1; i <= __iSize; i++)
			{
				if (index == __MaxIndex[i] || index == __MinIndex[i])
				{
					flag = true;
					break;
				}
			}
			return flag;
		}

		MaxMinHeap& insert(int index, Item dat)
		{
			assert(__iSize + 1 <= __iCapacity);
			assert(index + 1 >= 1 && index + 1 <= __iCapacity);
			__Data[++index] = dat;
			__MaxIndex[++__iSize] = index;
			__MinIndex[__iSize] = index;
			shiftUpMax(__iSize);
			shiftUpMin(__iSize);
			return *this;
		}

		/*
         * TODO:
		 * extractMaxItem()
		 * extractMaxIndex()
		 * shiftDownMax()
		 * shiftDownMin()
		 * if possible:
		 * change()
		 * __MaxRev
		 * __MinRev
		 * 
		 */
	private:
		Item* __Data;
		int __iCapacity;
		int __iSize;
		int* __MaxIndex;
		int* __MinIndex;

		void shiftUpMax(int idx)
		{
			while (idx / 2 >= 1 && __Data[__MaxIndex[idx]] > __Data[__MaxIndex[idx / 2]])
			{
				swap(__MaxIndex[idx], __MaxIndex[idx / 2]);
				idx /= 2;
			}
		}

		void shiftUpMin(int idx)
		{
			while (idx / 2 >= 1 && __Data[__MinIndex[idx]] < __Data[__MinIndex[idx / 2]])
			{
				swap(__MinIndex[idx], __MinIndex[idx / 2]);
				idx /= 2;
			}
		}
	};
}


