#include <iostream>
#include <vector>
using namespace std;

int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

void dfs(const vector<int>& t, bool** const field, bool** visited)
{
	int y, x;
	y = t[0];
	x = t[1];
	visited[y][x] = true;
		//cout << y-1 << " " << x-1 << "\n";
	for (int i = 0; i < 4; i++)
	{
		if (field[y + dy[i]][x + dx[i]] == true && visited[y + dy[i]][x + dx[i]] == false)
		{
			dfs(vector<int>{y + dy[i], x + dx[i]}, field, visited);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		int M, N;
		cin >> M >> N;
		bool** field = new bool* [(long long)N + 2]();
		for (int i = 0; i < N+2; i++)
			field[i] = new bool[(long long)M + 2]();

		bool** visited = new bool* [(long long)N + 2]();
		for (int i = 0; i < N+2; i++)
			visited[i] = new bool[(long long)M + 2]();

		int K;
		cin >> K;
		vector<vector<int>> kVec;
		for (int i = 0; i < K; i++)
		{
			int x, y;
			cin >> x >> y;
			x++, y++;
			field[y][x] = true;
			vector<int> t{ y,x };
			kVec.push_back(t);
		}
		//for (int i = 0; i <= N; i++)
		//{
		//	for (int j = 0; j <= M; j++)
		//	{
		//		cout << field[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		int count = 0;
		for (int i = 0; i < K; i++)
		{
			vector<int> t = kVec[i];
			//cout <<"vec"<< t[0]-1 << " " << t[1]-1 << "\n";
			if (visited[t[0]][ t[1]] == false)
			{
				count++;
				dfs(t, field, visited);
			}
		}
		cout << count << "\n";

	}
	return 0;
}