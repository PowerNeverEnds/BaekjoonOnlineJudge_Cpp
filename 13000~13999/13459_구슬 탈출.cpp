#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

class MyStruct
{
public:
	int y;
	int x;
	bool const operator <(const MyStruct& b) {
		if (this->y == b.y)
			return  this->x < b.x;
		else
			return this->y < b.y;
	};
	bool const operator==(const MyStruct& b) {
		return (this->y == b.y && this->x == b.x);
	};
};
class MyBalls
{
public:
	MyStruct r;
	MyStruct b;
	bool const operator<(const MyBalls& b) {
		if (this->r == b.r)
			return this->b < b.b;
		else
			return this->r < b.r;
	};
};

bool moveOneStep(MyStruct& n, int iy, int ix,char cBall, char** arr)
{

	if (arr[n.y + iy][n.x + ix] == '.' && arr[n.y][n.x] != 'O')
	{
		n.y += iy;
		n.x += ix;
		arr[n.y][n.x] = cBall;
		arr[n.y - iy][n.x - ix] = '.';
		return true;
	}
	else if (arr[n.y + iy][n.x + ix] == 'O')
	{
		n.y += iy;
		n.x += ix;
		arr[n.y - iy][n.x - ix] = '.';
		return false;
	}
	else
	{
		return false;
	}
}

void move(MyStruct& nR, MyStruct& nB,int iy,int ix, char** arr, MyBalls& start)
{
	while (true)
	{
		if (moveOneStep(nR, iy, ix,arr[nR.y][nR.x], arr))
		{
		}
		else if (moveOneStep(nB, iy, ix, arr[nB.y][nB.x], arr))
		{
		}
		else
		{
			break;
		}
	}
}

bool isGoal(MyStruct& nR, MyStruct& nB,char** arr)
{
	if (arr[nR.y][nR.x] == 'O' && arr[nB.y][nB.x] != 'O')
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool isSuicideGoal(MyStruct& nR, MyStruct& nB, char** arr)
{
	if (arr[nB.y][nB.x] == 'O')
	{
		return true;
	}
	else
	{
		return false;
	}

}

void clear(MyBalls start,char** arr,MyStruct Opening)
{
	arr[start.r.y][start.r.x] = '.';
	arr[start.b.y][start.b.x] = '.';
	arr[Opening.y][Opening.x] = 'O';
}

bool bfs(MyBalls start, char** arr, int depth,map<pair<pair<int,int>,pair<int,int>>,int>& visited, int N, int M, MyStruct Opening)
{
	queue<MyBalls> q;
	pair<int, int > psr = make_pair(start.r.y, start.r.x);
	pair<int, int > psb = make_pair(start.b.y, start.b.x);
	visited[make_pair(psr,psb)] = 1;
	q.push(start);
	
	while (true)
	{
		if (q.empty())
			break;
		start = q.front();
		q.pop();
		MyStruct nR{ start.r.y,start.r.x };
		MyStruct nB{ start.b.y,start.b.x };
		pair<int, int > psr = make_pair(start.r.y, start.r.x);
		pair<int, int > psb = make_pair(start.b.y, start.b.x);
		if (visited.count(make_pair(psr, psb)) && visited[make_pair(psr, psb)]-1 == depth)
			break;
		arr[start.r.y][start.r.x] = 'R';
		arr[start.b.y][start.b.x] = 'B';

		for (int i = 0; i < 4; i++)
		{
			MyStruct nR{ start.r.y,start.r.x };
			MyStruct nB{ start.b.y,start.b.x };
			arr[start.r.y][start.r.x] = 'R';
			arr[start.b.y][start.b.x] = 'B';
			move(nR,nB,dy[i],dx[i], arr,start);

			pair<int, int > pnr = make_pair(nR.y, nR.x);
			pair<int, int > pnb = make_pair(nB.y, nB.x);
			pair<int, int > psr = make_pair(start.r.y, start.r.x);
			pair<int, int > psb = make_pair(start.b.y, start.b.x);
			if (!visited.count(make_pair(pnr, pnb)) || visited[make_pair(psr, psb)] > visited[make_pair(pnr, pnb)]+1 )
			{
				if (isGoal(nR, nB, arr))
				{
					return true;
				}
				else if (isSuicideGoal(nR, nB, arr))
				{
					clear(MyBalls{ nR,nB }, arr, Opening);
					clear(start, arr, Opening);
					continue;
				}
				else
				{
					arr[start.r.y][start.r.x] = '.';
					arr[start.b.y][start.b.x] = '.';
					pair<int, int > pnr = make_pair(nR.y, nR.x);
					pair<int, int > pnb = make_pair(nB.y, nB.x);
					pair<int, int > psr = make_pair(start.r.y, start.r.x);
					pair<int, int > psb = make_pair(start.b.y, start.b.x);
					visited[make_pair(pnr, pnb)] = visited[make_pair(psr, psb)] + 1;
					clear(MyBalls{ nR,nB }, arr,Opening);
					clear(start, arr, Opening);
					q.push(start);
					q.push(MyBalls{ nR,nB });
				}
			}
			clear(start, arr,Opening);
			clear(MyBalls{ nR,nB }, arr, Opening);

			
		}
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	// 보드판저장
	char** arr = new char* [N];
	fill(arr, arr + N, nullptr);
	for (int i = 0; i < N; i++)
	{
		arr[i] = new char[M];
		fill(arr[i], arr[i] + M, NULL);
	}
	
	// 보드판입력받기
	for (int i = 0; i < N; i++)
	{
		string str;
		cin.ignore();
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = str[j];
		}
	}

	//Red, Blue 구슬 저장.
	MyStruct red{ 0,0 };
	MyStruct blue{ 0,0 };
	MyStruct Opening{ 0,0 };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 'R')
			{
				red.y = i;
				red.x = j;
			}
			if (arr[i][j] == 'B')
			{
				blue.y = i;
				blue.x = j;
			}
			if (arr[i][j] == 'O')
			{
				Opening.y = i;
				Opening.x = j;
			}
		}
	}

	map<pair<pair<int, int>, pair<int, int>>, int> visited;
	int result = bfs(MyBalls{ red,blue }, arr, 10,visited,N,M, Opening);
	cout << result << "\n";

	return 0;
}

/*

#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <queue>

using namespace std;

int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

class MyStruct
{
public:
	int y;
	int x;
	bool const operator <(const MyStruct& b) {
		if (this->y == b.y)
			return  this->x < b.x;
		else
			return this->y < b.y;
	};
	bool const operator==(const MyStruct& b) {
		return (this->y == b.y && this->x == b.x);
	};
};
class MyBalls
{
public:
	MyStruct r;
	MyStruct b;
	bool const operator<(const MyBalls& b) {
		if (this->r == b.r)
			return this->b < b.b;
		else
			return this->r < b.r;
	};
};

bool moveOneStep(MyStruct& n, int iy, int ix,char cBall, char** arr)
{

	if (arr[n.y + iy][n.x + ix] == '.' && arr[n.y][n.x] != 'O')
	{
		n.y += iy;
		n.x += ix;
		arr[n.y][n.x] = cBall;
		arr[n.y - iy][n.x - ix] = '.';
		return true;
	}
	else if (arr[n.y + iy][n.x + ix] == 'O')
	{
		n.y += iy;
		n.x += ix;
		//return false;
		//arr[n.y][n.x] = cBall;
		arr[n.y - iy][n.x - ix] = '.';
		return false;
	}
	else
	{
		return false;
	}
}

void move(MyStruct& nR, MyStruct& nB,int iy,int ix, char** arr, MyBalls& start)
{
	while (true)
	{
		if (moveOneStep(nR, iy, ix,arr[nR.y][nR.x], arr))
		{
			//arr[nR.y][nR.x] = 'R';
			//arr[nR.y-iy][nR.x-ix] = '.';
			//arr[nB.y][nB.x] = 'B';
		}
		else if (moveOneStep(nB, iy, ix, arr[nB.y][nB.x], arr))
		{
			//arr[nB.y][nB.x] = 'B';
			//arr[nB.y-iy][nB.x-ix] = '.';
		}
		else
		{
			break;
		}
	}
}

bool isGoal(MyStruct& nR, MyStruct& nB,char** arr)
{
	if (arr[nR.y][nR.x] == 'O' && arr[nB.y][nB.x] != 'O')
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool isSuicideGoal(MyStruct& nR, MyStruct& nB, char** arr)
{
	if (arr[nB.y][nB.x] == 'O')
	{
	return true;
	}
	else
	{
	return false;
	}

}

void clear(MyBalls start, char** arr, MyStruct Opening)
{

	//arr[nR.y][nR.x] = 'R';
	arr[start.r.y][start.r.x] = '.';
	//arr[nB.y][nB.x] = 'B';
	arr[start.b.y][start.b.x] = '.';

	arr[Opening.y][Opening.x] = 'O';
}

bool bfs(MyBalls start, char** arr, int depth, map<pair<pair<int, int>, pair<int, int>>, int>& visited, int N, int M, MyStruct Opening)
{
	//stack<MyBalls> s;
	//visited[start] = true;
	//s.push(start);

	queue<MyBalls> q;
	pair<int, int > psr = make_pair(start.r.y, start.r.x);
	pair<int, int > psb = make_pair(start.b.y, start.b.x);
	visited[make_pair(psr, psb)] = 1;
	q.push(start);

	while (true)
	{
		//start = s.top();
		//s.pop();
		if (q.empty())
			break;
		start = q.front();
		q.pop();
		MyStruct nR{ start.r.y,start.r.x };
		MyStruct nB{ start.b.y,start.b.x };
		pair<int, int > psr = make_pair(start.r.y, start.r.x);
		pair<int, int > psb = make_pair(start.b.y, start.b.x);
		if (visited.count(make_pair(psr, psb)) && visited[make_pair(psr, psb)] - 1 == depth)
			break;
		//arr[nR.y][nR.x] = 'R';
		arr[start.r.y][start.r.x] = 'R';
		//arr[nB.y][nB.x] = 'B';
		arr[start.b.y][start.b.x] = 'B';
		//for (int i = 0; i < N; i++)
		//{
		//	for (int j = 0; j < M; j++)
		//	{
		//		cout << arr[i][j];
		//	}cout << "\n";
		//}cout << "\n";
		for (int i = 0; i < 4; i++)
		{
			MyStruct nR{ start.r.y,start.r.x };
			MyStruct nB{ start.b.y,start.b.x };
			//arr[nR.y][nR.x] = 'R';
			arr[start.r.y][start.r.x] = 'R';
			//arr[nB.y][nB.x] = 'B';
			arr[start.b.y][start.b.x] = 'B';
			move(nR, nB, dy[i], dx[i], arr, start);

			pair<int, int > pnr = make_pair(nR.y, nR.x);
			pair<int, int > pnb = make_pair(nB.y, nB.x);
			pair<int, int > psr = make_pair(start.r.y, start.r.x);
			pair<int, int > psb = make_pair(start.b.y, start.b.x);
			if (!visited.count(make_pair(pnr, pnb)) || visited[make_pair(psr, psb)] > visited[make_pair(pnr, pnb)] + 1)
			{
				//cout << nR.y << " " << nR.x << " " << nB.y << " " << nB.x << "\n";
				if (isGoal(nR, nB, arr))
				{
					return true;
				}
				else if (isSuicideGoal(nR, nB, arr))
				{
					//arr[nR.y][nR.x] = '.';
					//arr[nB.y][nB.x] = '.';
					clear(MyBalls{ nR,nB }, arr, Opening);
					clear(start, arr, Opening);
					continue;
				}
				else
				{
					//arr[nR.y][nR.x] = 'R';
					arr[start.r.y][start.r.x] = '.';
					//arr[nB.y][nB.x] = 'B';
					arr[start.b.y][start.b.x] = '.';
					//visited[MyBalls{ nR,nB }] = visited[start] + 1;
					pair<int, int > pnr = make_pair(nR.y, nR.x);
					pair<int, int > pnb = make_pair(nB.y, nB.x);
					pair<int, int > psr = make_pair(start.r.y, start.r.x);
					pair<int, int > psb = make_pair(start.b.y, start.b.x);
					visited[make_pair(pnr, pnb)] = visited[make_pair(psr, psb)] + 1;
					clear(MyBalls{ nR,nB }, arr, Opening);
					clear(start, arr, Opening);
					q.push(start);
					q.push(MyBalls{ nR,nB });
					//if (visited[make_pair(pnr, pnb)] == depth)
					//	q.pop();
				}
			}
			////arr[nR.y][nR.x] = 'R';
			//arr[start.r.y][start.r.x] = '.';
			////arr[nB.y][nB.x] = 'B';
			//arr[start.b.y][start.b.x] = '.';
			clear(start, arr, Opening);
			clear(MyBalls{ nR,nB }, arr, Opening);


		}
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	// 보드판저장
	char** arr = new char* [N];
	fill(arr, arr + N, nullptr);
	for (int i = 0; i < N; i++)
	{
		arr[i] = new char[M];
		fill(arr[i], arr[i] + M, NULL);
	}

	// 보드판입력받기
	for (int i = 0; i < N; i++)
	{
		string str;
		cin.ignore();
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = str[j];
		}
	}

	//Red, Blue 구슬 저장.
	MyStruct red{ 0,0 };
	MyStruct blue{ 0,0 };
	MyStruct Opening{ 0,0 };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 'R')
			{
				red.y = i;
				red.x = j;
			}
			if (arr[i][j] == 'B')
			{
				blue.y = i;
				blue.x = j;
			}
			if (arr[i][j] == 'O')
			{
				Opening.y = i;
				Opening.x = j;
			}
		}
	}

	//map<MyBalls,int> visited;

	map<pair<pair<int, int>, pair<int, int>>, int> visited;
	int result = bfs(MyBalls{ red,blue }, arr, 10, visited, N, M, Opening);
	cout << result << "\n";

	return 0;
}

*/