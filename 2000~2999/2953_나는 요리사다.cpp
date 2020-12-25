#include <iostream>

using namespace std;

int main()
{
	int max = 0;
	int nth = 0;
	for (int i = 0; i < 5; i++)
	{
		int sum = 0;
		for (int j = 0; j < 4; j++)
		{
			int e;
			cin >> e;
			sum += e;
		}
		if (max < sum)
		{
			max = sum;
			nth = i;
		}
	}

	cout << nth + 1 << " " << max << "\n";


	return 0;
}