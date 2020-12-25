/**
 BOJ 5052
 - 전화번호 목록
 - 오후 8:44 2020-11-27

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

void init(int& n, string*& arr)
{
	cin >> n;
	arr = new string[(ll)n + 1];
	fill(arr, arr + n + 1, "");
	for (int i = 1; i <= n; i++)
	{
		cin.ignore();
		cin >> arr[i];
	}
}

bool solve(int& n, string*& arr)
{
	sort(arr + 1, arr + n + 1, [](auto a, auto b) {
		return a < b;
		});

	for (int i = 1; i <= n - 1; i++)
	{
		bool isSame = true;
		//cout << arr[i].length() << " " << arr[i + 1].length() << "\n";
		if (arr[i].length() > arr[i + 1].length())
			continue;
		for (int j = 0; j < arr[i].length(); j++)
		{
			if (arr[i][j] == arr[i + 1][j])
			{
			}
			else
			{
				isSame = false;
				break;
			}
		}
		if (isSame == true)
		{
			return false;
		}
	}

	return true;
}

void print(int& n, string*& arr)
{
	for (int i = 1; i <= n; i++)
		cout << arr[i] << "\n";
	cout << "\n";
}

int main()
{
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		string* arr;
		init(n, arr);

		bool re = solve(n, arr);

		//print(n, arr);

		if (re == true)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}

	return 0;
}