/**
 *    BOJ 1647
 *    - 도시 분할 계획
 *    author:  phcdream
 *    created: 오전 12:47 2020-12-19
**/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

typedef long long ll;

#define INF ((int)1e9+7)

#define ALL true
#define dfor if(true && ALL) for
#define dout if(true && ALL) cout

using namespace std;

struct MyStruct
{
	int n;
	int w;
	bool operator<(const MyStruct& ms) const {		// less -> max_heap
		return w > ms.w;							// 부호반대 min_heap
	}
	int m;
};


void in(int& N, int& M, vector<MyStruct>*& graph, vector<MyStruct>& meVec)
{
	cin >> N >> M;
	//graph = new vector<MyStruct>[(ll)N + 1];
	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		//graph[A].push_back({ B,C });
		//graph[B].push_back({ A,C });
		meVec.push_back({ A,C,B });
	}
}

//int solve1(int& N, int& M, vector<MyStruct>*& graph)
//{
//	int* visited = new int[(ll)N + 1];
//	fill(visited, visited + N + 1, INF);
//	int sum = 0;
//	int max = 0;
//	priority_queue<MyStruct> pq;
//	MyStruct st{ 1,0 };
//	//sum += 0;
//	//visited[st.n] = 0;
//	pq.push(st);
//	while (true)
//	{
//		if (pq.empty())
//			break;
//		st = pq.top();
//		pq.pop();
//		if (visited[st.n] != INF)
//			continue;
//		visited[st.n] = st.w;
//		sum += st.w;
//		max = st.w > max ? st.w : max;
//		for (auto e : graph[st.n])
//		{
//			if (visited[e.n] == INF)
//			{
//				pq.push(e);
//			}
//		}
//	}
//
//	return sum - max;
//}
/*
https://www.acmicpc.net/source/24420090
*/
struct Djs
{
	int* root;
	
	void dInit(int& N)
	{
		root = new int[(ll)N + 1];
		for (int i = 0; i <= N; i++)
			root[i] = i;
	}

	int dFind(int a)
	{
		if (a == root[a])
			return a;
		return root[a] = dFind(root[a]);
	}

	void dUnion(int a, int b)
	{
		a = dFind(a);
		b = dFind(b);
		root[b] = a;		// b를 a에 합치기
	}

};

int solve2(int& N, int& M, vector<MyStruct>& meVec)
{
	Djs djs;
	djs.dInit(N);

	sort(meVec.begin(), meVec.end(), [](auto a, auto b) {
		return a.w < b.w; 
		});

	int max = 0;
	int sum = 0;
	for (auto e : meVec)
	{
		if (djs.dFind(e.n) == djs.dFind(e.m))
		{
		}
		else
		{
			djs.dUnion(e.n, e.m);
			sum += e.w;
			max = e.w > max ? e.w : max;
		}
	}

	return sum - max;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	vector<MyStruct>* graph;
	vector<MyStruct> meVec;
	in(N, M, graph, meVec);

	//int re = solve1(N, M, graph);
	int re = solve2(N, M, meVec);
	cout << re << "\n";

	return 0;
}