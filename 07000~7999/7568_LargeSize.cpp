#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int weight[50] = { 0, };
	int height[50] = { 0, };
	int rank[50] = { 0, };
	for (int i = 0; i < n; i++)
	{
		cin >> weight[i] >> height[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (weight[i] < weight[j] && height[i] < height[j])
			{
				rank[i]++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << rank[i] + 1<<" ";
	}
	cout << "\n";

	return 0;
}