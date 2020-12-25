#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

struct MyStruct
{
	int a;
	int b;
	int c;
	bool operator<(const MyStruct& ms) {
		return c < ms.c;
	};
};

struct disJointSet
{
	int* uf;
	void init(int n)
	{
		uf = new int[(ll)n + 1];
		fill(uf, uf + n + 1, 0);
		for (int i = 1; i <= n; i++)
			uf[i] = i;
	}

	int setFind(int a)
	{
		if (uf[a] == a)
			return a;
		else
			return uf[a] = setFind(uf[a]);
	}

	void setUnion(int a, int b)
	{
		a = setFind(a);
		b = setFind(b);

		uf[b] = a;
	}
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int M;
	cin >> M;

	MyStruct* edge = new MyStruct[(ll)M];
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = MyStruct({ a,b,c });
	}

	sort(edge, edge + M, [](auto a, auto b) {
		return a < b;
		});

	disJointSet djs;
	djs.init(N);

	int sum = 0;
	for (int i = 0; i < M; i++)
	{
		MyStruct e;
		e = edge[i];
		if (djs.setFind(e.a) != djs.setFind(e.b))
		{
			djs.setUnion(e.a, e.b);
			sum += e.c;
		}
	}

	cout << sum << "\n";

	return 0;
}