#include <iostream>

typedef long long ll;

using namespace std;

void mySwap(int* a, int* b)
{
	int& aa = *a;
	int& bb = *b;
	int t = aa;
	aa = bb;
	bb = t;
	//cout << *a << " " << *b << "\n";
	//cout << aa << " " << bb << "\n";
}

void myReverse(int* first, int* last)
{
	while ((first != last) && (first != --last))
	{
		mySwap(first++, last);
	}
}


bool prev(int* first, int* last)
{
	if (first == last)
		return false;
	int* i = last;
	if (first == --i)
		return false;

	while (true)
	{
		int* i1, * i2;
		i1 = i;
		if (*--i > * i1) {
			i2 = last;
			while (!(*i > * --i2));
			mySwap(i, i2);
			myReverse(i1, last);
			return true;
		}
		if (i == first)
		{
			myReverse(first, last);
			return false;
		}
	}
}

int main()
{
	int N;
	cin >> N;
	int* arr = new int[(ll)N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	if (prev(arr, arr + N) == false)
	{
		cout << -1 << "\n";
	}
	else
	{

		//mySwap(arr, arr+1);
		for (int i = 0; i < N; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}

	return 0;
}