/**
 *    BOJ 17070
 *    - 파이프 옮기기 1
 *    author:  phcdream
 *    created: 오후 7:41 2020-12-08
**/
/*
#include <iostream>
#include <queue>

typedef long long ll;

using namespace std;

struct MyStruct
{
	int y;
	int x;
	int d;
	bool operator<(const MyStruct& ms) const {		// less->max-heap
		//return y + x > ms.y + x;
		if (y == ms.y)		// dp 로 풀어도될듯.
			return x > ms.x;
		return y > ms.y;
	}
};

void in(int& N, int**& arr)
{
	cin >> N;
	arr = new int* [(ll)N + 2];
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
}

// 그림순서대로 →, ↓, ↘
int dy[3] = { 0,1,1 };
int dx[3] = { 1,0,1 };


void print(int N, int***& visited)
{
	for (int k = 0; k < 3; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout << visited[k][i][j] << " ";
			}cout << "\n";
		}cout << "\n";
	}cout << "\n";
}

void bfs1(int N, int**& arr, int***& visited)
{
	//queue<MyStruct> q;
	priority_queue<MyStruct> q;
	MyStruct st{ 1,2,0 };
	visited[st.d][st.y][st.x] = 1;
	q.push(st);
	while (true)
	{
		if (q.empty())
			break;
		//st = q.front();
		st = q.top();
		q.pop();
		//print(N, visited);
		//cout << st.y << " " << st.x << "\n";
		for (int i = 0; i < 3; i++)
		{
			int nY = st.y + dy[i];
			int nX = st.x + dx[i];

			// visited[i][nY][nX] 에서 고침.
			//int prev = visited[i][nY][nX];
			int prev = visited[0][nY][nX] + visited[1][nY][nX]+visited[2][nY][nX];
			//if (arr[nY][nX] == 0)//&& visited[i][nY][nX] == 0)
			if (arr[nY][nX] == 0 && visited[i][nY][nX] == 0)
			{
				//cout << i << "  " << nY << " " << nX << "\n";
				switch (i)
				{
				case 0:
				{
					visited[i][nY][nX] += visited[0][st.y][st.x];
					visited[i][nY][nX] += visited[2][st.y][st.x];
				}
				break;
				case 1:
				{
					visited[i][nY][nX] += visited[1][st.y][st.x];
					visited[i][nY][nX] += visited[2][st.y][st.x];
				}
				break;
				case 2:
				{
					if (arr[st.y + 1][st.x] == 0 && arr[st.y][st.x + 1] == 0)	// 벽확인
					{
						visited[i][nY][nX] += visited[0][st.y][st.x];
						visited[i][nY][nX] += visited[1][st.y][st.x];
						visited[i][nY][nX] += visited[2][st.y][st.x];
					}
				}
				break;
				default:
					break;
				}
				//if (visited[i][nY][nX] != 0)
				if(prev==0 && visited[i][nY][nX]!=0)
				{
					//cout << "push" << "\n";
					q.push({ nY,nX });
				}
			}
		}
	}
}

void bfs2(int N, int**& arr, int***& visited)
{
	queue<MyStruct> q;
	//priority_queue<MyStruct> q;
	MyStruct st{ 1,2,0 };
	visited[st.d][st.y][st.x] = 1;
	q.push(st);
	while (true)
	{
		if (q.empty())
			break;
		st = q.front();
		//st = q.top();
		q.pop();
		//print(N, visited);
		//cout << st.y << " " << st.x << "\n";
		for (int i = 0; i < 3; i++)
		{
			int nY = st.y + dy[i];
			int nX = st.x + dx[i];

			// visited[i][nY][nX] 에서 고침.
			//int prev = visited[i][nY][nX];
			int prev = visited[0][nY][nX] + visited[1][nY][nX] + visited[2][nY][nX];
			//if (arr[nY][nX] == 0)//&& visited[i][nY][nX] == 0)
			if (arr[nY][nX] == 0 && visited[i][nY][nX] == 0)
			{
				//cout << i << "  " << nY << " " << nX << "\n";
				switch (i)
				{
				case 0:
				{
					visited[i][nY][nX] += visited[0][st.y][st.x];
					visited[i][nY][nX] += visited[2][st.y][st.x];
				}
				break;
				case 1:
				{
					visited[i][nY][nX] += visited[1][st.y][st.x];
					visited[i][nY][nX] += visited[2][st.y][st.x];
				}
				break;
				case 2:
				{
					if (arr[st.y + 1][st.x] == 0 && arr[st.y][st.x + 1] == 0)	// 벽확인
					{
						visited[i][nY][nX] += visited[0][st.y][st.x];
						visited[i][nY][nX] += visited[1][st.y][st.x];
						visited[i][nY][nX] += visited[2][st.y][st.x];
					}
				}
				break;
				default:
					break;
				}
				//if (visited[i][nY][nX] != 0)
				if (prev == 0 && visited[i][nY][nX] != 0)
				{
					//cout << "push" << "\n";
					q.push({ nY,nX });
				}
			}
		}
	}
}

int solve1(int N, int**& arr)
{
	int*** visited = new int** [3];
	fill(visited, visited + 3, nullptr);
	for (int i = 0; i < 3; i++)		// i<N+2에서 i<3으로 변경
	{
		visited[i] = new int* [(ll)N + 2];
		fill(visited[i], visited[i] + N + 2, nullptr);
		for (int j = 0; j < N + 2; j++)
		{
			visited[i][j] = new int[(ll)N + 2];
			fill(visited[i][j], visited[i][j] + N + 2, 0);
		}
	}
	visited[0][1][2] = 1;

	bfs1(N, arr, visited);

	//print(N,visited);

	int re = visited[0][N][N] + visited[1][N][N] + visited[2][N][N];
	delete[]visited;
	return re;
}

int solve2(int N, int**& arr)
{
	int*** visited = new int** [3];
	fill(visited, visited + 3, nullptr);
	for (int i = 0; i < 3; i++)		// i<N+2에서 i<3으로 변경
	{
		visited[i] = new int* [(ll)N + 2];
		fill(visited[i], visited[i] + N + 2, nullptr);
		for (int j = 0; j < N + 2; j++)
		{
			visited[i][j] = new int[(ll)N + 2];
			fill(visited[i][j], visited[i][j] + N + 2, 0);
		}
	}
	visited[0][1][2] = 1;

	bfs2(N, arr, visited);

	//print(N,visited);

	int re = visited[0][N][N] + visited[1][N][N] + visited[2][N][N];
	delete[]visited;
	return re;
}
#include <cstdlib>
#include <ctime>

void makeRandArr(int& N, int**& arr)
{
	if(arr!=nullptr)
		delete[]arr;

	//N = rand() % 5 + 3;
	N = 16;
	arr = new int* [(ll)N + 2];
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
			if (j<=1)
				arr[i][j] = 0;
			else
			{
				//int n = (rand() % (N+N/2+N/3));
				int n = (rand() % (N));
				n = (n != 0 ? 0 : 1);
				arr[i][j] = n;
			}
		}
	}
}

void printArr(int N, int**& arr)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << arr[i][j] << " ";
		}cout << "\n";
	}
}

int main()
{
	std::srand(std::time(nullptr));
	while (true)
	{
		int N;
		int** arr=nullptr;
		//in(N, arr);
		makeRandArr(N,arr);
		arr[1][1] = 0;
		arr[1][2] = 0;

		int re1 = solve1(N, arr);
		int re2 = solve2(N, arr);
		if (re1 == re2)
		{
			//printArr(N, arr);
			//cout << "pass" << "\n";
		}
		else
		{
			if (re1 < 1000)
			{
				cout << N << "\n";
				printArr(N, arr);
				cout << "correct: " << re1 << "\n";
				cout << "wrong: " << re2 << "\n";
				cout << "\n";
			}
		}
		delete[] arr;
	}
	//cout << re2 << "\n";

	return 0;
}
*/

/*
3
0 0 0
0 0 0
0 0 0

4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0

4
0 0 0 0
0 0 0 0
0 0 1 0
0 0 0 0

3
0 0 0
0 1 0
0 0 0

3
0 0 1
0 0 0
0 0 0

3
0 0 0
0 0 0
0 0 1

3
0 0 0
0 0 0
0 1 0

6
0 0 0 0 1 0
0 1 0 0 0 1
0 0 0 0 0 0
0 0 0 1 0 0
0 0 0 0 1 0
0 0 0 0 0 0

6
0 0 0 0 1 0
0 1 0 0 0 1
0 0 0 0 0 0
0 0 0 1 0 0
0 0 0 0 0 0
0 0 0 0 0 0

6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

16
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

16
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 1 1
0 0 0 0 0 0

6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 0 0 0 0

6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 0 0 1 0

6
0 0 0 0 0 0
0 0 0 1 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 0 0 1 0

6
0 0 0 0 0 1
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 0 0 1 0

6
0 0 0 0 1 1
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 0 0 1 0

6
0 0 0 1 1 1
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 0 0 1 0

6
0 0 0 0 1 1
0 1 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 0 0 1 0

6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 0 1 0
0 0 0 0 0 0

6
0 0 0 1 0 0
1 0 0 0 1 0
0 1 0 0 0 1
0 1 0 0 0 0
0 0 1 1 0 0
0 0 0 0 0 0


6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 0 0 0 0


6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 1 0 0 0
0 0 0 0 0 0
0 0 0 0 1 0
correct: 1
wrong: 0

6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
correct: 5
wrong: 4

6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 1 0 0 0
0 0 0 0 0 0
0 0 0 1 0 0
correct: 3
wrong: 2

7
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 1 0 0 0 1 0
0 0 0 0 0 0 0
1 0 0 0 1 1 0
0 0 0 0 0 0 0
0 1 0 0 0 0 0
correct: 9
wrong: 8

7
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 1 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
correct: 53
wrong: 52

16
0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 1 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 1 1 0 0 1 1 0 0 0 0 0 1 0
0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 1 0 0 0 1 0 1 0 0
0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
correct: 109
wrong: 103

16
0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1
0 1 0 1 0 1 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0 0 1 1 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 1 1 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
correct: 664
wrong: 562

*/

/**
 *    BOJ 17070
 *    - 파이프 옮기기 1
 *    author:  phcdream
 *    created: 오후 7:41 2020-12-08
**/

#include <iostream>
#include <queue>

typedef long long ll;

using namespace std;

struct MyStruct
{
	int y;
	int x;
	int d;
	bool operator<(const MyStruct& ms) const {		// less->max-heap
		//return y + x > ms.y + x;
		if (y == ms.y)		// dp 로 풀어도될듯.
			return x > ms.x;
		return y > ms.y;
	}
};

void in(int& N, int**& arr)
{
	cin >> N;
	arr = new int* [(ll)N + 2];
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
}

// 그림순서대로 →, ↓, ↘
int dy[3] = { 0,1,1 };
int dx[3] = { 1,0,1 };


void print(int N, int***& visited)
{
	for (int k = 0; k < 3; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout << visited[k][i][j] << " ";
			}cout << "\n";
		}cout << "\n";
	}cout << "\n";
}

void bfs1(int N, int**& arr, int***& visited)
{
	//queue<MyStruct> q;
	priority_queue<MyStruct> q;
	MyStruct st{ 1,2,0 };
	visited[st.d][st.y][st.x] = 1;
	q.push(st);
	while (true)
	{
		if (q.empty())
			break;
		//st = q.front();
		st = q.top();
		q.pop();
		//print(N, visited);
		//cout << st.y << " " << st.x << "\n";
		for (int i = 0; i < 3; i++)
		{
			int nY = st.y + dy[i];
			int nX = st.x + dx[i];

			// visited[i][nY][nX] 에서 고침.
			//int prev = visited[i][nY][nX];
			int prev = visited[0][nY][nX] + visited[1][nY][nX] + visited[2][nY][nX];
			//if (arr[nY][nX] == 0)//&& visited[i][nY][nX] == 0)
			if (arr[nY][nX] == 0 && visited[i][nY][nX] == 0)
			{
				//cout << i << "  " << nY << " " << nX << "\n";
				switch (i)
				{
				case 0:
				{
					visited[i][nY][nX] += visited[0][st.y][st.x];
					visited[i][nY][nX] += visited[2][st.y][st.x];
				}
				break;
				case 1:
				{
					visited[i][nY][nX] += visited[1][st.y][st.x];
					visited[i][nY][nX] += visited[2][st.y][st.x];
				}
				break;
				case 2:
				{
					if (arr[st.y + 1][st.x] == 0 && arr[st.y][st.x + 1] == 0)	// 벽확인
					{
						visited[i][nY][nX] += visited[0][st.y][st.x];
						visited[i][nY][nX] += visited[1][st.y][st.x];
						visited[i][nY][nX] += visited[2][st.y][st.x];
					}
				}
				break;
				default:
					break;
				}
				//if (visited[i][nY][nX] != 0)
				if (prev == 0 && visited[i][nY][nX] != 0)
				{
					//cout << "push" << "\n";
					q.push({ nY,nX });
				}
			}
		}
	}
}

void bfs2(int N, int**& arr, int***& visited)
{
	queue<MyStruct> q;
	//priority_queue<MyStruct> q;
	MyStruct st{ 1,2,0 };
	visited[st.d][st.y][st.x] = 1;
	q.push(st);
	while (true)
	{
		if (q.empty())
			break;
		st = q.front();
		//st = q.top();
		q.pop();
		//print(N, visited);
		//cout << st.y << " " << st.x << "\n";
		for (int i = 0; i < 3; i++)
		{
			int nY = st.y + dy[i];
			int nX = st.x + dx[i];

			// visited[i][nY][nX] 에서 고침.
			//int prev = visited[i][nY][nX];
			int prev = visited[0][nY][nX] + visited[1][nY][nX] + visited[2][nY][nX];
			//if (arr[nY][nX] == 0)//&& visited[i][nY][nX] == 0)
			if (arr[nY][nX] == 0 && visited[i][nY][nX] == 0)
			{
				//cout << i << "  " << nY << " " << nX << "\n";
				switch (i)
				{
				case 0:
				{
					visited[i][nY][nX] += visited[0][st.y][st.x];
					visited[i][nY][nX] += visited[2][st.y][st.x];
				}
				break;
				case 1:
				{
					visited[i][nY][nX] += visited[1][st.y][st.x];
					visited[i][nY][nX] += visited[2][st.y][st.x];
				}
				break;
				case 2:
				{
					if (arr[st.y + 1][st.x] == 0 && arr[st.y][st.x + 1] == 0)	// 벽확인
					{
						visited[i][nY][nX] += visited[0][st.y][st.x];
						visited[i][nY][nX] += visited[1][st.y][st.x];
						visited[i][nY][nX] += visited[2][st.y][st.x];
					}
				}
				break;
				default:
					break;
				}
				//if (visited[i][nY][nX] != 0)
				if (prev == 0 && visited[i][nY][nX] != 0)
				{
					//cout << "push" << "\n";
					q.push({ nY,nX });
				}
			}
		}
	}
}

int solve1(int N, int**& arr)
{
	int*** visited = new int** [3];
	fill(visited, visited + 3, nullptr);
	for (int i = 0; i < 3; i++)		// i<N+2에서 i<3으로 변경
	{
		visited[i] = new int* [(ll)N + 2];
		fill(visited[i], visited[i] + N + 2, nullptr);
		for (int j = 0; j < N + 2; j++)
		{
			visited[i][j] = new int[(ll)N + 2];
			fill(visited[i][j], visited[i][j] + N + 2, 0);
		}
	}
	visited[0][1][2] = 1;

	bfs1(N, arr, visited);

	//print(N,visited);

	int re = visited[0][N][N] + visited[1][N][N] + visited[2][N][N];
	delete[]visited;
	return re;
}

int solve2(int N, int**& arr)
{
	int*** visited = new int** [3];
	fill(visited, visited + 3, nullptr);
	for (int i = 0; i < 3; i++)		// i<N+2에서 i<3으로 변경
	{
		visited[i] = new int* [(ll)N + 2];
		fill(visited[i], visited[i] + N + 2, nullptr);
		for (int j = 0; j < N + 2; j++)
		{
			visited[i][j] = new int[(ll)N + 2];
			fill(visited[i][j], visited[i][j] + N + 2, 0);
		}
	}
	visited[0][1][2] = 1;

	bfs2(N, arr, visited);

	//print(N,visited);

	int re = visited[0][N][N] + visited[1][N][N] + visited[2][N][N];
	delete[]visited;
	return re;
}


int main()
{
	int N;
	int** arr;
	in(N, arr);

	int re1 = solve1(N, arr);
	int re2 = solve2(N, arr);
	cout << re1 << "\n";

	return 0;
}
