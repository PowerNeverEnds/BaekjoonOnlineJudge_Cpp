/**
 *    BOJ 14226
 *    - 이모티콘
 *    author:  phcdream
 *    created: 오전 5:22 2020-12-06
**/

#include <iostream>
#include <queue>
#include <set>

typedef long long ll;

using namespace std;

struct MyStruct
{
	int e;
	int c;
	int v;
	bool operator<(const MyStruct& ms) const {
		if (e == ms.e)
		{
			if (c == ms.c)
				return v < ms.v;
			return c < ms.c;
		}
		return e < ms.e;
	}

};

int bfs(int s, int**& visited, int S)
{
	//set<MyStruct> se;
	queue<MyStruct> q;
	MyStruct st = MyStruct({ 1,0,1 });
	q.push(st);
	visited[st.e][st.c] = 1;
	//se.insert(st);
	while (true)
	{
		st = q.front();
		q.pop();
		//cout << "\n";
		//cout << st.e << " " << st.c << " " << st.v << "\n";
		bool bOper[3] = { 1,st.c + st.e <= S,1 <= st.e-1 };
		for (int i = 0; i < 3; i++)
		{
			MyStruct nMS = st;
			if (bOper[i] == true)
			{
				switch (i)
				{
				case 0:
					nMS.c = st.e;
					break;
				case 1:
					nMS.e += st.c;
					break;
				case 2:
					nMS.e -= 1;
					break;
				default:
					break;
				}
				nMS.v++;
			}
			else
				continue;
			//cout << nMS.e << " " << nMS.c << " " << nMS.v << "\n";
			//if (se.count(nMS) == 0)
			if(visited[st.e][st.c]+1<visited[nMS.e][nMS.c] || visited[nMS.e][nMS.c]==0)
			{
				visited[nMS.e][nMS.c] = visited[st.e][st.c] + 1;
				q.push(nMS);
				//se.insert(nMS);
			}
			//else
			//{
			//	//cout << "no push" << "\n";
			//	continue;
			//}
			if (nMS.e == S)
				return nMS.v;
		}
	}
}

int solve(int S)
{
	int** visited = new int*[(ll)S + 1];
	fill(visited, visited + S + 1, nullptr);
	for (int i = 0; i < S + 1; i++)
	{
		visited[i] = new int[(ll)S + 1];
		fill(visited[i], visited[i] + S + 1, 0);
	}
	int re = bfs(1, visited, S);
	return re-1;
}

int main()
{
	int S;
	cin >> S;
	int re = solve(S);
	cout << re << "\n";

	return 0;
}