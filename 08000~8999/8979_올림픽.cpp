/**
 *    BOJ 8979
 *    - 올림픽
 *    author:  phcdream
 *    created: 오전 3:25 2020-11-29
**/

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

struct MyStruct
{
	int n;
	int g;
	int s;
	int b;

	bool operator<(const MyStruct& ms)const {
		if (g == ms.g)
		{
			if (s == ms.s)
				return b > ms.b;
			return s > ms.s;
		}
		return g > ms.g;
	}

	bool operator==(const MyStruct& ms)const {
		return g == ms.g && s == ms.s && b == ms.b;
	}
};

void init(int& N, int& K, vector<MyStruct>& vec)
{
	cin >> N >> K;
	//vec.resize(N);
	int n, g, s, b;
	for (int i = 0; i < N; i++)
	{
		cin >> n >> g >> s >> b;
		vec.push_back(MyStruct({ n,g,s,b }));
	}
}

void print(int N, vector<MyStruct> vec)
{
	for (auto e : vec)
		cout << e.n << " " << e.g << " " << e.s << " " << e.b << "\n";
	cout << "\n";
}

int solve(int N, int K, vector<MyStruct> vec)
{
	sort(vec.begin(), vec.end(), [](auto a, auto b) {
		return a < b;
		});

	int rank = 0;
	int cnt = 1;
	MyStruct prev = MyStruct({ 0,0,0,0 });
	for (int i = 0; i < N; i++)
	{
		if (prev == vec[i])
			cnt++;
		else
		{
			rank += cnt;
			cnt = 1;
		}

		if (vec[i].n == K)
		{
			break;
		}
		prev = vec[i];
	}

	//print(N, vec);

	return rank;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	vector<MyStruct> vec;
	init(N, K, vec);

	int re = solve(N, K, vec);

	cout << re << "\n";

	return 0;
}

/*
4 3
1 1 2 0
2 1 2 1
3 1 2 0
4 1 2 1

3

*/