#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

#define INF 1e9

using namespace std;

struct MyStruct
{
	int y;
	int x;
};

int getDist(MyStruct a, MyStruct b)
{
	return abs(a.y - b.y) + abs(a.x - b.x);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	bool* out = new bool[(long long)t];
	fill(out, out + t, false);
	for (int o = 0; o < t; o++)
	{
		vector<MyStruct> vec;
		int n;
		cin >> n;

		// i0: 상근이, i1,...,in:편의점, in+1: 펜타포트
		for (int i = 0; i < n + 2; i++)
		{
			int x, y;
			cin >> x >> y;
			vec.push_back(MyStruct{ y,x });
		}
		int** d = new int* [(long long)n + 2];
		for (int i = 0; i < n + 2; i++)
		{
			d[i] = new int[(long long)n + 2];
			fill(d[i], d[i] + n + 2, INF);
		}
		for (int i = 0; i < n + 2; i++)
		{
			for (int j = 0; j < n + 2; j++)
			{
				int dist = getDist(vec[i], vec[j]);
				if (dist <= 1000)
				{
					d[i][j] = dist;		// 이거 dist대신에 1해도됨
					d[j][i] = dist;		// 여기 jj 되어있어서 틀렸습니다 나옴
				}
			}
		}
		for (int i = 0; i < n + 2; i++)
		{
			d[i][i] = 0;
		}
		for (int k = 0; k < n + 2; k++)
		{
			for (int i = 0; i < n + 2; i++)
			{
				for (int j = 0; j < n + 2; j++)
				{
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}


		if (d[0][n + 1] != INF)
		{
			out[o] = true;
		}

		//for (int i = 0; i < n + 2; i++)
		//{
		//	for (int j = 0; j < n + 2; j++)
		//	{
		//		cout << (d[i][j] != INF ? d[i][j] : -1) << " ";
		//	}
		//	cout << "\n";
		//}
	}
	for (int i = 0; i < t; i++)
	{
		cout << (out[i] ? "happy" : "sad") << "\n";
	}

	return 0;
}
