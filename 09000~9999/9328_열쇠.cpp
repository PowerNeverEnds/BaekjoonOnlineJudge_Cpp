/**
 *    BOJ 9328
 *    - 열쇠
 *    author:  phcdream
 *    created: 오후 11:48 2020-12-14
**/

#include <iostream>
#include <stack>
#include <vector>
#include <string>

typedef long long ll;

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

struct MyPoint
{
	int y;
	int x;
};

void in(int& h, int& w, char**& arr, bool*& bKey)
{
	cin >> h >> w;
	arr = new char* [(ll)h + 2];
	fill(arr, arr + h + 2, nullptr);
	for (int i = 0; i < h + 2; i++)
	{
		arr[i] = new char[(ll)w + 2];
		fill(arr[i], arr[i] + w + 2, NULL);
	}

	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			cin >> arr[i][j];
		}
	}

	bKey = new bool[(ll)26];
	fill(bKey, bKey + 26, false);
	string str;
	cin.ignore();
	getline(cin, str);
	if (str == "0")
		return;
	for (int i = 0; i < str.length(); i++)
	{
		bKey[str[i] - 'a'] = true;
	}
}

void print(int h, int w, int** visited)
{
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			cout << visited[i][j] << "";
		}
		cout << "\n";
	}
	cout << "\n";
}

void dfs(int& h, int& w, char**& arr, bool*& bKey, stack<MyPoint>& s, int**& visited, vector<MyPoint>*& vec, int& cnt)
{
	MyPoint st;
	while (true)
	{
		//print(h, w, visited);
		//cout << s.size() << "\n";
		if (s.empty())
			break;
		st = s.top();
		s.pop();
		for (int i = 0; i < 4; i++)
		{
			int nY = st.y + dy[i];
			int nX = st.x + dx[i];
			char nCh = arr[nY][nX];
			if (arr[nY][nX] != NULL && arr[nY][nX] != '*' && visited[nY][nX] == 0)
			{
				if (arr[nY][nX] == '.')
				{
					s.push(st);
					visited[nY][nX] = 1;
					s.push({ nY,nX });
				}
				else if (arr[nY][nX] == '$')
				{
					s.push(st);
					cnt++;
					visited[nY][nX] = 1;
					s.push({ nY,nX });
				}
				else
				{
					if (isupper(nCh))
					{
						if (bKey[nCh - 'A'] == true)
						{
							s.push(st);
							visited[nY][nX] = 1;
							s.push({ nY,nX });
						}
						else
						{
							vec[nCh - 'A'].push_back({ nY,nX });
						}
					}
					if (islower(nCh))
					{
						if (bKey[nCh - 'a'] == false)
						{
							bKey[nCh - 'a'] = true;
							s.push(st);
							for (auto e : vec[nCh - 'a'])
							{
								visited[e.y][e.x] = 1;
								s.push({ e.y,e.x });
							}
						}
						visited[nY][nX] = 1;	// lower방문추가
						s.push({ nY,nX });
					}
				}
			}
		}
	}
}

int solve(int& h, int& w, char**& arr, bool*& bKey)
{
	stack<MyPoint> s;
	int** visited = new int* [(ll)h + 2];
	fill(visited, visited + h + 2, nullptr);
	for (int i = 0; i < h + 2; i++)
	{
		visited[i] = new int[(ll)w + 2];
		fill(visited[i], visited[i] + w + 2, 0);
	}

	vector<MyPoint>* vec = new vector<MyPoint>[26];
	int o[2] = { 1,w };
	int io[2] = { h,w };
	int cnt = 0;
	for (int a = 0; a < 2; a++)
	{
		int ay;
		int ax;
		if (a == 0)
		{
			o[0] = 1;
			o[1] = w;
			ay = 1;
			ax = 0;
		}
		else
		{
			o[1] = h;
			ay = 0;
			ax = 1;
		}
		for (int i = 1; i <= io[a]; i++)		// i범위 변경
		{
			for (int k = 0; k < 2; k++)
			{
				int nY = i * ay + o[k] * ax;
				int nX = i * ax + o[k] * ay;
				if (arr[nY][nX] == '*' || visited[nY][nX] != 0)		// visited 추가(중복방문X)
					continue;
				if (arr[nY][nX] == '.')
				{
					visited[nY][nX] = 1;
					s.push({ nY,nX });
				}
				if (isupper(arr[nY][nX]))
				{
					if (bKey[arr[nY][nX] - 'A'] == true)
					{
						visited[nY][nX] = true;
						s.push({ nY,nX });
					}
					else
					{
						vec[arr[nY][nX] - 'A'].push_back({ nY,nX });
					}
				}
				if (islower(arr[nY][nX]))
				{
					bKey[arr[nY][nX] - 'a'] = true;
					visited[nY][nX] = true;
					s.push({ nY,nX });
				}
				if (arr[nY][nX] == '$')
				{
					cnt++;
					visited[nY][nX] = true;
					s.push({ nY,nX });
				}
			}
		}
	}

	dfs(h, w, arr, bKey, s, visited, vec, cnt);

	return cnt;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
	{
		int h, w;
		char** arr;
		bool* bKey;
		in(h, w, arr,bKey);

		int re = solve(h, w, arr,bKey);
		cout << re << "\n";
	}

	return 0;
}

/*
3
5 17
*****************
.............**$*
*B*A*P*C**X*Y*.X.
*y*x*a*p**$*$**$*
*****************
cz
5 11
*.*********
*...*...*x*
*X*.*.*.*.*
*$*...*...*
***********
0
7 7
*ABCDE*
X.....F
W.$$$.G
V.$$$.H
U.$$$.J
T.....K
*SQPML*
irony


1
3 3
*X*
*$*
***
x

1
4 4
*X**
*$Y*
*Y$*
****
x

1
2 2
$$
$$
0

1
3 3
$$$
$$$
$$$
0

1
3 4
$$$$
$$$$
$$$$
0

1
4 4
*B**
*a**
bA$*
****
0

1
4 5
**B**
**a**
.bA$*
*****
0

*/