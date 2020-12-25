#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int s, a;
		cin >> s >> a;
		cnt += a % s;
	}
	
	cout << cnt << "\n";

	return 0;
}