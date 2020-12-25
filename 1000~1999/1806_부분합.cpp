#include <iostream>
#include <queue>


#define MAX ((int)1e5+7)

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, S;
	cin >> N >> S;

	if (S == 0)
	{
		cout << 1 << "\n";
		return 0;
	}
	int sum = 0;
	queue<int> q;
	int min = MAX;
	for (int i = 0; i < N; i++)
	{
		int e;
		cin >> e;
		sum += e;
		q.push(e);
		if (sum >= S)
		{
			min = q.size() < min ? q.size() : min;
			while (true)
			{
				if (q.empty())
					break;
				sum -= q.front();
				q.pop();
				if (sum < S)
				{
					break;
				}
				else
				{
					min = q.size() < min ? q.size() : min;
				}
			}
		}
	}

	if (min == MAX)
		cout << 0 << "\n";
	else
		cout << min << "\n";

	return 0;
}

/*
10 15
5 1 3 5 10 7 4 9 2 8

3 100
1 2 3

3 0
1 2 3

3 1
2 3 4

10 10
1 2 3 3 9 1 10 10 10 1

10 10
1 2 3 3 1 1 1 1 1 1 

10 10
1 2 3 3 2 1 1 1 1 1


10 10
1 2 3 2 1 2 1 1 1 1

*/