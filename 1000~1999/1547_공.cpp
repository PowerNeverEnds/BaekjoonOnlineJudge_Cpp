#include <iostream>

typedef long long ll;

using namespace std;

void mySwap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M;
	cin >> M;
	int arr[4];
	for(int i=1;i<=3;i++)
		arr[i] = i;
	for (int i = 0; i < M; i++)
	{
		int X, Y;
		cin >> X >> Y;
		mySwap(arr[X], arr[Y]);
	}

	for (int i = 1; i <= 3; i++)
	{
		if (arr[i] == 1)
			cout << i << "\n";
	}

	return 0;
}