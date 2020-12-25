#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

#define MAX ((int)1e9+7)

using namespace std;

struct MyStruct
{
	ll n;
	int c;
};

void push(queue<MyStruct>& q, vector<MyStruct>& visited, MyStruct st, bool bOper, ll oper)
{
	if (bOper == true)
	{
		visited.push_back(MyStruct({ oper,st.c + 1 }));
		q.push(MyStruct({ oper,st.c + 1 }));
	}
}

int bfs(MyStruct st, vector<MyStruct>& visited, int B)
{
	queue<MyStruct> q;
	visited.push_back(st);
	q.push(st);
	if (st.n == B)
		return true;
	while (true)
	{
		//cout << q.size() << " " << visited.size() << "\n";
		if (q.empty())
			break;
		st = q.front();
		q.pop();
		//cout << st.n << "\n";
		bool bOper[2] = { true,true };
		ll oper[2] = { st.n * 2,st.n * 10 + 1 };
		//for (int i = visited.size() - 1; i >= 0; i--)
		//{
		//	MyStruct e = visited[i];
		//	//if(e.n/10<st.n)
		//	if (bOper[0] == false && bOper[1] == false)
		//		break;
		//	for (int i = 0; i < 2; i++)
		//	{
		//		if (e.n == oper[i] || oper[i] > MAX)
		//		{
		//			bOper[i] = false;
		//		}
		//	}
		//}
		for (int i = 0; i < 2; i++)
		{
			if (oper[i] > MAX)
			{
				bOper[i] = false;
			}
		}
		for (int i = 0; i < 2; i++)
		{
			push(q, visited, st, bOper[i], oper[i]);
			if (oper[i] == B)
				return true;
		}
	}
	return false;
}

int main()
{
	int A, B;
	cin >> A >> B;

	vector<MyStruct> visited;

	if (bfs(MyStruct({ A,1 }), visited, B))
		cout << visited.back().c - 1 + 1 << "\n";
	else
		cout << -1 << "\n";

	//for (auto e : visited)
	//{
	//	cout << e.n << " " << e.c << "\n";
	//}
	//cout << visited.size() << "\n";

	return 0;
}