#include <iostream>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int sum = 0;
	int cnt = 0;
	queue<int> q;
	for (int i = 0; i < N; i++)
	{
		int e;
		cin >> e;
		q.push(e);
		sum += e;
		while (sum>M)
		{
			sum -= q.front();
			q.pop();
		}
		if (sum == M)
		{
			cnt++;
			sum -= q.front();
			q.pop();
		}
	}

	cout << cnt << "\n";

	return 0;
}