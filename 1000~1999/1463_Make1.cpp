#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int* arr = new int[2 + n + 1];
	for (int i = 0; i < 2 + n + 1; i++)
		arr[i] = 0;

	int small=0;
	small = n;
	arr[n] = 1;
	while (1)
	{
		if (arr[1] != 0)
			break;
		for (int i = small; i < n + 1; i++)
		{
			if (arr[i] != 0)
			{
				if (arr[i - 1] == 0)
				{
					arr[i - 1] = arr[i] + 1;
					small = small<i-1?small:i-1;
				}
				else if (arr[i - 1] != 0 && arr[i - 1] > (arr[i] + 1))
				{
					arr[i - 1] = arr[i] + 1;
				}
				if (i % 2 == 0)
				{
					if (arr[i / 2] == 0)
					{
						arr[i / 2] = arr[i] + 1;
						small = small < i / 2 ? small : i / 2;
					}
					else if (arr[i / 2] != 0 && arr[i / 2] > (arr[i] + 1))
					{
						arr[i / 2] = arr[i] + 1;
					}
				}
				if (i % 3 == 0)
				{
					if (arr[i / 3] == 0)
					{
						arr[i / 3] = arr[i] + 1;;
						small = small < i / 3 ? small : i / 3;
					}
					else if (arr[i / 3] != 0 && arr[i / 3] > (arr[i] + 1))
					{
						arr[i / 3] = arr[i] + 1;
					}
				}
			}
		}
	}
	cout << arr[1]-1 << "\n";
	return 0;
}

// Æ®¸®·Î ÇØº¸±â ½ÇÆÐ(Æ®¸®´Â ±¸ÇöµÇÀÖÀ½)
/*
#include <iostream>
using namespace std;

template <typename T>
class Tree;

template <typename T>
class Node {
	T data;
	Node* child;
	Node* sibling;
	bool visit;
public:
	Node(T d=0):data(d) { child = NULL; sibling = NULL; visit = false; }
	Node* getChild() { return child; }
	Node* getSibling() { return sibling; }
	void setChild(Node* node) { child = node; }
	void setSibling(Node* node) { sibling = node; }
	T getData() { return data; }
	friend class Tree<T>;
};

template <typename T>
class Tree {
	Node<T>* root;
	Node<T>* pointNode;
public:
	Tree() { root = NULL; pointNode = NULL; }
	void setPointNode(Node<T>* node)
	{
		pointNode = node;
	}
	Node<T>* getRoot() { return root; }
	Node<T>* getPointNode() { return pointNode; }
//	Node<T>* getChild() { return pointNode->child(); }
//	Node<T>* getSibling() { return pointNode->sibling(); }
	void add(T d)
	{
		Node<T> *node = new Node<T>(d);
		if (root == NULL)
		{
			root = node;
			pointNode = node;
		}
		else
		{
			Node<T>* temp = pointNode->getChild();
			if (temp == NULL)	//pointNode have not child
			{
				pointNode->setChild(node);
				return;
			}
			else
			{
				// temp is pointNode's child
				// So, temp's sibling is pointNode's child
				while (temp->getSibling() != NULL) { temp=temp->getSibling(); }
				temp->setSibling(node);
			}
		}
	}
	void printChild() {
		Node<T>* temp = pointNode->getChild();
		if (temp == NULL)
			cout << "no child" << "\n";
		else
		{
			while (1)
			{
				if (temp == NULL)
					break;
				cout << temp->getData() << " ";
				temp = temp->getSibling();
			}cout << "\n";
		}
	}
	void printAll() {
		if (root == NULL)
			return;
		cout << "root: " << root->getData() << "\n";
		Node<T>* temp = getRoot();
		drive(0, temp);
	}
	void drive(int depth, Node<T>* node) {
		if (node->getChild() == NULL)
		{
			if (node->getSibling() == NULL)
			{
				for (int i = 0; i < depth; i++)
					cout << "n";
				cout << node->getData() << "\n";
				return;
			}
			else
			{
					for (int i = 0; i < depth; i++)
						cout << "s";
					cout << node->getData() << "\n";
					drive(depth, node->getSibling());
			}
		}
		else
		{
				for (int i = 0; i < depth; i++)
					cout << "c";
				cout << node->getData() << "\n";
				drive(depth + 1, node->getChild());
				if (node->getSibling() == NULL)
				{
					;
				}
				else
				{
					drive(depth, node->getSibling());
				}
			
		}
	}
};
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	Tree<int> tree;
	
	int n;
	cin >> n;

	tree.add(n);
	tree.setPointNode(tree.getPointNode()->getChild());
	cout<<"roothave: " <<(tree.getRoot()->getSibling()==NULL)<<"\n";
	int count=0;
	bool finish = false;
	for(int i=0;;i++)
	{
		tree.printAll();
		tree.setPointNode(tree.getRoot());
		int circularSibling=0;
		bool goNextLevel = false;
		for (int j = 0; j < i;)
		{
			cout << "i j " << i << " " << j << "\n";
			if (!(j < i - 2) && (i == 3))
				break;
			tree.setPointNode(tree.getRoot());
			for (int k = 0; k < i - j - 2; k++)
			{
				cout << "2¹Ø" << "\n";
				tree.setPointNode(tree.getPointNode()->getChild());
			}
			cout << "CIR: " << circularSibling <<" "<< (tree.getPointNode()->getData())<< "\n";
			for (int k = 0;k<circularSibling; k++)
			{
				if (tree.getPointNode()->getSibling() == NULL)
				{
					circularSibling = 0;
					goNextLevel = true;
					break;
				}
				cout << "¿·" << "\n";
				tree.setPointNode(tree.getPointNode()->getSibling());
			}
			cout <<"if i>=2 "<<tree.getPointNode()->getData()<<" "<< (tree.getPointNode()->getSibling() == NULL) << "\n";
			if (i >=2 && tree.getPointNode()->getSibling() == NULL)
			{

				goNextLevel = true;
			}
			circularSibling++;
			for (int k = 0; k < j; k++)
			{
				cout << "1¹Ø";
				tree.setPointNode(tree.getPointNode()->getChild());
			}
			if (i > 1)
			{

				cout << "3¹Ø"<<"\n";
				tree.setPointNode(tree.getPointNode()->getChild());
			}

			if (goNextLevel==true)
			{
				j++;
			}
			if (!(j < i))
				break;
			for (int k = 0;; k++)
			{
				int number = tree.getPointNode()->getData();
				cout << i << " " << j << " "<<k<<" " << "number: " << number <<"     "<<count<< "\n";
				if (number == 1)
				{
					finish = true;
					break;
				}
				if (number == 2 || number == 3)
				{
					count++;
					finish = true;
					break;
				}
				tree.add(number - 1);
				if (number % 2 == 0)
					tree.add(number / 2);
				if (number % 3 == 0)
					tree.add(number / 3);
				//else
				//{
				//	tree.setPointNode(tree.getPointNode()->getChild());
				//}
				if (tree.getPointNode()->getSibling())
				{
					cout << "¿·À¸·ÎÀÌµ¿" << "\n";
					tree.setPointNode(tree.getPointNode()->getSibling());
				}
				else
				{
					break;
				}
				if (finish == true)
					break;
			}
			if (finish == true)
				break;

		}

		if (finish == true)
			break;
		count++;
	}

	tree.printAll();
	cout << "count: " << count << "\n";
	return 0;
}
*/
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	Tree<int> tree;
//
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			tree.add(i*10+j);
//		}
//		if (tree.getPointNode()->getChild())
//		{
//			tree.setPointNode(tree.getPointNode()->getChild());
//		}
//
//		
//	}
//	tree.setPointNode(tree.getRoot());
//	tree.printChild();
//	tree.printAll();
//	return 0;
//}


/*
1 0
2 1
3 1
4 13 22 2
5 14 3
6 15 23 32 2
7 16 3
8 17 24 3
9 18 33 2
10 19 25 3
11 1.10 4
12 1.11 26 34 3
13 1.12 4
14 1.13 27 4
15 1.14 35 4
16 1.15 28 4
.
84 11113333 2.42->22.21->2237 8
.
.
.
n 1(n-1) n%2==0?2(n/2) n%3==0?3(n/3) ¼ÂÁß Àê ÀÛÀº ¼ö




16

¹Ø¹Ø ¹Ø
¹Ø¹Ø¿· ¹Ø
¹Ø¿·¹Ø ¹Ø
¹Ø¿·¹Ø¿· ¹Ø
*/