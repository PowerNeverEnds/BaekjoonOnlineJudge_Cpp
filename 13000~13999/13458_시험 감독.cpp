#include <iostream>

typedef long long ll;

using namespace std;

int A[1000001];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;


	for (int i = 0; i < N; i++)
		cin >> A[i];

	int B, C;
	cin >> B >> C;
	ll sum = 0;
	for (int i = 0; i < N; i++)
	{
		int t;
		t = A[i] - B;
		sum++;
		if (t <= 0)
			continue;
		t = (t-1) / C + 1;
		sum += t;
	}

	cout << sum << "\n";

	return 0;
}
