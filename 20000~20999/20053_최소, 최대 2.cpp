#include <iostream>

#define INF 1e9

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		int min = (int)INF, max = -(int)INF;
		for (int i = 0; i < N; i++)
		{
			int n;
			cin >> n;
			min = n < min ? n : min;
			max = n > max ? n : max;
		}
		cout << min << " " << max << "\n";
	}

	return 0;
}