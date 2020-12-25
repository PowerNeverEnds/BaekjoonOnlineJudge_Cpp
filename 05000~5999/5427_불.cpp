/**
 *    BOJ 5427
 *    - 불
 *    author:  phcdream
 *    created: 오전 1:45 2020-12-03
**/

#include <iostream>
#include <queue>

typedef long long ll;

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

struct MyPoint
{
	int y;
	int x;
};

void in(int& h, int& w, char**& arr, int**& visited)
{
	cin >> w >> h;	// 순서
	arr = new char* [(ll)h + 2];
	fill(arr, arr + h + 2, nullptr);
	for (int i = 0; i < h + 2; i++)
	{
		arr[i] = new char[(ll)w + 2];
		fill(arr[i], arr[i] + w + 2, 'e');
	}
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			cin >> arr[i][j];
		}
	}

	visited = new int* [(ll)h + 2];
	fill(visited, visited + h + 2, nullptr);
	for (int i = 0; i < h + 2; i++)
	{
		visited[i] = new int[(ll)w + 2];
		fill(visited[i], visited[i] + w + 2, 0);
	}
}

MyPoint* move(char**& arr, int**& visited, queue<MyPoint>& q)
{
	MyPoint st;
	int size = (int)q.size();
	bool bE = false;
	MyPoint* mpE=nullptr;
	for (int i = 0; i < size; i++)
	{
		st = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nY = st.y + dy[i];
			int nX = st.x + dx[i];
			if (arr[nY][nX] == '.' && visited[nY][nX] ==0)
			{
				visited[nY][nX] = visited[st.y][st.x] + 1;
				q.push(MyPoint({ nY,nX }));
			}
			if (arr[nY][nX] == 'e' && bE==false)
			{
				bE = true;
				mpE = new MyPoint({ nY,nX });
				visited[nY][nX] = visited[st.y][st.x] + 1;
			}
		}
	}

	if (bE == true)
		return mpE;
	else
		return nullptr;
}

int simul(char**& arr, int**& visited, queue<MyPoint>& fire, queue<MyPoint>& me)
{
	while (true)
	{
		//cout << fire.size() << " " << me.size() << "\n";
		if (me.empty())
			return -1;
		MyPoint* e;
		e = move(arr, visited, fire);
		delete[] e;
		e = move(arr, visited, me);
		if (e != nullptr)
			return visited[e->y][e->x] - 1;
	}
}

int solve(int& h, int& w, char**& arr, int**& visited)
{
	queue<MyPoint> fire;
	queue<MyPoint> me;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if (arr[i][j] == '*' || arr[i][j] == '@')
			{
				if (arr[i][j] == '*')
					fire.push(MyPoint({ i,j }));
				if (arr[i][j] == '@')
					me.push(MyPoint({ i,j }));
				visited[i][j] = 1;
			}
		}
	}

	return simul(arr, visited, fire, me);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
	{
		int w, h;
		char** arr;
		int** visited;
		in(h, w, arr,visited);

		int re = solve(h, w, arr, visited);
		if (re == -1)
			cout << "IMPOSSIBLE" << "\n";
		else
			cout << re << "\n";
	}
	return 0;
}

/*
5
4 3
####
#*@.
####
7 6
###.###
#*#.#*#
#.....#
#.....#
#..@..#
#######
7 4
###.###
#....*#
#@....#
.######
5 5
.....
.***.
.*@*.
.***.
.....
3 3
###
#@#
###

6
1 1
@
2 2
**
*@
3 3
#.*
#@#
###
3 3
#..
#@*
###
5 5
#####
*@..#
.##.#
....#
##.##
5 5
#####
*@..#
.##.#
....#
###.#
.
*/