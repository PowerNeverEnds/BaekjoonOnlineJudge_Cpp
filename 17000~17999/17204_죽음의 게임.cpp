/**
 *    BOJ 17204
 *    - 죽음의 게임
 *    author:  phcdream
 *    created: 오전 4:01 2020-12-08
**/

#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	int* arr = new int[(ll)N + 1];
	fill(arr, arr + N + 1, 0);
	//int* visited= new int[(ll)N + 1];
	//fill(visited, visited + N + 1, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int p = 0;
	for (int i = 1; i <= N; i++)
	{
		p = arr[p];
		if (p == K)
		{
			cout << i << "\n";
			return 0;
		}
	}
	
	cout << -1 << "\n";

	return 0;
}