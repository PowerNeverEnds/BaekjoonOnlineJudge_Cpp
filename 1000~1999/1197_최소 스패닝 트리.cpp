#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;
struct MyStruct;

struct MyStruct
{
	int a;
	int b;
	int val;
	bool operator<(const MyStruct& A) {//const {
		return val < A.val;
	}
};
struct disJointSet
{
	int* uf;
	void init(int V)
	{
		uf = new int[(ll)V + 1];
		fill(uf, uf + V + 1, 0);
		for (int i = 1; i <= V; i++)
			uf[i] = i;
	}

	int setFind(int a)
	{
		if (uf[a] == a)
			return a;
		else
		{
			return uf[a] = setFind(uf[a]);
		}
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
	int V, E;
	cin >> V >> E;
	vector<MyStruct> edge;
	for (int i = 0; i < E; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		edge.push_back(MyStruct({ A,B,C }));
	}

	sort(edge.begin(), edge.end(), [](auto a, auto b) {
		return a < b;
		});

	disJointSet djs;
	djs.init(V);

	int sum = 0;
	for (auto e : edge)
	{
		if (djs.setFind(e.a) == djs.setFind(e.b))
		{
		}
		else
		{
			djs.setUnion(e.a, e.b);
			sum += e.val;
		}
	}
	
	cout << sum << "\n";

	return 0;
}