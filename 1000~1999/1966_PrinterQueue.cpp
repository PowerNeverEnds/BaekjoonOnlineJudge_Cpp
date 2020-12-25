#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

bool upGreater(int a, int b);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int testCase;
	cin >> testCase;
	while (testCase-- > 0)
	{
		int n, m;
		cin >> n >> m;
		int point=m;
		queue<int> myQueue;
		vector<int> myVector;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			myVector.push_back(a);
			myQueue.push(a);
		}
		sort(myVector.begin(), myVector.end());
		int count = 0;
		while (1)
		{
			if (myVector.back() == myQueue.front())
			{
				count++;
				if (point == 0)
					break;
				myVector.pop_back();
				myQueue.pop();
				point--;
			}
			else
			{
				myQueue.push(myQueue.front());
				myQueue.pop();
				point--;
				if (point < 0)
					point = myQueue.size()-1;
			}
		}
		cout << count << "\n";
	}

	return 0;
}

bool upGreater(int a, int b)
{
	return a > b;
}