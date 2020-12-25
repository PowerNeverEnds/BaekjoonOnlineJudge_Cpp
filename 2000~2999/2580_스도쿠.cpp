/*
#include <iostream>
#include <deque>
#include <vector>
#include <stack>

using namespace std;

struct MyStruct
{
	int y;
	int x;
};

int dy[10] = { -1,-1,-1,0,0,0,1,1,1 };
int dx[10] = { -1,0,1,-1,0,1,-1,0,1 };


bool dfs(MyStruct st, int arr[][9], stack<MyStruct>& dq, vector<int> visited[][9])
{
	st = dq.top();
	dq.pop();
	int exist = false;
	int i = st.y;
	int j = st.x;
	for (auto e : visited[st.y][st.x])
	{
		exist = false;
		for (int i = 0; i < 9; i++)
		{
			if (e == arr[st.y][i] || e == arr[i][st.x])
			{
				exist = true;
				break;
			}
		}
		for (int k = 0; k < 10; k++)
		{
			if (e == arr[i / 3 * 3 + 1 + dy[k]][j / 3 * 3 + 1 + dx[k]])
			{
				exist = true;
				break;
			}
		}
		if (exist == false)
		{
			arr[st.y][st.x] = e;
			if (dq.empty())
				return true;
			if (dfs(st, arr, dq, visited))
				return true;
			else
				arr[st.y][st.x] = 0;
		}
	}
	dq.push(st);
	return false;
}

int main()
{
	int arr[9][9] = { 0, };
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];

	vector<int> visited[9][9];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] != 0)
				continue;
			bool exist[10] = { 0, };
			for (int k = 0; k < 9; k++)
			{
				exist[arr[i][k]] = true;
				exist[arr[k][j]] = true;
			}
			for (int k = 0; k < 10; k++)
				exist[arr[i / 3 * 3 + 1 + dy[k]][j / 3 * 3 + 1 + dx[k]]] = true;

			for (int k = 1; k <= 9; k++)
				if (exist[k] == false)
					visited[i][j].push_back(k);
		}
	}

	stack<MyStruct> dq;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (arr[i][j] == 0)
				dq.push(MyStruct({ i,j }));

	dfs(MyStruct({}), arr, dq, visited);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}cout << "\n";

	return 0;
}
*/
/*
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0

*/


#include <iostream>
#include <deque>
#include <vector>
#include <stack>

using namespace std;

struct MyStruct
{
	int y;
	int x;
};

// 위에서 아래로, 왼쪽부터 오른쪽으로
int dy[10] = { -1,-1,-1,0,0,0,1,1,1 };
int dx[10] = { -1,0,1,-1,0,1,-1,0,1 };


bool dfs(int arr[][9], stack<MyStruct>& dq, vector<int> visited[][9])
{
	//for (int i = 0; i < 9; i++)
	//{
	//	for (int j = 0; j < 9; j++)
	//		cout << arr[i][j] << " ";
	//	cout << "\n";
	//}cout << "\n";
	MyStruct st;
	st = dq.top();
	dq.pop();
	//cout << st.y << " " << st.x << "\n";
	for (auto e : visited[st.y][st.x])
	{
		int exist = false;
		for (int i = 0; i < 9; i++)
		{
			if (e == arr[st.y][i] || e == arr[i][st.x])
			{
				exist = true;
				break;
			}
		}
		for (int k = 0; k < 10; k++)
		{
			int i = st.y;
			int j = st.x;
			if (e == arr[i / 3 * 3 + 1 + dy[k]][j / 3 * 3 + 1 + dx[k]])
			{
				exist = true;
				break;
			}
			//int et = arr[i / 3 * 3 + 1 + dy[k]][j / 3 * 3 + 1 + dx[k]];
			//cout << i / 3 * 3 + 1 + dy[k] << " " << j / 3 * 3 + 1 + dx[k] << " " << et << "\n";
		}
		if (exist == false)
		{
			arr[st.y][st.x] = e;
			if (dq.empty())
				return true;
			if (dfs(arr, dq, visited))
				return true;
			else
			{
				//dq.push(st);
				arr[st.y][st.x] = 0;
			}
		}
	}
	dq.push(st);
	return false;
}

int main()
{
	int arr[9][9] = { 0, };
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];

	vector<int> visited[9][9];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] != 0)
				continue;
			bool exist[10] = { 0, };
			for (int k = 0; k < 9; k++)
			{
				exist[arr[i][k]] = true;
				exist[arr[k][j]] = true;
			}
			for (int k = 0; k < 10; k++)
			{
				exist[arr[i / 3 * 3 + 1 + dy[k]][j / 3 * 3 + 1 + dx[k]]] = true;
				//int et = arr[i / 3 * 3 + 1 + dy[k]][j / 3 * 3 + 1 + dx[k]];
				//cout << i / 3 * 3 + 1 + dy[k] << " " << j / 3 * 3 + 1 + dx[k] << " " << et << "\n";
			}
			//cout << "\n";
			for (int k = 1; k <= 9; k++)
				if (exist[k] == false)
					visited[i][j].push_back(k);
		}
	}
	//for (int i = 0; i < 9; i++)
	//{
	//	for (int j = 0; j < 9; j++)
	//	{
	//		if (arr[i][j] != 0)
	//			continue;
	//		cout << i << " " << j << ": ";
	//		for (auto e : visited[i][j])
	//		{
	//			cout << e << " ";
	//		}cout << "\n";
	//	}cout << "\n";
	//}

	stack<MyStruct> dq;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (arr[i][j] == 0)
				dq.push(MyStruct({ i,j }));

	dfs(arr, dq, visited);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}cout << "\n";

	return 0;
}



/*
http://theyearlyprophet.com/solving-every-sudoku-puzzle.html

0 0 0 0 0 5 0 8 0
0 0 0 6 0 1 0 4 3
0 0 0 0 0 0 0 0 0
0 1 0 5 0 0 0 0 0
0 0 0 1 0 6 0 0 0
3 0 0 0 0 0 0 0 5
5 3 0 0 0 0 0 6 1
0 0 0 0 0 0 0 0 4
0 0 0 0 0 0 0 0 0

. . . |. . 5 |. 8 .
. . . |6 . 1 |. 4 3
. . . |. . . |. . .
------+------+------
. 1 . |5 . . |. . .
. . . |1 . 6 |. . .
3 . . |. . . |. . 5
------+------+------
5 3 . |. . . |. 6 1
. . . |. . . |. . 4
. . . |. . . |. . .


8 5 0 0 0 2 4 0 0
7 2 0 0 0 0 0 0 9
0 0 4 0 0 0 0 0 0
0 0 0 1 0 7 0 0 2
3 0 5 0 0 0 9 0 0
0 4 0 0 0 0 0 0 0
0 0 0 0 8 0 0 7 0
0 1 7 0 0 0 0 0 0
0 0 0 0 3 6 0 4 0


8 5 . |. . 2 |4 . .
7 2 . |. . . |. . 9
. . 4 |. . . |. . .
------+------+------
. . . |1 . 7 |. . 2
3 . 5 |. . . |9 . .
. 4 . |. . . |. . .
------+------+------
. . . |. 8 . |. 7 .
. 1 7 |. . . |. . .
. . . |. 3 6 |. 4 .
*/
