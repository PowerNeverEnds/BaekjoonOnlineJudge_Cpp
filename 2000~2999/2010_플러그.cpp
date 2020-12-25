#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int sum = 1;
	for (int i = 0; i < N; i++)
	{
		int e;	// e는 자연수
		cin >> e;
		sum += e - 1;
	}
	
	cout << sum << "\n";

	return 0;
}