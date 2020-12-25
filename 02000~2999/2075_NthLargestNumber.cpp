#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	priority_queue<int,vector<int>,greater<int> > pq;
	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		pq.push(number);
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int number;
			cin >> number;
			pq.push(number);
			pq.pop();
		}
	}
	cout << pq.top() << "\n";

	return 0;
}