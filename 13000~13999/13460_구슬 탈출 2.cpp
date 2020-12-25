/**
 *    BOJ 13460
 *    - 구슬 탈출 2
 *    author:  phcdream
 *    created: 오전 12:09 2020-12-06
**/

#include <iostream>
#include <queue>

typedef long long ll;

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

struct MyPoint
{
	int y = 0;
	int x = 0;
	bool operator==(const MyPoint& mp) {
		return y == mp.y && x == mp.x;
	}
	int operator-(const MyPoint& mp) {
		if (y == mp.y)
			return x - mp.x;
		return y - mp.y;
	}
};

struct MyStruct
{
	MyPoint r;
	MyPoint b;
	bool operator==(const MyStruct& ms) {
		return r == ms.r && b == ms.b;
	}
};

int myAbs(int a)
{
	return a >= 0 ? a : -a;
}

void in(int& N, int& M, char**& arr)
{
	cin >> N >> M;
	arr = new char* [(ll)N + 2];
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new char[(ll)M + 2];
		fill(arr[i], arr[i] + M + 2, '#');
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
}

void move(int N, int M, char** arr, int d, MyPoint& mp, MyPoint& nMP)
{
	for (int k = 0;; k++)
	{
		int nY = mp.y + k * dy[d];
		int nX = mp.x + k * dx[d];
		if (arr[nY][nX] != '#' && arr[nY][nX] != 'O')
			;
		else
		{
			if (arr[nY][nX] == '#')
			{
				nMP.y = nY - dy[d];
				nMP.x = nX - dx[d];
			}
			if (arr[nY][nX] == 'O')
			{
				nMP.y = nY;
				nMP.x = nX;
			}
			break;
		}
	}
}

void rePosition(MyStruct st, MyPoint& nR, MyPoint& nB, int d)
{
	if (myAbs(st.r - nR) < myAbs(st.b - nB))
	{
		nB.y -= dy[d];
		nB.x -= dx[d];
	}
	else
	{
		nR.y -= dy[d];
		nR.x -= dx[d];
	}
}


#define FAIL	-1
#define FINISH	1
#define NOTHING	0
int finish(char** arr, MyPoint nR, MyPoint nB)
{
	char chR = arr[nR.y][nR.x];
	char chB = arr[nB.y][nB.x];
	if (chB == 'O')
		return FAIL;	// B가 구멍에 빠짐 q.push 하지말기
	else if (chR == 'O' && chB != 'O')
		return FINISH;	// R만 구멍에 빠짐. 성공
	else
		return NOTHING;	// 아무일도 없음 q.push하기
}

bool oneStep(int N, int M, char** arr, queue<MyStruct>& q)
{
	int size = (int)q.size();
	MyStruct st;
	for (int sz = 0; sz < size; sz++)
	{
		st = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			MyPoint nR, nB;
			move(N, M, arr, i, st.r, nR);
			move(N, M, arr, i, st.b, nB);

			int re = finish(arr, nR, nB);

			if (nR == nB)
				rePosition(st, nR, nB, i);
			//cout <<"\n";
			//cout << st.r.y << " " << st.r.x << "  " << st.b.y << " " << st.b.x << "  " << re << "\n";
			//cout << nR.y << " " << nR.x << "  " << nB.y << " " << nB.x << "\n";
			switch (re)
			{
			case FAIL:
				break;
			case FINISH:
				return true;
				break;
			case NOTHING:
				if (st == MyStruct({ nR,nB }))	// 안움직였으면,큐에 안넣어도됨.
					;//cout << "no move" << "\n";
				else
					q.push({ nR,nB });
				break;
			default:
				break;
			}
		}
	}
	return false;
}

int solve(int N, int M, char** arr)
{
	queue<MyStruct> q;
	MyStruct st;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (arr[i][j] == 'R')
			{
				st.r.y = i;
				st.r.x = j;
			}
			if (arr[i][j] == 'B')
			{
				st.b.y = i;
				st.b.x = j;
			}
		}
	}
	q.push(st);
	for (int i = 0; i < 10; i++)
	{
		//cout <<"i "<< i <<"##########################"<< "\n";
		bool re = oneStep(N, M, arr, q);
		if (re == true)
			return i + 1;
	}

	return -1;
}

int main()
{
	int N, M;
	char** arr;
	in(N, M, arr);

	int re = solve(N, M, arr);
	cout << re << "\n";

	return 0;
}