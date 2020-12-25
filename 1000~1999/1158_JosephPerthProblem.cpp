#include <iostream>
using namespace std;

class Node {
	int data;
	Node* next;
	Node* prev;
public:
	Node(int n = -1) { data = n; next = NULL; prev = NULL; }
	friend class List;
};

class List {
	Node* head;
	Node* tail;
	Node* position;
	int size;
public:
	List() { head = NULL; tail = NULL; position = NULL;  size = 0; }
	void push(int n) {
		Node* node = new Node(n);
		if (head == NULL)
		{
			head = node;
			position = node;
		}
		else
		{
			tail->next = node;
			node->prev = tail;
		}
		tail = node;
		tail->next = head;
		head->prev = tail;
		size++;
	}
	int pop() {
		if (position != NULL)
		{
			Node* temp=position;
			if (position->next == position)
			{
				position = NULL;
				head = NULL;
				tail = NULL;
			}
			else
			{
				position->prev->next = position->next;
				position->next->prev = position->prev;
				position = position->next;
				head = position;
				tail = position;
			}
			int n;
			n = temp->data;
			delete temp;
			size--;
			return n;
		}
		else
			return -1;
	}
	void next() {
		position = position->next;
	}
	int empty() {
		if (size == 0)return 1; else return 0;
	}
	int getSize() {
		return size;
	}
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	
	List list;
	for (int i = 1; i <= n; i++)
	{
		list.push(i);
	}
	cout << "<";
	while (list.getSize()>1)
	{
		for (int i = 0; i < k-1; i++)
			list.next();
		cout<<list.pop()<<", ";

	}
	cout<<list.pop();
	cout << ">"<<"\n";
	return 0;
}