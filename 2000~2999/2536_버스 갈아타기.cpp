/**
 *    BOJ 2536
 *    - 버스 갈아타기
 *    author:  phcdream
 *    created: 오후 11:10 2020-12-07
**/

#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

struct MyPoint
{
	int y;
	int x;
	bool operator==(const MyPoint& mp)const {
		return y == mp.y && x == mp.x;
	}
};

int myMin(int a, int b)
{
	return a <= b ? a : b;
}

int myMax(int a, int b)
{
	return a >= b ? a : b;
}
void in(int& m, int& n, int& k, vector<int>*& visitedY, vector<int>*& visitedX, int*& visited, MyPoint**& arr, MyPoint& start, MyPoint& end)
{
	cin >> m >> n;
	visitedY = new vector<int>[(ll)n + 1];
	visitedX = new vector<int>[(ll)m + 1];
	cin >> k;
	arr = new MyPoint * [(ll)k + 1];
	fill(arr, arr + k + 1, nullptr);
	visited = new int[(ll)k + 1];
	fill(visited, visited + k + 1, 0);
	for (int i = 0; i < k + 1; i++)
	{
		arr[i] = new MyPoint[2];
	}
	for (int i = 0; i < k; i++)
	{
		int b, x1, y1, x2, y2;
		cin >> b >> x1 >> y1 >> x2 >> y2;
		arr[b][0] = { y1,x1 };
		arr[b][1] = { y2,x2 };
		if (x1 == x2)
		{
			visitedX[x1].push_back(b);
		}
		if (y1 == y2)
		{
			visitedY[y1].push_back(b);
		}
	}
	int sx, sy, dx, dy;
	cin >> sx >> sy >> dx >> dy;
	start.y = sy;
	start.x = sx;
	end.y = dy;
	end.x = dx;
}
bool isBetween(int a, int b, int mp)
{
	if (a <= mp&& mp <= b || b <= mp && mp <= a)
	{
		return true;
	}
	return false;
}
#include <cassert>
bool isBetween(MyPoint a, MyPoint b, MyPoint mp)
{
	if (a.y == b.y && b.y == mp.y)
	{
		return isBetween(a.x, b.x, mp.x);
	}
	if (a.x == b.x && b.x == mp.x)
	{
		return isBetween(a.y, b.y, mp.y);
	}
	assert(false);
}
#define Y 0
#define X 1
int myTransfer(int st,int l ,int r, bool xy,int stxy,vector<int>*& visitedXY, int*& visited,MyPoint**& arr, MyPoint end, queue<int>& q)
{
	//cout << (xy == Y ? "Y" : "X")<<" "<<stxy << "\n";
	//cout << l << " " << r << "\n";
	for (int i = l; i <= r; i++)
	{
		MyPoint mpt{};
		if (xy == Y)
			mpt = { i,stxy };
		else if (xy == X)
			mpt = { stxy,i };
		//cout << "i " << i << " " << visitedXY[i].size() << "\n";
		for (int j = 0; j < visitedXY[i].size(); j++)
		{
			int nB = visitedXY[i][j];	// nBus
			if (visited[nB] == 0)
			{
				MyPoint a; MyPoint b;
				a = arr[nB][0];
				b = arr[nB][1];
				if (isBetween(a, b, mpt) == true)
				{
					//cout <<"isBetween "<<nB<<"번  "<< mpt.x << " " << mpt.y << "\n";
					visited[nB] = visited[st] + 1;
					q.push(nB);
				}
			}
		}
		if (mpt == end)
		{
			return visited[st];
		}
	}

	return false;
}
int bfs(int& m, int& n, int& k, vector<int>*& visitedY, vector<int>*& visitedX, int*& visited, MyPoint**& arr, MyPoint start, MyPoint end, queue<int>& q)
{
	int st;
	while (true)
	{
		if (q.empty())
			break;
		st = q.front();
		q.pop();
		//cout << st << "번\n";
		int re=0;
		if (arr[st][0].x == arr[st][1].x)
		{
			int min = myMin(arr[st][0].y, arr[st][1].y);
			int max = myMax(arr[st][0].y, arr[st][1].y);
			re = myTransfer(st, min,max, Y, arr[st][0].x, visitedY, visited, arr, end, q);
		}
		else if (arr[st][0].y == arr[st][1].y)
		{
			int min = myMin(arr[st][0].x, arr[st][1].x);
			int max = myMax(arr[st][0].x, arr[st][1].x);
			re = myTransfer(st, min, max, X, arr[st][0].y, visitedX, visited, arr, end, q);
		}
		if (re != 0)
			return re ;
	}
	assert(false);
	return -1;
}

//	m: X, n: Y
int solve(int& m, int& n, int& k, vector<int>*& visitedY, vector<int>*& visitedX, int*& visited, MyPoint**& arr, MyPoint start, MyPoint end)
{
	if (start == end)
		return 0;
	queue<int> q;
	for (int i=0;i<visitedY[start.y].size();i++)
	{
		int e = visitedY[start.y][i];
		MyPoint a = arr[e][0];
		MyPoint b = arr[e][1];
		if (isBetween(a, b, start)==true)
		{
			visited[e] = 1;
			q.push(e);
		}
	}
	for (int i = 0; i < visitedX[start.x].size(); i++)
	{
		int e = visitedX[start.x][i];
		MyPoint a = arr[e][0];
		MyPoint b = arr[e][1];
		if (isBetween(a, b, start) == true)
		{
			visited[e] = 1;
			q.push(e);
		}
	}

	int re = bfs(m, n, k, visitedY, visitedX, visited, arr, start, end,q);
	return re;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, n;
	int k;
	vector<int>* visitedY;
	vector<int>* visitedX;
	int* visited;
	MyPoint** arr;
	MyPoint start; MyPoint end;
	in(m, n, k, visitedY, visitedX, visited, arr, start, end);

	int re = solve(m, n, k, visitedY, visitedX, visited, arr, start, end);
	cout << re << "\n";

	return 0;
}
/*
7 6
8
1 2 1 2 2
2 1 1 5 1
6 7 3 7 6
7 2 1 2 6
3 3 2 6 2
4 5 6 5 1
5 1 5 7 5
8 3 5 6 5
2 1 7 4

7 6
8
1 2 1 2 2
2 1 1 5 1
6 7 3 7 6
7 2 1 2 6
3 3 2 6 2
4 5 6 5 1
5 1 5 7 5
8 3 5 6 5
3 2 2 2

7 6
8
1 2 1 2 2
2 1 1 5 1
6 7 3 7 6
7 2 1 2 6
3 3 2 6 2
4 5 6 5 1
5 1 5 7 5
8 3 5 6 5
2 1 5 1

7 6
8
1 2 1 2 2
2 1 1 5 1
6 7 3 7 6
7 2 1 2 6
3 3 2 6 2
4 5 6 5 1
5 1 5 7 5
8 3 5 6 5
2 1 2 1

7 6
1
1 1 1 5 1
1 1 4 1

7 6
8
1 2 1 2 2
2 1 1 5 1
6 7 3 7 6
7 2 1 2 6
3 3 2 6 2
4 5 6 5 1
5 1 5 7 5
8 3 5 6 5
1 1 7 4

7 6
8
1 2 1 2 2
2 1 1 5 1
6 7 3 7 6
7 2 1 2 6
3 3 2 6 2
4 5 6 5 1
5 1 5 7 5
8 3 5 6 5
7 4 2 1

7 6
8
1 2 2 2 1
2 5 1 1 1
6 7 6 7 3
7 2 6 2 1
3 6 2 3 2
4 5 1 5 6
5 7 5 1 5
8 6 5 3 5
7 4 2 1

6 7
8
1 1 2 2 2
2 1 1 1 5
6 3 7 6 7
7 1 2 6 2
3 2 3 2 6
4 6 5 1 5
5 5 1 5 7
8 5 3 5 6
1 2 4 7


9 9
8
1 1 1 1 9
2 2 1 2 9
3 3 1 3 9
4 4 1 4 9
5 1 1 9 1
6 1 2 9 2
7 1 3 9 3
8 1 4 9 4
1 1 2 2

9 9
8
1 1 1 1 9
2 1 9 9 9
3 9 9 9 1
4 9 1 2 1
5 2 1 2 8
6 2 8 8 8
7 8 8 8 2
8 8 2 3 2
1 1 3 2

9 9
8
1 1 1 1 9
2 1 9 9 9
3 9 9 9 1
4 9 1 2 1
5 2 1 2 8
6 2 8 8 8
7 8 8 8 2
8 8 2 1 2
1 1 5 1

9 9
9
1 1 1 6 1
2 3 5 3 1
3 4 4 7 4
4 7 3 5 3
5 4 1 1 1
6 3 5 7 5
7 1 1 4 1
8 7 9 7 2
9 9 9 1 9
1 1 7 9

*/



/*
잘못풀음 중간에 내릴수잇음.
*/
/*
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <queue>

typedef long long ll;

using namespace std;

struct MyPoint
{
	int y;
	int x;
	bool operator<(const MyPoint& mp) const {
		if (y == mp.y)
			return x < mp.x;
		return y < mp.y;
	}
	bool operator==(const MyPoint& mp) const {
		return y == mp.y && x == mp.x;
	}
};

struct MyNode
{
	MyPoint mp;
	vector<MyNode*> vec;
	bool operator<(const MyNode& mn)const {
		return mp < mn.mp;
	}
};

void in(int& m, int& n, int& k, map<MyPoint,MyNode*>& map, MyPoint& start, MyPoint& end)
{
	cin >> m >> n;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int b, x1, y1, x2, y2;
		cin >> b >> x1 >> y1 >> x2 >> y2;
		MyPoint u{ y1,x1 };
		MyPoint v{ y2, x2 };
		if (map.count(u)==0 || map.count(v) == 0)
		{
			if (map.count(u) == 0 && map.count(v) == 0)
			{
				cout << "new new" << "\n";
				cout << u.x << " " << u.y << " " << v.x << " " << v.y << "\n";
				MyNode* vt = new MyNode;
				map[v] = { vt };
				MyNode* ut = new MyNode;
				map[u] = { ut };
				map[v]->vec.push_back(ut);
				map[u]->vec.push_back(vt);
			}
			else if (map.count(u) == 0)
			{
				cout << "u new" << "\n";
				cout << u.x << " " << u.y  << "\n";
				MyNode* ut = new MyNode;
				map[u] = { ut };
				map[u]->vec.push_back(map[v]);
			}
			else if (map.count(v) == 0)
			{
				cout << "new v" << "\n";
				cout << v.x << " " << v.y << "\n";
				MyNode* vt = new MyNode;
				map[v] = { vt };
				map[v]->vec.push_back(map[u]);
			}
		}
		else
		{
			cout << "push" << "\n";
			cout << u.x << " " << u.y << " " << v.x << " " << v.y << "\n";
			map[u]->vec.push_back(map[v]);
			map[v]->vec.push_back(map[u]);
		}
	}
	int sx, sy, dx, dy;
	cin >> sx >> sy >> dx >> dy;
	start.y = sy;
	start.x = sx;
	end.y = dy;
	end.x = dx;
}

int solve(int& m, int& n, int& k, map<MyPoint, MyNode*>& map, MyPoint& start, MyPoint& end)
{
	if (start == end)
		return 0;

	std::map<MyPoint, int> visited;

	queue<MyPoint> q;
	visited[start] = 1;
	q.push(start);
	MyPoint st;
	while (true)
	{
		if (q.empty())
			break;
		st = q.front();
		q.pop();
		cout << st.x << " " << st.y << "\n";
		MyNode* mn = map[st];
		for (auto e : mn->vec)
		{
			cout << e->mp.x << " " << e->mp.y << "\n";
			if (visited.count(e->mp) == 0)
			{
				visited[e->mp] = visited[st] + 1;
				q.push(e->mp);
				if (e->mp == end)
					return visited[e->mp] - 1;
			}
		}
	}

	return -1;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, n;
	int k;
	map<MyPoint, MyNode*> map;
	MyPoint start; MyPoint end;

	in(m, n, k,map,start,end);

	int re = solve(m, n, k, map,start,end);
	cout << re << "\n";

	return 0;
}
*/