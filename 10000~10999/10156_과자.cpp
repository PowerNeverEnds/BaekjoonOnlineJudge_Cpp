#include <iostream>

using namespace std;

int main()
{
	int K, N, M;
	cin >> K >> N >> M;

	int re = K * N - M;
	if (re > 0)
		cout << K * N - M << "\n";
	else
		cout << 0 << "\n";

	return 0;
}