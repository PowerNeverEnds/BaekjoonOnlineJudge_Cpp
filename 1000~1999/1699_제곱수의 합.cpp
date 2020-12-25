/*
밑에 주석이랑 위쪽 코드는 같은코드
밑에 주석을 지운게 위쪽코드
*/

#include <iostream>
#include <queue>

#define MAX 318

using namespace std;

int arr[MAX] = { 0, };

int main()
{
	int* dp = new int[100001];
	fill(dp, dp + 100001, 0);

	int N;
	cin >> N;
	for (int i = 0; i < MAX; i++)
		arr[i] = i * i;

	queue<int> q;
	for (int i = 0; i < MAX; i++)
	{
		if (arr[i] > N)
			break;
		dp[arr[i]] = 1;
		q.push(arr[i]);
	}

	int st;
	while (true)
	{
		if (q.empty())
			break;
		st = q.front();
		q.pop();
		for (int i = 0; i < MAX; i++)
		{
			if (st + arr[i] > N)
				break;
			if (dp[st + arr[i]] > dp[st] + 1 || dp[st + arr[i]] == 0)
			{
				dp[st + arr[i]] = dp[st] + 1;
				q.push(st + arr[i]);
			}
		}
	}

	cout << dp[N] << "\n";

	return 0;
}

/*
#include <iostream>
#include <queue>

#define MAX 318

using namespace std;

int arr[MAX] = { 0, };

int main()
{
	int* dp = new int[100001];
	fill(dp, dp + 100001, 0);
	int N;
	cin >> N;
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = i * i;
	}
	//cout << arr[MAX - 1] << "\n";
	queue<int> q;
	int st;// = 1;
	//dp[st] = 1;
	//q.push(st);
	for (int i = 0; i < MAX; i++)
	{
		if (arr[i] > N)
			break;
		dp[arr[i]] = 1;
		q.push(arr[i]);
	}
	//while (!q.empty())
	//{
	//	cout << q.front() << "\n";
	//	q.pop();
	//}
	while (true)
	{
		//for (int i = 0; i < 40; i++)
		//	cout << dp[i] << " ";
		//cout << "\n";
		if (q.empty())
			break;
		st = q.front();
		q.pop();
		//cout << st << "\n";
		for (int i = 0; i < MAX; i++)
		{
			if (st + arr[i] > N)
				break;
			if (dp[st + arr[i]] > dp[st] + 1 || dp[st + arr[i]] == 0)
			{
				dp[st + arr[i]] = dp[st] + 1;
				//cout << st << " " << arr[i] << " " << dp[st] << "\n";
				q.push(st + arr[i]);
			}
		}
	}

	cout << dp[N] << "\n";

	return 0;
}
*/