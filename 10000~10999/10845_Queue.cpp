#include <iostream>
#include <string>
using namespace std;

template <typename T>
class MyQueue;

template <typename T>
class MyNode {
	T data;
	MyNode* next=NULL;
	MyNode* prev=NULL;
public:
	MyNode(T d) :data(d) { ; }
	friend class MyQueue<T>;
};

template <typename T>
class MyQueue {
	MyNode<T>* head = NULL;
	MyNode<T>* tail = NULL;
	int size = 0;
public:
	void push(T a) {
		MyNode<T> *node = new MyNode<T>(a);
		if (head == NULL)
			head = node;
		else {
			node->prev = tail;
			tail->next = node;
		}
		tail = node;
		size++;
	}
	T pop(){
		if (head != NULL)
		{
			MyNode<T>* temp = head;
			if (head->next)
			{
				head->next->prev = NULL;
				head = head->next;
			}
			else {
				head = NULL;
				tail = NULL;
			}
			size--;
			T d = temp->data;
			delete temp;
			return d;
		}
		else
			return -1;
	}
	int getSize() { return size; }
	int empty() { if (size == 0) return 1; else return 0; }
	T front() { if (empty()) return -1; else return head->data; }
	T back() { if (empty()) return -1; else return tail->data; }
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	MyQueue<int> queue;
	int n;
	cin >> n;

	string command[] = { "push","pop", "size", "empty", "front", "back" };
	string str;
	while (n-- > 0)
	{
		cin >> str;
		int i = 0;
		for (i = 0;; i++)
			if (command[i] == str)
				break;
		switch (i)
		{
		case 0:
			int number;
			cin >> number;
			queue.push(number);
			break;
		case 1:
			cout<<queue.pop()<<"\n";
			break;
		case 2:
			cout << queue.getSize() << "\n";
			break;
		case 3:
			cout << queue.empty() << "\n";
			break;
		case 4:
			cout << queue.front() << "\n";
			break;
		case 5:
			cout << queue.back() << "\n";
			break;
		}
	}
	return 0;
}