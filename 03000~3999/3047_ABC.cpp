/**
 BOJ 3047
 - ABC
 - ¿ÀÈÄ 10:41 2020-11-27
 */

#include <iostream>

using namespace std;

void mySwap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

int main()
{
	int arr[3];
	for (int i = 0; i < 3; i++)
		cin >> arr[i];

	if (arr[0] > arr[1])
		mySwap(arr[0], arr[1]);
	if (arr[1] > arr[2])
		mySwap(arr[1], arr[2]);
	if (arr[0] > arr[1])
		mySwap(arr[0], arr[1]);

	for (int i = 0; i < 3; i++)
	{
		char ch;
		cin >> ch;
		cout << arr[ch - 'A']<<" ";
	}

	return 0;
}