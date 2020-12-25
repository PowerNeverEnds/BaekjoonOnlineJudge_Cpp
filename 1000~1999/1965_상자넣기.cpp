#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int** dp = new int* [n];
	for (int i = 0; i < n; i++)
	{
		dp[i] = new int[n];
		fill(dp[i], dp[i] + n, 0);
	}

	//dp[0][0] = arr[i];
	for (int j = 1; j < n; j++)
	{
		for (int i = 1; i <= j; i++)
		{
			
		}
	}

	//stack<int> s;
	//int maxSize = 0;
	//for (int i = 0; i < n; i++)
	//{
	//	int e;
	//	cin >> e;

	//	while (!s.empty() && !(s.top() < e))
	//		s.pop();
	//	s.push(e);
	//	//cout <<s.size()<<" "<< s.top() << "\n";
	//	maxSize = s.size() > maxSize ? s.size() : maxSize;
	//}

	//cout << maxSize << "\n";

	return 0;
}
/*
8
1 6 2 5 7 3 5 6
5

3
1 2 3
3
3 2 1
3
1 3 2
3
2 1 3

1
3

5
1 5 2 3 7
4

11
1 2 3 2 1 4 6 2 1 5 6
6


*/