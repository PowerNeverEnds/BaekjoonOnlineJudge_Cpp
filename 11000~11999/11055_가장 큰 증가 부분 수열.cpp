/*
https://m.blog.naver.com/occidere/220793914361
*/

#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[(ll)N + 1];
	fill(arr, arr + N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	//int** dp = new int* [(ll)N + 1];
	//fill(dp, dp + N + 1, nullptr);
	//for (int i = 0; i < N + 1; i++)
	//{
	//	dp[i] = new int[(ll)N + 1];
	//	fill(dp[i], dp[i], 0);
	//}

	int* dp = new int[(ll)N + 1];
	fill(dp, dp + N + 1, 0);

	int allMax = 0;
	for (int i = 1; i <= N; i++)
	{
		//dp[i][i] = arr[i];
		dp[i] = arr[i];
		for (int j = 1; j <= i; j++)
		{
			if (arr[j] < arr[i])
			{
				//int max = 0;
				//for (int k = 1; k <= j; k++)
				//{
				//	if (dp[j][k] > max)
				//	{
				//		max = dp[j][k];
				//	}
				//}
				//dp[i][j] = max + arr[i];
				if (dp[j] + arr[i] > dp[i])
					dp[i] = dp[j] + arr[i];
			}
			//allMax = dp[i][j] > allMax ? dp[i][j] : allMax;
			allMax = dp[i] > allMax ? dp[i] : allMax;
		}
	}

	cout << allMax << "\n";

	return 0;
}


/*
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int arr[1001] = { 0, };
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	stack<int> s;
	int max = 0;
	for (int k = 0; k < N; k++)
	{
		int sum = 0;
		for (int i = k; i < N; i++)
		{
			if (s.empty())
			{
				sum += arr[i];
				s.push(arr[i]);
			}
			else
			{
				while (!s.empty() && s.top() >= arr[i])
				{
					sum -= s.top();
					s.pop();
				}
				sum += arr[i];
				s.push(arr[i]);
			}
			max = sum > max ? sum : max;
			cout <<arr[i]<<" "<< sum<<" " << max << "\n";
		}
	}
	cout << max << "\n";

	return 0;
}
*/
/*
10
1 2 3 4 5 2 5 6 7 8


*/