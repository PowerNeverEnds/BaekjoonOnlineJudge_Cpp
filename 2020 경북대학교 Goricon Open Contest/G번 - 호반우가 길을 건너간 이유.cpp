/*

#include <iostream>
#include <vector>

using namespace std;

struct MyStruct
{
	int y;
	int x;
};

int arr[1001][1001];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int e;
			cin >> e;
			arr[i][j] = e;
		}
	}
	vector<MyStruct> vec;

	for (int i = 0; i < N + M; i += 2)
	{
		if (i + 1 >= N || i + 1 >= M)
			break;
		vec.push_back(MyStruct({ i,i }));
		vec.push_back(MyStruct({ i + 1,i + 1 }));
		vec.push_back(MyStruct({ i,i }));
		vec.push_back(MyStruct({ i + 1,i + 1 }));
	}
	int yy = vec.back().y;
	int xx = vec.back().x;
	if (N < M)
	{
		//cout << "M" << "\n";
		if (N % 2 == 1)
		{
			vec.push_back(MyStruct({ yy,xx + 1 }));
			vec.push_back(MyStruct({ yy + 1,xx }));
			vec.push_back(MyStruct({ yy,xx + 1 }));
			vec.push_back(MyStruct({ yy + 1,xx }));
			//vec.push_back(MyStruct({ yy + 1,xx + 1 }));
			yy = yy+1;
			//xx = xx+1;
		}
		//cout <<"v "<< vec.back().y << " "<<vec.back().x << "\n";
		for (int i = xx + 1; i < N + M; i += 2)
		{
			if (i +1 >= M)
				break;
			vec.push_back(MyStruct({ yy,i }));
			vec.push_back(MyStruct({ yy,i + 1 }));
			vec.push_back(MyStruct({ yy,i }));
			vec.push_back(MyStruct({ yy,i + 1 }));
		}
		if (vec.back().y != N-1 || vec.back().x != M-1)
		{
			vec.push_back(MyStruct({ N - 1 - 1,M - 1 }));
			vec.push_back(MyStruct({ N - 1,M - 1 }));
			vec.push_back(MyStruct({ N - 1 - 1,M - 1 }));
			vec.push_back(MyStruct({ N - 1,M - 1 }));
		}
	}
	else if (N > M)
	{
		//cout << "N" << "\n";
		if (M % 2 == 1)
		{
			vec.push_back(MyStruct({ yy,xx + 1 }));
			vec.push_back(MyStruct({ yy + 1,xx }));
			vec.push_back(MyStruct({ yy,xx + 1 }));
			vec.push_back(MyStruct({ yy + 1,xx }));
			//vec.push_back(MyStruct({ yy + 1,xx + 1 }));
			//yy = yy+1;
			xx = xx+1;
		}
		//cout << "v " << vec.back().y << " " << vec.back().x << "\n";
		for (int i = yy + 1; i < N + M; i += 2)
		{
			if (i + 1 >= N)
				break;
			vec.push_back(MyStruct({ i,xx }));
			vec.push_back(MyStruct({ i + 1,xx }));
			vec.push_back(MyStruct({ i,xx }));
			vec.push_back(MyStruct({ i + 1,xx }));
		}

		if (vec.back().y != N-1 || vec.back().x != M-1)
		{
			vec.push_back(MyStruct({ N - 1,M - 1-1 }));
			vec.push_back(MyStruct({ N - 1,M - 1 }));
			vec.push_back(MyStruct({ N - 1,M - 1-1 }));
			vec.push_back(MyStruct({ N - 1,M - 1 }));
		}
	}
	else
	{
		if (N % 2 == 1)
		{
			vec.push_back(MyStruct({ N - 1 - 1,M - 1 }));
			vec.push_back(MyStruct({ N - 1,M - 1 }));
			vec.push_back(MyStruct({ N - 1 - 1,M - 1 }));
			vec.push_back(MyStruct({ N - 1,M - 1 }));
		}
	}
	int a = 0;
	cout << vec.size() << "\n";
	for (auto e : vec)
	{
		a ^= arr[e.y][e.x];
		//cout << e.y << " " << e.x  << " " << arr[e.y][e.x] << " " << a << "\n";
		cout << e.y << " " << e.x << "\n";
	}
	return 0;
}
*/

/*
3 3
1 2 3
4 5 6
1 6 7

4 4
1 2 3 4
4 5 6 3
1 6 7 4
1 9 75 4

4 3
1 2 3
4 5 6
1 6 7
4 9 8


6 3
1 2 3
4 5 6
1 6 7
4 9 8
1 6 7
4 9 8

4 6
1 2 3 5 7 9
4 5 6 6 9 8
1 6 7 8 8 6
4 9 8 7 8 5

4 5
1 2 3 5 7
4 5 6 6 9
1 6 7 8 8
4 9 8 7 8

3 6
1 2 3 5 7 9
4 5 6 6 9 8
1 6 7 8 8 6

3 5
1 2 3 5 7
4 5 6 6 9
1 6 7 8 8


*/
/*
https://www.acmicpc.net/source/23723266
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

typedef long long ll;

vector<pair<int, int> > v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int a; cin >> a;
		}
	int x = 0, y = 0;
	while (x < n - 1 || y < m - 1) {
		v.push_back(make_pair(x, y));
		if (x == 0 && y == 0 && ((n + m - 1) & 1)) {
			x++; y++;
		}
		else if (x < n - 1) x++;
		else y++;
	}
	v.push_back(make_pair(x, y));
	cout << v.size() * 2 << '\n';
	for (int i = 0; i < v.size(); i += 2)
		for (int j = 0; j < 4; j++)
			cout << v[(ll)i + (j & 1)].first << " " << v[(ll)i + (j & 1)].second << '\n';
	return 0;
}