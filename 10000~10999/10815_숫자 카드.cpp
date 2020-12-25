#include <iostream>
#include <vector>

#define MAX (10000000)

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	bool* arr = new bool[MAX*2];
	fill(arr, arr + MAX * 2, false);
	int N;
	cin >> N;
	int e;
	for (int i = 0; i < N; i++)
	{
		cin >> e;
		arr[e + MAX] = true;
	}
	
	vector<bool> vec;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> e;
		vec.push_back(arr[e + MAX]);
	}

	for (auto e : vec)
		cout << e << " ";
	cout << "\n";

	return 0;
}