#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	string* strN = new string[N];
	string* strM = new string[M];

	for (int i = 0; i < N; i++)
		cin >> strN[i];
	for (int i = 0; i < M; i++)
		cin >> strM[i];

	sort(strN, strN + N, [](auto a, auto b) {
		return a < b;
		});
	sort(strM, strM + M, [](auto a, auto b) {
		return a < b;
		});

	string* out = new string[N > M ? N : M];
	int outCount = 0;
	for (int i = 0; i < N; i++)
	{
		int left, right;
		left = 0;
		right = M - 1;
		int mid = 0;
		while (true)
		{
			if (left > right)
				break;
			mid = (left + right) / 2;
			if (strM[mid] == strN[i])
			{
				out[outCount++] = strN[i];
				break;
			}
			else if (strM[mid] < strN[i])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
	}

	cout << outCount << "\n";
	for (int i = 0; i < outCount; i++)
	{
		cout << out[i] << "\n";
	}
	return 0;
}