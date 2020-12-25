/*
힙 공부후, pop하는부분 코딩하다보니, 동기화에 오류가있음.
min-max-heap 자료구조 공부 하려다,
다른 방법 찾음.

1. map 은 sorted를 보장하고 또 begin() 부터 end() 까지 오름차순으로 증가하기때문에 (default less<type>)
Insert가 들어오면 맵에 삽입
Delete가 들어오면 해당 숫자에 대한 밸류를 찾아서 -1 (0 이면 삭제)
하고 최소 최대를 출력하는 방식입니다.
https://www.acmicpc.net/board/view/532

2. 완전이진탐색트리(binary Search Tree)
AVL 트리(균형잡힌이진트리)
레드-블랙 트리(자가균형이진탐색트리)

3. min-max-heap
https://www.youtube.com/watch?v=5ZP8uxdp564

4. mutiset 사용

*/

//	3.min-max-heap
//	https://www.youtube.com/watch?v=5ZP8uxdp564
#include <iostream>
#include <vector>

typedef long long ll;

#define MIN_LEVEL 0
#define MAX_LEVEL 1

using namespace std;

void mySwap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

bool myGreater(int a, int b)
{
	return a < b;
}
bool myLess(int a, int b)
{
	return a > b;
}

struct MyMinMaxHeap
{
	vector<int> vec;

	MyMinMaxHeap()
	{
		vec.push_back(NULL);
	}

	int findLevel(int n)
	{
		int level = 0;
		while (n /= 2) { level++; };
		return level;
	}

	void print()
	{
		for (int i = 1; i < vec.size(); i++)
			cout << vec[i] << " ";
		cout << "\n";
	}

	bool empty() { return (vec.size() == 1); }
	int printMax() {
		if (vec.size()==1)
			return 0;
		else
		{
			if (vec.size() > 3)
				return myMax(vec[2], vec[3]);
			else
				return vec.back();
		}
	}
	int printMin() {
		if (vec.size()==1)
			return 0;
		else
			return vec[1];
	}

	void push(int n)
	{
		vec.push_back(n);
		int child = (int)vec.size() - 1;
		int parent = child / 2;
		//	If the new node is on a min-level
		int level = findLevel(child);
		//cout << level << "\n";
		//print();
		if (parent == 0)
			return;
		if (level % 2 == MIN_LEVEL)
		{
			//	If new node's parent is smaller than it then swap their value
			//	and 'UpHeapMax' from its parent.
			if (vec[parent] < vec[child])
			{
				mySwap(vec[parent], vec[child]);
				upHeapMax(parent);
			}
			//	Else 'UpHeapMin' from the new node
			else
			{
				upHeapMin(child);
			}
		}
		//	If the new node is on a max-level
		else
		{
			//	If new node's parent is larger than it then swap their value
			//	and 'UpHeapMin' from its parent.
			if (vec[parent] > vec[child])
			{
				mySwap(vec[parent], vec[child]);
				upHeapMin(parent);
			}
			//	Else 'upHeapMax' from the new node
			else
			{
				upHeapMax(child);
			}
		}
	}

	void upHeapMin(int node)
	{
		upHeap(node, myLess);
		//upHeap(node, [](auto gp, auto n) {return gp > n; });
	}
	void upHeapMax(int node)
	{
		upHeap(node, myGreater);
		//upHeap(node, [](auto gp, auto n) {return gp < n; });
	}

	void upHeap(int node, bool(*comp)(int, int))
	{

		int grandParent = node / 4;
		while (grandParent >= 1 && comp(vec[grandParent], vec[node]))
		{
			//cout << "upHeap" << " " << node << "\n";
			mySwap(vec[node], vec[grandParent]);
			node = grandParent;
			grandParent = node / 4;
		}
	}

	//	Deletion of the smallest element
	int pop_min()
	{
		int t;
		if (vec.size()==1)
			return 0;
		t = vec[1];
		//	Replace root with the last element in heap.
		mySwap(vec[1], vec.back());
		//	Derease the number of element in heap.
		vec.pop_back();
		//	 DownHeapmin from root.
		downHeapMin(1);
		return t;
	}
	int myMax(int a, int b)
	{
		return a > b ? a : b;
	}

	//	Delection of the largest element
	int pop_max()
	{
		int t;
		if (vec.size()==1)
			return 0;
	
		//	Replace either left-child or right child of root (depends on
		//	which one is larger) with the last element in heap.
		//	use -> mySwap
		
		//	Decrease the number of element in heap.
		//	use -> pop_back 
		
		//	Downheapmax from node.
		if (vec.size() > 3)
		{
			t = myMax(vec[2], vec[3]);
			if (vec[2] > vec[3])
			{
				mySwap(vec[2], vec.back());
				vec.pop_back();
				downHeapMax(2);
			}
			else
			{
				mySwap(vec[3], vec.back());
				vec.pop_back();
				downHeapMax(3);
			}
		}
		else
		{
			t = vec.back();
			vec.pop_back();

		}
		return t;
	}

	void downHeapMax(int node)
	{
		downHeap(node, myGreater);
	}
	void downHeapMin(int node)
	{
		downHeap(node, myLess);
	}

	//	This comment describes 'Downheapmax' .

	//	'DownHeapmin' is the same except that the relational
	//	operators are reversed.
	void downHeap(int node, bool(*comp)(int,int))
	{
		int tNode = node * 2;
		if (tNode >= vec.size())
			return;
		int maxNum = vec[tNode];
		int maxNode = tNode;
		while (true)
		{
			tNode = node * 2;
			if (tNode >= vec.size())
				break;
			maxNum = vec[tNode];
			maxNode = tNode;

			// Let m is the largest element in current node's children and grandchildren
			//	(if any).
			for (int k = 2; k <= 4; k += 2)
			{
				tNode = node * k;
				for (int i = 0; i < k; i++)
				{
					if ((ll)tNode + i >= (ll)vec.size())
						break;
					if (comp(maxNum, vec[(ll)tNode + i]))
					{
						maxNum = vec[(ll)tNode + i];
						maxNode = tNode + i;
					}
				}
			}
			//	If m is grandchildren of current node than
			if (maxNode >= node * 4)
			{
				//	if m is larger than current node then
				if (comp(vec[node], vec[maxNode]))
				{
					//	swap their value
					mySwap(vec[node], vec[maxNode]);
					//	If m is smaller than its parent then swap their value
					if (comp(vec[maxNode], vec[maxNode / 2]))
					{
						mySwap(vec[maxNode], vec[maxNode / 2]);
					}
					// Continue downheapmax from m
					node = maxNode;
				}
				else
					break;
			}
			//	If m is children of current node  then
			else
			{
				//	If m is larger than current node then
				if (comp(vec[node], vec[maxNode]))
				{
					//	Swap their value
					mySwap(vec[node], vec[maxNode]);
				}
				break;
			}
		}

	}
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//myMinMaxHeap.push(8);
	//myMinMaxHeap.push(35);
	//myMinMaxHeap.push(28);
	//myMinMaxHeap.push(14);
	//myMinMaxHeap.push(27);
	//myMinMaxHeap.push(9);
	//myMinMaxHeap.push(26);
	//myMinMaxHeap.push(30);
	//myMinMaxHeap.push(22);

	//myMinMaxHeap.print();

	//cout<<myMinMaxHeap.pop_max()<<"\n";
	//
	//myMinMaxHeap.print();

	//cout<<myMinMaxHeap.pop_min()<<"\n";
	//
	//myMinMaxHeap.print();

	int T;
	cin >> T;
	while (T--)
	{
		MyMinMaxHeap myMinMaxHeap;
		int Q;
		cin >> Q;
		while (Q--)
		{
			//cout << "print" << "\n";
			//myMinMaxHeap.print();
			char oper;
			int n;
			cin >> oper >> n;
			switch (oper)
			{
			case 'I':
				myMinMaxHeap.push(n);
				break;
			case 'D':
				switch (n)
				{
				case 1:
					myMinMaxHeap.pop_max();
					break;
				case -1:
					myMinMaxHeap.pop_min();
					break;
				default:
					break;
				}
			default:
				break;
			}
		}
		if (myMinMaxHeap.empty())
			cout << "EMPTY" << "\n";
		else
			cout << myMinMaxHeap.printMax() << " " << myMinMaxHeap.printMin() << "\n";
	}
	
	return 0;
}

/*
#include <iostream>
#include <map>
using namespace std;

int main()
{

	return 0;
}
*/


/*
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MyHeap
{
public:
	MyHeap(bool (*c)(T, T));
	~MyHeap();
	void push(T data);
	void swap(T& a, T& b) { T t = a; a = b; b = t; };
	T pop();
	void show() { for (auto e : vec)  cout << e << " "; cout << "\n"; }
private:
	vector<T> vec;
	bool (*comp)(T, T);
};

template <typename T>
MyHeap<T>::MyHeap(bool (*c)(T,T)) : comp(c)
{
	vec.push_back(NULL);
}

template <typename T>
MyHeap<T>::~MyHeap()
{
}

template <typename T>
void MyHeap<T>::push(T data)
{
	vec.push_back(data);
	int child = (int)vec.size() - 1;
	int parent = child / 2;
	while (child > 1 && comp(vec[parent], vec[child]))
	{
		swap(vec[parent], vec[child]);
		child = parent;
		parent = child / 2;
	}
}

template <typename T>
T MyHeap<T>::pop()
{
	T t = vec[1];

	swap(vec[1], vec[vec.size() - 1]);
	vec.pop_back();

	int parent = 1;
	int child = parent * 2;
	if ((long long)child + 1 <= (long long)vec.size() - 1)
	{
		child = comp(vec[child], vec[(long long)child + 1]) ? vec[(long long)child + 1] : vec[child];
	}

	return t;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		MyHeap<int> maxHeap([](auto a, auto b) {return a < b; });
		MyHeap<int> minHeap([](auto a, auto b) {return a > b; });
		int k;
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			char oper;
			int n;
			cin >> oper >> n;
			switch (oper)
			{
			case 'D':
				switch (n)
				{
				case 1:
					maxHeap.pop();
					break;
				case -1:
					minHeap.pop();
					break;
				default:
					break;
				}
				break;
			case 'I':
				maxHeap.push(n);
				minHeap.push(n);
				break;
			default:
				break;
			}
			maxHeap.show();
			minHeap.show();
		}
	}
	return 0;
}

*/