#include <iostream>
using namespace std;

template <typename T>
class Heap {
	T* data;
	int heapCapacity;
	int hSize;
public:
	Heap(int capacity) :heapCapacity(capacity) { data = new T[heapCapacity + 1]; hSize = 0; }
	T top() { return data[0]; }
	void pop()
	{
		data[0] = data[--hSize];
		for (int i = 0; i * 2 <= hSize;)
		{
			if ((i * 2 + 1) <= hSize)
			{
				if (data[i * 2] <= data[i * 2 + 1])
				{
					if (data[i] > data[i * 2])
					{
						swap(data[i], data[i * 2]);
						i *= 2;
					}
					else
					{
						break;
					}
				}
				else if (data[i * 2] > data[i * 2 + 1])	// if -> else if 로 변경
				{
					if (data[i] > data[i * 2 + 1])
					{
						swap(data[i], data[i * 2 + 1]);
						i = i * 2 + 1;	// i*=2+1; 에서 변경 i*=2+1 은 i*=(2+1) 이랑 같다
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				if (data[i] > data[i * 2])
				{
					swap(data[i], data[i * 2]);
					i *= 2;
				}
				else
				{
					break;
				}

			}
		}
	}
	void push(T n)
	{
		data[hSize] = n;
		for (int i = hSize; data[i] < data[i / 2]; i /= 2)
		{
			//if (data[i] > data[i / 2])
			//{
			swap(data[i], data[i / 2]);
			//}
		}
		hSize++;
	}
	int size() { return hSize; }
	bool empty() { if (size() == 0)return true; else return false; }
	void swap(T& a, T& b)
	{
		T t = a;
		a = b;
		b = t;
	}
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	Heap<int> heap(n);
	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		if (number == 0)
		{
			if (heap.empty() == false)
			{
				cout << heap.top() << "\n";
				heap.pop();
			}
			else
			{
				cout << "0" << "\n";
			}
		}
		else
		{
			heap.push(number);
		}
	}

	return 0;
}