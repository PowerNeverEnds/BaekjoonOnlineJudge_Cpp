#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main()
{
	vector<int> vec;
	int sum = 0;
	vec.push_back(NULL);
	for (int i = 1; i < 1000; i++)
	{
		sum += i;
		if (sum > 1000)
			break;
		vec.push_back(sum);

	}
	bool* arr = new bool[(ll)1000 + 1];
	fill(arr, arr + 1000 + 1, false);
	int vSize = vec.size();
	for (int i = 1; i < vSize; i++)
	{
		for (int j = i; j < vSize; j++)
		{
			for (int k = j; k < vSize; k++)
			{
				int sum = vec[i] + vec[j] + vec[k];
				//cout << i << " " << j << " " << k << "\n";
				//cout << vec[i] << " " << vec[j] << " " << vec[k] << " " << sum << "\n";
				if (sum > 1000)
					break;
				arr[sum] = true;
			}
		}
	}

	//for (int i = 0; i <= 100; i++)
	//{
	//	cout << i << " " << arr[i] << "\n";
	//}

	int t;
	cin >> t;
	while (t--)
	{
		int K;
		cin >> K;
		cout << arr[K] << "\n";
	}

	return 0;
}