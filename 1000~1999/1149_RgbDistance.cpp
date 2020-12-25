#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int* r = new int[n];
	int* g = new int[n];
	int* b = new int[n];
	int* rSum = new int[n];
	int* gSum = new int[n];
	int* bSum = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> r[i] >> g[i] >> b[i];
		rSum[i] = gSum[i] = bSum[i] = -1;
	}
	rSum[0] = r[0];
	gSum[0] = g[0];
	bSum[0] = b[0];

	for (int i = 1; i < n; i++)
	{
		rSum[i] = r[i] + (gSum[i - 1] < bSum[i - 1] ? gSum[i - 1] : bSum[i - 1]);
		gSum[i] = g[i] + (rSum[i - 1] < bSum[i - 1] ? rSum[i - 1] : bSum[i - 1]);
		bSum[i] = b[i] + (rSum[i - 1] < gSum[i - 1] ? rSum[i - 1] : gSum[i - 1]);
	}

	int sum;
	sum = rSum[n - 1] < gSum[n - 1] ? rSum[n - 1] : gSum[n - 1];
	sum = bSum[n - 1] < sum ? bSum[n - 1] : sum;
	cout << sum << "\n";
}

/*
3
26 40 83
49 60 57
13 89 99

*/