/**
 BOJ 1976
 - 여행 가자
 - 오전 1:12 2020-11-28
 */

#include <iostream>

typedef long long ll;

using namespace std;

void init(int& N, int& M, int**& arr, int*& mArr)
{
	cin >> N;
	cin >> M;
	arr = new int* [(ll)N + 1];
	fill(arr, arr + N + 1, nullptr);
	for (int i = 0; i < N + 1; i++)
	{
		arr[i] = new int[(ll)N + 1];
		fill(arr[i], arr[i] + N + 1, 0);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}
	mArr = new int[(ll)M + 1];
	fill(mArr, mArr + M + 1, 0);
	for (int i = 1; i <= M; i++)
	{
		cin >> mArr[i];
	}

}

bool solve(int& N, int& M, int**& arr, int*& mArr)
{
	for (int k = 1; k <= N; k++)
	{
		arr[k][k] = 1;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (arr[i][k] == 1 && arr[k][j] == 1)
				{
					arr[i][j] = 1;
				}
			}
		}
	}

	bool isPoss = true;
	for (int i = 1; i <= M; i++)
	{
		if (arr[mArr[1]][mArr[i]] == 0)
		{
			isPoss = false;
			break;
		}
	}

	return isPoss;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	int M;
	int** arr;
	int* mArr;
	init(N, M, arr, mArr);

	bool re = solve(N, M, arr, mArr);

	if (re == true)
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";

	return 0;
}