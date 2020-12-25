#include <iostream>
#include <queue>

typedef long long ll;

#define CHEEZE 1
#define OUTSIDE 2
#define INSIDE 0

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

struct MyPoint
{
	int y;
	int x;
};

void print(int** arr, int N, int M)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << arr[i][j] << " ";
		}cout << "\n";
	}cout << "\n";
}

void bfs(MyPoint st, int** arr, int N, int M, int from, int to)
{
	queue<MyPoint> q;
	arr[st.y][st.x] = to;
	q.push(st);
	while (true)
	{
		if (q.empty())
			break;
		st = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nY = st.y + dy[i];
			int nX = st.x + dx[i];
			if (arr[nY][nX] == from)
			{
				arr[nY][nX] = to;
				q.push(MyPoint({ nY,nX }));
			}
		}
	}
}

void setMeltCheeze(int** arr, queue<MyPoint>& cheeze, queue<MyPoint>& meltCheeze)
{
	MyPoint st;
	int i = 0;
	int cheezeSize = (int)cheeze.size();
	for(int i=0;i<cheezeSize;i++)
	{
		st = cheeze.front();
		int cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			int nY = st.y + dy[i];
			int nX = st.x + dx[i];
			if (arr[nY][nX] == OUTSIDE)
			{
				cnt++;
			}
		}
		//cout <<st.y<<" "<<st.x<<" "<< cnt << "\n";
		if (cnt >= 2)
		{
			meltCheeze.push(st);
			cheeze.pop();
		}
		else
		{
			cheeze.pop();
			cheeze.push(st);
		}
	}
}

int simul(int** arr, int N, int M)
{
	bfs(MyPoint({ 1,1 }),arr, N, M, INSIDE, OUTSIDE);
	//print(arr, N, M);
	queue<MyPoint> meltCheeze;
	queue<MyPoint> cheeze;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (arr[i][j] == CHEEZE)
				cheeze.push(MyPoint({ i,j }));
		}
	}

	int cnt = 0;
	while (true)
	{
		//print(arr, N, M);
		//cout << cheeze.size() << " ";
		setMeltCheeze(arr, cheeze, meltCheeze);
		//cout << meltCheeze.size() << "\n";
		if (meltCheeze.empty())
			break;
		MyPoint st;
		while (true)
		{
			if (meltCheeze.empty())
				break;
			st = meltCheeze.front();
			meltCheeze.pop();
			arr[st.y][st.x] = OUTSIDE;
			for (int i = 0; i < 4; i++)
			{
				int nY = st.y + dy[i];
				int nX = st.x + dx[i];
				if (arr[nY][nX] == INSIDE)
				{
					bfs(MyPoint({ nY,nX }), arr, N, M, INSIDE, OUTSIDE);
				}
			}
		}
		cnt++;
	}
	return cnt;
}

int main()
{
	int N, M;
	cin >> N >> M;
	int** arr = new int* [(ll)N+2];
	fill(arr, arr + N+2, nullptr);
	for (int i = 0; i < N+2; i++)
	{
		arr[i] = new int[(ll)M+2];
		fill(arr[i], arr[i] + M+2, OUTSIDE);
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}

	int cnt = simul(arr, N, M);

	cout << cnt << "\n";

	return 0;
}

/*
8 9
0 0 0 0 0 0 0 0 0
0 0 0 1 1 0 0 0 0
0 0 0 1 1 0 1 1 0
0 0 1 1 1 1 1 1 0
0 0 1 1 1 1 1 0 0
0 0 1 1 0 1 1 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0


8 9
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 1 1 0
0 1 0 1 1 1 0 1 0
0 1 0 0 1 0 0 1 0
0 1 0 1 1 1 0 1 0
0 1 1 0 0 0 1 1 0
0 0 0 0 0 0 0 0 0
*/