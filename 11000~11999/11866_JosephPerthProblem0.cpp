#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	queue<int> que;

	for (int i = 1; i <= n; i++)
	{
		que.push(i);
	}
	cout << "<";
	while (que.empty() == false)
	{
		for (int i = 0; i < k - 1; i++)
		{
			que.push(que.front());
			que.pop();
		}
		if (que.size() == 1)
		{
			cout << que.front() << ">" << "\n";

		}
		else
			cout<< que.front()<<", ";
		que.pop();
	}


	return 0;
}