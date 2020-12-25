#include <iostream>
#include <vector>

typedef long long ll;

// 1000000000000 -> ¹é¸¸
#define MAX (int(1e6+7))

using namespace std;

int main()
{
	bool* bPArr = new bool[MAX];
	fill(bPArr, bPArr + MAX, false);
	bPArr[0] = bPArr[1] = true;
	for (int i = 2; i < MAX; i++)
	{
		if (bPArr[i] == true)
		{
			continue;
		}
		for (int j = i + i; j < MAX; j += i)
		{
			bPArr[j] = true;
		}
	}

	vector<int> vecP;
	for (int i = 0; i < MAX; i++)
		if (bPArr[i] == false)
			vecP.push_back(i);

	//cout << vecP.size() << "\n";

	ll min, max;
	cin >> min >> max;

	int cnt = 0;
	int arrSize = (ll)max - min + 1;
	bool* arr = new bool[arrSize];
	fill(arr, arr + arrSize, false);
	for (auto e : vecP)
	{
		ll sqE = (ll)e * e;
		ll l = sqE + (ll)(min - 1) / sqE * sqE;
		//cout << l << "\n";
		if (l > max)
			continue;
		ll i = l - min;
		//cout << i << "\n";
		if (!(i < arrSize))
			continue;
		do
		{
			//cout << i << "\n";
			arr[i] = true;
			i += sqE;
		} while (i < arrSize);
	}
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] == false)
			cnt++;
	}

	cout << cnt << "\n";

	return 0;
}

/*
100000000000
100001000000

8 8

36 36

7 8
8 9
7 9

1000000000000 1000001000000

1000000000000 1000000100000

1000000000000 1000000000001
1000000000000 1000000000010
4 8
4 9
4 10
3 8
3 9
3 10
1 1
1 2
1 3
1 4
1 5
*/
