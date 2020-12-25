#include <iostream>
#include <string>
using namespace std;

template <typename T>
class MyDeque;

template <typename T>
class Node {
	T data;
	Node* next;
	Node* prev;
public:
	Node(T a = NULL) :data(a) {	next = NULL; prev = NULL;}
	friend class MyDeque<T>;
};

template <typename T>
class MyDeque {
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	MyDeque() { head = NULL; tail = NULL; size = 0; }
	void push_front(T x) {
		Node<T>* node = new Node<T>(x);
		if (tail == NULL)
		{
			tail = node;
		}
		if (head != NULL)
		{
			head->prev = node;
		}
		node->next = head;
		head = node;
		size++;
	}
	void push_back(T x) {
		Node<T>* node = new Node<T>(x);
		if (head == NULL)
		{
			head = node;
		}
		if (tail != NULL)
		{
			tail->next = node;
		}
		node->prev = tail;
		tail = node;
		size++;
	}

	T pop_front() {
		if (head != NULL)
		{
			Node<T>* temp = head;
			if (head->next)
			{
				head->next->prev = NULL;
				head = head->next;
			}
			else
			{
				head = NULL;
				tail = NULL;
			}
			int d = temp->data;
			delete temp;
			size--;
			return d;
		}
		else
			return -1;
	}
	T pop_back() {
		if (tail != NULL)
		{
			Node<T>* temp = tail;
			if (tail->prev)
			{
				tail->prev->next = NULL;
				tail = tail->prev;
			}
			else
			{
				head = NULL;
				tail = NULL;
			}
			int d = temp->data;
			delete temp;
			size--;
			return d;
		}
		else
			return -1;
	}

	int getSize() { return size; }
	int empty() { if (size == 0) return 1; else return 0; }
	T front() { if (head != NULL) return head->data; else return -1; }
	T back() { if (tail != NULL) return tail->data; else return -1; }
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	MyDeque<int> deque;
	string command[] = { "push_front", "push_back","pop_front","pop_back","size","empty", "front","back" };
	int n;
	cin >> n;
	
	while (n-- > 0)
	{
		string str;
		cin >> str;
		int i = -1;
		while (command[++i] != str);
		int number;
		switch (i)
		{
		case 0:
			cin >> number;
			deque.push_front(number);
			break;
		case 1:
			cin >> number;
			deque.push_back(number);
			break;
		case 2:
			cout << deque.pop_front() << "\n";
			break;
		case 3:
			cout << deque.pop_back() << "\n";
			break;
		case 4:
			cout << deque.getSize() << "\n";
			break;
		case 5:
			cout << deque.empty() << "\n";
			break;
		case 6:
			cout << deque.front() << "\n";
			break;
		case 7:
			cout << deque.back() << "\n";
			break;
		}
	}
	return 0;
}