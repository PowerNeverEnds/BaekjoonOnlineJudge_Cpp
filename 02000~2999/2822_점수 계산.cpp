#include <iostream>
#include <algorithm>

using namespace std;

struct MyStruct
{
	int n;
	int ind;
	bool operator>(const MyStruct& ms) const {
		return n > ms.n;
	}
};

int main()
{
	MyStruct arr[8] = { 0, };
	for (int i = 0; i < 8; i++)
	{
		cin >> arr[i].n;
		arr[i].ind = i + 1;
	}

	sort(arr, arr + 8, [](auto a, auto b) {
		return a > b;
		});

	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += arr[i].n;
	}
	cout << sum << "\n";
	sort(arr, arr + 5, [](auto a, auto b) {
		return a.ind < b.ind;
		});
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i].ind << " ";
	}

	return 0;
}