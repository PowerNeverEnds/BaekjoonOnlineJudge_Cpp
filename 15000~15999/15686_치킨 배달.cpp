#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

#define INF ((int)(1e9))

using namespace std;

int myAbs(int a)
{
	return a > 0 ? a : -a;
}

struct MyPoint
{
	int y;
	int x;
};

int dist(const MyPoint& a, const MyPoint& b)
{
	return myAbs(a.y - b.y) + myAbs(a.x - b.x);
}
// i번 집이랑 c번 치킨집 거리
struct MyDist
{
	int c;	//	치킨집 번호
	int d;	//	거리
	bool operator<(const MyDist& md) {
		return d < md.d;
	};
};

int myMin(int a, int b)
{
	return a < b ? a : b;
}


int dp(vector<MyDist>* vmd,int s, int d, int m, int* visited, int chs, int hos, bool& reverse)
{
	int min = INF;
	if (d >= m)
	{
		int sum = 0;
		//for (int i = 0; i < chs; i++)
		//{
		//	cout << visited[i] << " ";
		//}cout << "\n";

		for (int i = 0; i < hos; i++)
		{
			int tmin = INF;
			for (auto e : vmd[i])
			{
				if (visited[e.c] == false)
					continue;
				if (e.d < tmin)
				{
					tmin = e.d;
				}
			}
			//cout << i << " " << tmin << "\n";
			sum += tmin;
		}
		//cout << sum << "\n"<<"\n";
		return sum;
	}
	for (int i = s; i < chs - m + d + 1; i++)
	{
		//visited[d] = i;
		visited[i] = !reverse;
		int re = dp(vmd,i+1, d + 1, m, visited, chs, hos, reverse);
		//visited[d] = 0;
		visited[i] = reverse;
		if (re < min)
		{
			min = re;
		}
	}
	return min;
}

int main()
{
	int N, M;
	cin >> N >> M;
	int** arr = new int* [(ll)N + 2];
	fill(arr, arr + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int[(ll)N + 2];
		fill(arr[i], arr[i] + N + 2, -1);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	int cnt = 0;
	vector<MyPoint> chicken;
	vector<MyPoint> house;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == 2)
			{
				chicken.push_back(MyPoint({ i,j }));
				cnt++;
			}
			else if (arr[i][j] == 1)
			{
				house.push_back(MyPoint({ i,j }));
			}
		}
	}

	vector<MyDist>* vmd = new vector<MyDist>[house.size()];
	for (int i = 0; i < house.size(); i++)
	{
		for (int j = 0; j < chicken.size(); j++)
		{
			vmd[i].push_back(MyDist({ j,dist(house[i],chicken[j]) }));
		}
	}


	for (int i = 0; i < house.size(); i++)
	{
		sort(vmd[i].begin(), vmd[i].end(), [](auto a, auto b) {
			return a < b;
			});
	}

	//for (int i = 0; i < house.size(); i++)
	//{
	//	for (auto e : vmd[i])
	//	{
	//		cout << e.c << " " << e.d << "\n";
	//	}
	//	cout << "\n";
	//}
	int max = 1;

	int* visited = new int[(ll)chicken.size()];
	bool reverse = false;
	if (M > chicken.size() - M)
	{
		reverse = true;
	}
	if (!reverse)
		fill(visited, visited + chicken.size(), 0);
	else
		fill(visited, visited + chicken.size(), 1);
	//cout << reverse << "\n";
	int re = dp(vmd,0, 0, myMin(M, chicken.size() - M), visited, chicken.size(), house.size(), reverse);
	cout << re << "\n";

	//cout << cnt << "\n";

	return 0;
}



/*

5 2
1 2 0 2 1
1 2 0 2 1
1 2 0 0 1
1 2 0 0 1
1 2 0 0 1

*/