#include <iostream>

typedef long long ll;

using namespace std;

int dfs(int* arr, int* visited, int d, int dMax, int S)
{
	int cnt = 0;
	if (d > dMax)
	{
		int sum = 0;
		for (int i = 1; i <= dMax; i++)
			sum += arr[i] * visited[i];
		if (sum == S)
		{
			//for (int i = 1; i <= dMax; i++)
			//	cout << (visited[i] == 1 ? arr[i] : 0) << " ";
			//cout << "\n";
			return true;
		}
		return false;
	}
	for (int i = 0; i <= 1; i++)
	{
		visited[d] = i;
		cnt += dfs(arr, visited, d + 1, dMax, S);
		visited[d] = 0;
	}
	return cnt;
}

int main()
{
	int N, S;
	cin >> N >> S;

	int* arr = new int[(ll)N + 1];
	fill(arr, arr + N + 1, 0);
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	int* visited = new int[(ll)N + 1];
	fill(visited, visited + N + 1, 0);

	int result = dfs(arr, visited, 1, N, S);
	if (S == 0)
		result -= 1;

	cout << result << "\n";

	return 0;
}