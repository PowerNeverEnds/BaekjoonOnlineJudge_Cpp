#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

struct MyStruct
{
	ll n;
	int c;
	bool operator<(const MyStruct& ms)const {
		if (c == ms.c)
			return n < ms.n;
		return c > ms.c;
	}
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<ll> vec;

	for (int i = 0; i < N; i++)
	{
		ll e;
		cin >> e;
		vec.push_back(e);
	}

	sort(vec.begin(), vec.end(), [](auto a, auto b) {
		return a < b;
		});

	vector<MyStruct> cntVec;
	cntVec.push_back(MyStruct({ vec[0],0 }));
	int max = 0;
	for (auto e : vec)
	{
		if (cntVec.back().n == e)
		{
			cntVec.back().c++;
		}
		else
		{
			cntVec.push_back(MyStruct{ e,1 });
		}
	}

	sort(cntVec.begin(), cntVec.end(), [](auto a, auto b) {
		return a < b;
		});

	cout << cntVec[0].n << "\n";

	return 0;
}