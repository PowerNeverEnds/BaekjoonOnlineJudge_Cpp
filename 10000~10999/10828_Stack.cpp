#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack {
	T* data;
	int size;
	int sizeOfStack;
public:
	Stack() { size = 0; sizeOfStack = 1; expandStack(); }
	~Stack() { delete[] data; }
	void push(T x){
		if (size  == sizeOfStack)
			expandStack();
		data[size++] = x;
	}
	void expandStack() {
		T* temp = new T[++sizeOfStack];
		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}
		swap(temp, data);
		delete[] temp;
	}
	int getSize() { return size; }
	void mySwap(T& a, T& b)
	{
		T t = a;
		a = b;
		b = t;
	}
	T pop() {
		if (size > 0) return data[--size];
		else return -1;
	}
	int empty() {
		return size == 0 ? 1 : 0;
	}
	T top() {
		if (size > 0) return data[size - 1];
		else return -1;
	}

};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	Stack<int> stack;

	string command[] = {"push","pop","size","empty","top"};

	while (n-- > 0)
	{
		string str;
		cin >> str;
		int i = 0;
		for (;; i++)
			if (command[i] == str)
				break;
		switch (i) {
		case 0:
			int number;
			cin >> number;
			stack.push(number);
			break;
		case 1:
			cout << stack.pop() << "\n";
			break;
		case 2:
			cout << stack.getSize() << "\n";
			break;
		case 3:
			cout << stack.empty() << "\n";
			break;
		case 4:
			cout << stack.top() << "\n";
			break;
		}
	}

	return 0;
}