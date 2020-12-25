/**
 *    BOJ 9506
 *    - 약수들의 합
 *    author:  phcdream
 *    created: 오전 4:34 2020-12-07
**/

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

#define MAX ((int)1e5+7)

using namespace std;

int main()
{
	vector<int>* vec = new vector<int>[MAX];
	bool* bSum = new bool[MAX];
	fill(bSum, bSum + MAX, false);
	for (int i = 0; i < MAX; i++)
	{
		//if(i%10000==0)
		//	cout << i << "\n";
		int sum = 0;
		vec[i].push_back(1);
		sum += 1;
		for (int j = 2; j*j <= i; j++)
		{
			//cout << i << " " << j << "\n";
			if (i % j == 0)
			{
				if(j*j==i)
					vec[i].push_back(j);
				else
				{
					vec[i].push_back(j);
					vec[i].push_back(i / j);
					sum += i / j;
				}
				sum += j;
			}
			if (sum > i)
				break;
		}
		if (sum == i)
		{
			bSum[i] = true;
			sort(vec[i].begin(), vec[i].end(), [](auto a, auto b) {
				return a < b;
				});
		}
	}

	while (true)
	{
		int n;
		cin >> n;
		if (n == -1)
			break;
		if (bSum[n]==false)
		{
			cout << n << " is NOT perfect." << "\n";
		}
		else
		{
			cout << n << " = ";
			for (auto e : vec[n])
			{
				cout << e;
				if (e != vec[n].back())
					cout << " + ";
			}
			cout << "\n";
		}
	}

	return 0;
}