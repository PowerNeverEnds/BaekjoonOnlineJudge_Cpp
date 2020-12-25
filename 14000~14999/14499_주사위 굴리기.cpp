/**
 BOJ 14499
 - 주사위 굴리기
 - 오전 4:24 2020-11-27
 */

/*
2818_숙제하기 싫을 때
*/




#include <iostream>

typedef long long ll;

using namespace std;

// 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4로 주어진다. 0번 인덱스는 없음.
int dy[5] = { 0,0,0,-1,1 };
int dx[5] = { 0,1,-1,0,0 };

struct MyDice
{
public:
	int front = 0;
	int back = 0;
	int up = 0;
	int down = 0;
	int left = 0;
	int right = 0;

	void move(int d)
	{
		switch (d)
		{
		case 1:
			moveEast();
			break;
		case 2:
			moveWest();
			break;
		case 3:
			moveNorth();
			break;
		case 4:
			moveSouth();
			break;
		default:
			break;
		}
	}

	void moveEast()
	{
		int t = front;
		front = left;
		left = back;
		back = right;
		right = t;
	}

	void moveWest()
	{
		int t = front;
		front = right;
		right = back;
		back = left;
		left = t;
	}

	void moveNorth()
	{
		int t = front;
		front = down;
		down = back;
		back = up;
		up = t;
	}

	void moveSouth()
	{
		int t = front;
		front = up;
		up = back;
		back = down;
		down = t;
		//show();
	}

	void show()
	{
		cout << "  " << up << "\n";
		cout << left << " " << front << " " << right << "\n";
		cout << "  " << down << "\n";
		cout << "  " << back << "\n";
	}
};

// MyDice 참조자인지 확인하기
void setMap(int** arr, int nY, int nX, MyDice& md)
{
	if (arr[nY][nX] == 0)
	{
		arr[nY][nX] = md.back;
	}
	else
	{
		md.back = arr[nY][nX];
		arr[nY][nX] = 0;
	}
}

// x y반대로 받음
void simul(int** arr, MyDice& md, int& y, int& x, int K)
{
	for (int i = 0; i < K; i++)
	{
		int comm;
		cin >> comm;
		int nY = y + dy[comm];
		int nX = x + dx[comm];
		//cout << nY << " " << nX << "\n";
		if (arr[nY][nX] == -1)
			continue;

		md.move(comm);
		setMap(arr, nY, nX, md);
		//md.show();
		cout << md.front << "\n";

		y = nY;
		x = nX;
	}
}

void init(int& N, int& M, int& x, int& y, int& K, int**& arr)
{
	cin >> N >> M >> x >> y >> K;
	x++;
	y++;
	arr = new int* [(ll)N + 2];
	fill(arr, arr + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int[(ll)M + 2];
		fill(arr[i], arr[i] + M + 2, -1);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, x, y, K;
	int** arr = nullptr;

	init(N, M, x, y, K, arr);
	//for (int i = 1; i <= 4; i++)
	//{
	//	for (int j = 1; j <= 2; j++)
	//		cout << arr[i][j] << " ";
	//	cout << "\n";
	//}
	MyDice md;

	simul(arr, md, x, y, K);

	return 0;
}