#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

typedef long long ll;

using namespace std;

class MyHeap
{
public:
	MyHeap();
	~MyHeap();
	void push(int n);
	int pop();
	void swap(int& a, int& b) { int t = a; a = b; b = t; };
	bool comp(int a, int b) {
		if (abs(a) == abs(b))
			return a > b;
		else
			return abs(a) > abs(b);
	};
private:
	vector<int> vecData;
};

MyHeap::MyHeap()
{
	vecData.push_back(NULL);
}

MyHeap::~MyHeap()
{
}

void MyHeap::push(int n)
{
	vecData.push_back(n);
	int child = (int)vecData.size() - 1;
	int parent = child / 2;
	while (child > 1)
	{
		if (comp(vecData[parent], vecData[child]))
		{
			swap(vecData[parent], vecData[child]);
			child = parent;
			parent = child / 2;
		}
		else
			break;
	}
}

int MyHeap::pop()
{
	if (vecData.size() - 1 == 0)
	{
		return 0;
	}

	int result = vecData[1];
	swap(vecData[1], vecData[vecData.size() - 1]);
	vecData.pop_back();

	int parent = 1;
	int child = parent * 2;
	while ((ll)child + 1 <= (ll)vecData.size() - 1)
	{
		if ((ll)child + 1 <= (ll)vecData.size() - 1)
			child = comp(vecData[child], vecData[(ll)child + 1]) ? child + 1 : child;
		if (comp(vecData[parent], vecData[child]))
		{
			swap(vecData[parent], vecData[child]);
			parent = child;
			child = parent * 2;
		}
		else
			break;
	}
	return result;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//int a[6] = { 0,-1,-2,1,2 ,-2 };
	//sort(a, a + 6, [](int a, int b) {
	//	if (abs(a) == abs(b))
	//		return a > b;
	//	else
	//		return abs(a) > abs(b);
	//});
	//for (int i = 0; i < 6; i++)
	//{
	//	cout << a[i] << " ";
	//}

	MyHeap myHeap;
	int N;
	cin >> N;

	int* out = new int[N];
	fill(out, out + N, NULL);
	int outC = 0;

	int x;
	while (N--)
	{
		cin >> x;
		if (x == 0)
		{
			out[outC++] = myHeap.pop();
		}
		else
		{
			myHeap.push(x);
		}
	}

	for (int i = 0; i < outC; i++)
	{
		cout << out[i] << "\n";
	}

	return 0;
}