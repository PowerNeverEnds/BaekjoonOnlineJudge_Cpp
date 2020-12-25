#include <iostream>

using namespace std;

void myReverse(int* first, int* last)
{
	int* i1, * i2;
	i1 = first, i2 = last;
	while (i1 != i2 && i1 != --i2)
	{
		iter_swap(i1++, i2);
	}
}

bool next(int* first, int* last)
{
	if (first == last)return false;
	int* i = last;
	if (first == --i)return false;

	while (true)
	{
		int* i1, * i2;
		i1 = i;
		if (*--i < *i1) {
			i2 = last;
			while (!(*i < *--i2))
				;
			iter_swap(i, i2);
			myReverse(i1, last);
			return true;
		}
		if (i == first) {
			myReverse(first, last);
			return false;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	fill(arr, arr + N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	if (next(arr, arr + N) == false)
	{
		cout << -1 << "\n";
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			cout << arr[i] << " ";
		}cout << "\n";
	}

	return 0;
}