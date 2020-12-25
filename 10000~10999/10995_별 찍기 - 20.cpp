#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N * 2; j++)
		{
			if ((i + j) % 2 == 0)
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}

	return 0;
}