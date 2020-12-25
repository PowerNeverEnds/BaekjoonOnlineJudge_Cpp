#include <iostream>

typedef unsigned long long ull;

using namespace std;

int main()
{
	int N;
	ull M;
	cin >> N >> M;
	
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int left, right;
	left = 0;
	right = 1000000000 + 1;
	int mid;
	ull s;
	while (true)
	{
		mid = (left + right) / 2;
		s = 0;
		if (left > right)
		{
			break;
		}
		else
		{
			for (int i = 0; i < N; i++)
			{
				if (mid < arr[i])
				{
					s += (ull)arr[i] - mid;
				}
			}
			if (M == s)
			{
				break;
			}
			else if (M < s)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
	}
	cout << mid << "\n";

	return 0;
}