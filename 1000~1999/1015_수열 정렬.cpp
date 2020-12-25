/**
 *    BOJ 1015
 *    - 수열 정렬
 *    author:  phcdream
 *    created: 오전 3:18 2020-12-07
**/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct MyStruct
{
	int n;
	int ind;
	int sortedInd;
};

int main()
{
	int N;
	cin >> N;
	vector<MyStruct> vec;
	for (int i = 0; i < N; i++)
	{
		int e;
		cin >> e;
		vec.push_back({ e,i });
	}
	sort(vec.begin(), vec.end(), [](auto a, auto b) {
		if (a.n == b.n)
			return a.ind < b.ind;
		return a.n < b.n;
		});
	for (int i = 0; i < N; i++)
	{
		vec[i].sortedInd = i;
	}
	sort(vec.begin(), vec.end(), [](auto a, auto b) {
		//if (a.n == b.n)
		//	return a.sortedInd < b.sortedInd;
		return a.ind < b.ind;
		});

	for (int i = 0; i < N; i++)
	{
		cout << vec[i].sortedInd << " ";
	}
	cout << "\n";

	return 0;
}

/*
3
2 3 1

3
2 2 1

3
2 1 2

5
2 2 1 2 2

*/