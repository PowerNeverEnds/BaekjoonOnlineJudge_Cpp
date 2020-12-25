#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	int N;
	cin >> N;
	int** arr = new int* [(ll)N+1];
	for (int i = 0; i < N+1; i++)
	{
		arr[i] = new int[2];
		fill(arr[i], arr[i] + 2, 0);
	}
	int* dp = new int [(ll)N+1];	// i�ϱ��� �������ִ� �ְ��
		fill(dp, dp+ N+1, 0);

	for(int i=1;i<=N;i++)
		cin >> arr[i][0] >> arr[i][1];

	int max = 0;
	for (int i = 1; i <= N; i++)
	{

		int day = arr[i][0] + i - 1;
		// i���� ��� �����,
		// i�ϱ����ְ��+������ݾ� > (i+������Ϸῡ�ɸ��±Ⱓ) ���� �ְ��
		if (day <= N && dp[i - 1] + arr[i][1] > dp[day]) {
			dp[day] = dp[i - 1] + arr[i][1];
		}
		if(dp[i]<dp[i-1])
			dp[i] = dp[i - 1];
		max = dp[i] > max ? dp[i] : max;
	}

	cout << max << "\n";

	return 0;
}