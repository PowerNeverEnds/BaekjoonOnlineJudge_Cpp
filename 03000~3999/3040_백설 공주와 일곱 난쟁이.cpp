/**
 *    BOJ 3040
 *    - 백설 공주와 일곱 난쟁이
 *    author:  phcdream
 *    created: 오후 9:39 2020-12-04
**/

#include <iostream>

using namespace std;

int main()
{
	int sum = 0;
	int arr[9] = { 0, };
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - arr[i] - arr[j] == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k != i && k != j)
					{
						cout << arr[k] << "\n";
					}
				}
				return 0;
			}
		}
	}

	return 0;
}