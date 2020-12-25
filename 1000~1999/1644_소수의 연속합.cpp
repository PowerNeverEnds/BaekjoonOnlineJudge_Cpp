#include <iostream>
#include <vector>

typedef long long ll;

#define MAX (4000000)

using namespace std;

int main()
{
	int N;
	cin >> N;

	bool* arr = new bool[(ll)MAX];
	fill(arr, arr + MAX, true);
	arr[0] = arr[1] = false;
	for (int i = 2; i < MAX; i++)
	{
		if (arr[i] == true)
			arr[i] = true;
		else
			continue;
		for (int j = i + i; j < MAX; j += i)
			arr[j] = false;
	}
	vector<int> vec;
	for (int i = 0; i < MAX; i++)
	{
		if (arr[i] == true)
			vec.push_back(i);
	}

	int l, r;
	l = r = 0;
	int sum = 0;
	int cnt = 0;
	while (true)
	{
		if (r >= vec.size())
			break;
		sum += vec[r++];
		while (true)
		{
			if (sum <= N)
				break;
			sum -= vec[l++];
		}
		if (sum == N)
			cnt++;
	}

	cout << cnt << "\n";

	return 0;
}