/**
 *    BOJ 15501
 *    - 부당한 퍼즐
 *    author:  phcdream
 *    created: 오후 9:05 2020-12-07
**/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void inVec(int n, vector<int>& vec)
{
	for (int i = 0; i < n; i++)
	{
		int e;
		cin >> e;
		vec.push_back(e);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> aVec;
	vector<int> bVec;
	int n;
	cin >> n;
	if (n <= 3)
	{
		cout << "good puzzle" << "\n";
		return 0;
	}
	inVec(n, aVec);
	inVec(n, bVec);
	bool isReverse = false;
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		if (aVec[0] == bVec[i])
		{
			if (bVec[(i + 1) % n] != aVec[1])// || i==n-1 && bVec[0] !=aVec[1])
			{
				isReverse = true;
				p = n - (i + 1) % n;
			}
			else
			{
				p = i;
			}
			break;
		}
	}
	if(isReverse==true)		// if 문없이 그냥 reverse 해버림.
		reverse(bVec.begin(), bVec.end());

	for (int i = 0; i < n; i++)
	{
		if (aVec[i] != bVec[(i + p) % n])
		{
			cout << "bad puzzle" << "\n";
			return 0;
		}
	}

	cout << "good puzzle" << "\n";

	return 0;
}

/*
5
1 2 3 4 5
4 3 2 1 5

4
1 3 2 4
4 3 2 1

4
2 3 4 1
4 3 2 1

2
1 2
1 2

5
1 2 3 4 5
1 2 3 4 5

5
1 2 3 4 5
5 1 2 3 4

5
1 2 3 4 5
4 5 1 2 3

5
1 2 3 4 5
3 4 5 1 2

5
1 2 3 4 5
2 3 4 5 1
*/