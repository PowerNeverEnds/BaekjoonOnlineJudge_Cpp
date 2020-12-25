/*
2020-11-07 ¿ÀÈÄ11:41
*/
#include <iostream>
#include <algorithm>
#include <string>

typedef long long ll;

using namespace std;

int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

struct MyStruct
{
	int y;
	int x;
};

int dfs(MyStruct st, char** arr, bool* visited, int cnt)
{
	int max = 0;
	visited[arr[st.y][st.x] - 'A'] = true;
	//cout << st.y << " " << st.x << "\n";
	for (int i = 0; i < 4; i++)
	{
		int nY = st.y + dy[i];
		int nX = st.x + dx[i];
		if (arr[nY][nX] != NULL)
		{
			if (visited[arr[nY][nX] - 'A'] == false)
			{
				visited[arr[nY][nX] - 'A'] = true;
				int t;
				t = dfs(MyStruct({ nY,nX }), arr, visited, cnt + 1);
				visited[arr[nY][nX] - 'A'] = false;
				max = t > max ? t : max;
			}
		}
	}
	max = cnt > max ? cnt : max;

	return max;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int R, C;
	cin >> R >> C;
	char** arr = new char* [(ll)R + 2];
	fill(arr, arr + R + 2, nullptr);
	for (int i = 0; i < R + 2; i++)
	{
		arr[i] = new char[(ll)C + 2];
		fill(arr[i], arr[i] + C + 2, NULL);
	}

	for (int i = 1; i <= R; i++)
	{
		string str;
		cin.ignore();
		cin >> str;
		for (int j = 1; j <= C; j++)
			arr[i][j] = str[(ll)j - 1];
	}

	//for (int i = 1; i <= R; i++)
	//{
	//	for (int j = 1; j <= C; j++)
	//	{
	//		cout << arr[i][j] << " ";
	//	}cout << "\n";
	//}cout << "\n";

	bool visited[26] = { 0, };
	fill(visited, visited + 26, false);

	visited[arr[1][1] - 'A'] = true;
	cout << dfs(MyStruct({ 1,1 }), arr, visited, 1) << "\n";

	return 0;
}


/*

3 4
CABD
AACB
DAAA

1 1
C

3 20
QWERTYUIOPASDFGHJKLQ
ASDFGHJKLQZXCVBNMQQQ
ZXCVBNMQQQQWERTYUIOP

*/