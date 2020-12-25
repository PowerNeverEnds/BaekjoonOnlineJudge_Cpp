#include <iostream>
using namespace std;

template <typename T>
class Heap {
	T* data;
	int capacity;
	int size;
public:
	Heap(int capacity) :capacity(capacity) { data = new T[this->capacity + 1]; size = 0; }
	int getCapacity() { return capacity; }
	int getSize() { return size; }
	bool empty() { if (getSize() == 0) return true; else return false; }
	T top() { return data[0]; }
	void pop()
	{
		data[0] = data[--size];
		for (int i = 0; (i * 2) <= size;)
		{
			if ((i * 2 + 1) <= size)
			{
				if (data[i * 2] >= data[i * 2 + 1])
				{
					if (data[i] < data[i * 2])
					{
						swap(data[i], data[i * 2]);
						i *= 2;
					}
					else
					{
						break;
					}
				}
				else if (data[i * 2] < data[i * 2 + 1])
				{
					if (data[i] < data[i * 2 + 1])
					{
						swap(data[i], data[i * 2 + 1]);
						i = i * 2 + 1;
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				if (data[i] < data[i * 2])
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
		if (capacity > size)
		{
			data[size] = n;
			for (int i = size; (data[i] > data[i / 2]); i /= 2)
			{
				swap(data[i], data[i / 2]);
			}
			size++;
		}
		else
		{
			return;
		}
	}
	void swap(T& a, T& b)
	{
		T t = a;
		a = b;
		b = t;
	}
	void print()
	{
		for (int i = 0; i < getSize(); i++)
		{
			cout << data[i] << " ";
		}
		cout << "\n";
	}
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	Heap<int> heap(n);
	while (n-- > 0)
	{
		//cout << heap.getCapacity() << " " << heap.getSize() << "\n";
		int number;
		cin >> number;
		if (number == 0)
		{
			if (heap.empty())
			{
				cout << "0" << "\n";
			}
			else
			{
				cout << heap.top() << "\n";
				heap.pop();
			}
		}
		else
		{
			heap.push(number);
		}
		//heap.print();
	}

	return 0;
}