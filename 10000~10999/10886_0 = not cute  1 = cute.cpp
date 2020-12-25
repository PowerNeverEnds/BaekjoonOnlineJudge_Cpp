#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int arr[2] = { 0, };
	for (int i = 0; i < N; i++)
	{
		int e;
		cin >> e;
		arr[e]++;
	}
	if (arr[0] < arr[1])
	{
		cout << "Junhee is cute!" << "\n";
	}
	else if (arr[0] > arr[1])
	{
		cout << "Junhee is not cute!" << "\n";
	}

	return 0;
}