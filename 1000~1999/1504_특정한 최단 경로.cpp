/**
 *    BOJ 1504
 *    - 특정한 최단 경로
 *    author:  phcdream
 *    created: 오후 11:11 2020-12-03
**/

//#include <iostream>
//#include <vector>
//#include <queue>
//
//typedef long long ll;
//
//#define INF ((int)1e6+7)
//
//using namespace std;
//
//struct MyStruct
//{
//	int n;
//	int c;
//	bool operator<(const MyStruct& ms)const {
//		return c < ms.c;
//	}
//};
//
//int myMin(int a, int b)
//{
//	return a <= b ? a : b;
//}
//
//void in(int& N, int& E, vector<MyStruct>*& graph, int& v1, int& v2)
//{
//	cin >> N >> E;
//	graph = new vector<MyStruct>[(ll)N + 1];
//	for (int i = 0; i < E; i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		graph[a].push_back(MyStruct({ b,c }));
//		graph[b].push_back(MyStruct({ a,c }));
//	}
//	cin >> v1 >> v2;
//}
//
//int* dijkstra(int N, vector<MyStruct>* graph, int v)
//{
//	priority_queue<MyStruct> pq;
//	int* d = new int[(ll)N + 1];
//	fill(d, d + N + 1, INF);
//	d[v] = 0;
//	pq.push(MyStruct({ v,0 }));
//
//	MyStruct st;
//	while (true)
//	{
//		if (pq.empty())
//			break;
//		st = pq.top();
//		pq.pop();
//		if (st.c > d[st.n])	// 우선순위큐 값보다 구해놓은 거리값이 더작을경우, continue
//			continue;
//		for (auto e : graph[st.n])
//		{
//			if (d[st.n] + e.c < d[e.n])
//			{
//				d[e.n] = d[st.n] + e.c;
//				pq.push(MyStruct({ e.n,d[e.n] }));
//			}
//		}
//	}
//
//	return d;
//}
//
//int solve(int N, int E, vector<MyStruct>* graph, int v1, int v2)
//{
//	int minS = INF;
//	int minE = INF;
//	int vv;
//	int* re = dijkstra(N, graph, v1);	// 정점v1 다익스트라
//	minS = re[1];
//	minE = re[N];
//	vv = re[v2];
//	re = dijkstra(N, graph, v2);	// 정점v2 다익스트라
//
//	// S,v1,v2,E 4가지 경우의 수
//	int sum;
//	int a, b, c, d;
//	a = minS + vv + vv + minE;		//	S-v1-v2-v1-E
//	b = minS + vv + re[N];			//	S-v1-v2-E
//	c = re[1] + vv + minE;			//	S-v2-v1-E
//	d = re[1] + vv + vv + re[N];	//	S-v2-v1-v2-E
//
//	sum = myMin(myMin(a, b), myMin(c, d));
//
//	if (sum >= INF)
//		return -1;
//	else
//		return sum;
//}
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	int N, E;
//	vector<MyStruct>* graph;
//	int v1, v2;
//	in(N, E, graph, v1, v2);
//
//	int re = solve(N, E, graph, v1, v2);
//	cout << re << "\n";
//
//	return 0;
//}
/*

4 6
1 2 3
2 3 3
3 4 1
1 3 5
2 4 5
1 4 4
2 3

2 0
1 2

4 3
1 2 1
2 3 2
3 4 3
2 3

4 5
1 2 1
2 4 2
1 3 3
3 4 3
2 3 2
2 3



*/

/*
함수 호출 안해도 시간똑같음
위 코드랑 똑같이 다른 다익3번코드 보다느림.
*/
/*
#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

#define INF ((int)1e6+7)

using namespace std;

struct MyStruct
{
	int n;
	int c;
	bool operator<(const MyStruct& ms)const {
		return c < ms.c;
	}
};

int myMin(int a, int b)
{
	return a <= b ? a : b;
}

//void in(int& N, int& E, vector<MyStruct>*& graph, int& v1, int& v2)
//{
//
//}
//
//int* dijkstra(int N, vector<MyStruct>* graph, int v)
//{
//
//
//	return d;
//}
//
//int solve(int N, int E, vector<MyStruct>* graph, int v1, int v2)
//{
//
//}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, E;
	vector<MyStruct>* graph;
	int v1, v2;
	//	in(N, E, graph, v1, v2);
	cin >> N >> E;
	graph = new vector<MyStruct>[(ll)N + 1];
	int a, b, c;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back(MyStruct({ b,c }));
		graph[b].push_back(MyStruct({ a,c }));
	}
	cin >> v1 >> v2;
	int sum;
	//int re = solve(N, E, graph, v1, v2);
	{
		//int* visited = new int[(ll)N + 1];
		//fill(visited, visited + N + 1, 0);
		int minS = INF;
		int minE = INF;
		int vv;
		//int* re = dijkstra(N, graph, v1);
		int* d = new int[(ll)N + 1];
		fill(d, d + N + 1, INF);
		priority_queue<MyStruct> pq;
		MyStruct st;
		{
			int v = v1;
			d[v] = 0;
			pq.push(MyStruct({ v,0 }));

			while (true)
			{
				if (pq.empty())
					break;
				st = pq.top();
				pq.pop();
				if (st.c > d[st.n])
					continue;
				for (auto e : graph[st.n])
				{
					if (d[st.n] + e.c < d[e.n])
					{
						d[e.n] = d[st.n] + e.c;
						pq.push(MyStruct({ e.n,d[e.n] }));
					}
				}
			}
		}

		minS = d[1];
		minE = d[N];
		vv = d[v2];
		//re = dijkstra(N, graph, v2);
		//int* d = new int[(ll)N + 1];
		fill(d, d + N + 1, INF);
		{
			int v = v2;
			//priority_queue<MyStruct> pq;
			d[v] = 0;
			pq.push(MyStruct({ v,0 }));

			//MyStruct st;
			while (true)
			{
				if (pq.empty())
					break;
				st = pq.top();
				pq.pop();
				if (st.c > d[st.n])
					continue;
				for (auto e : graph[st.n])
				{
					if (d[st.n] + e.c < d[e.n])
					{
						d[e.n] = d[st.n] + e.c;
						pq.push(MyStruct({ e.n,d[e.n] }));
					}
				}
			}
		}
		// S,v1,v2,E 4가지 경우의 수
		//cout << minS << " " << vv << " " << minE << " " << d[1] << " " << d[N] << "\n";
		int a, b, c, dd;
		a = minS + vv + vv + minE;		//	S-v1-v2-v1-E
		b = minS + vv + d[N];			//	S-v1-v2-E
		c = d[1] + vv + minE;			//	S-v2-v1-E
		dd = d[1] + vv + vv + d[N];	//	S-v2-v1-v2-E
		//cout << a << " " << b << " " << c << " " << dd << "\n";
		sum = myMin(myMin(a, b), myMin(c, dd));
	}

	if (sum >= INF)
		cout << "-1" << "\n";
	else
		cout << sum << "\n";

	return 0;
}
*/

/*
동적할당 뺀 버전+ pair씀
*/
/*
#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

#define INF ((int)1e6+7)

using namespace std;



//struct MyStruct
//{
//	int n;
//	int c;
//	bool operator<(const MyStruct& ms)const {
//		return c < ms.c;
//	}
//};

vector<pair<int,int>> graph[800 + 1];
int N, E;
int v1, v2;

int myMin(int a, int b)
{
	return a <= b ? a : b;
}

//void in()//(int& N, int& E, vector<MyStruct> graph[], int& v1, int& v2)
//{
//
//}

int d[801];
int* dijkstra(int v)//int N, vector<MyStruct> graph[], int v)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	//int* d = new int[(ll)N + 1];
	fill(d, d + N + 1, INF);
	d[v] = 0;
	pq.push({ v,0 });

	pair<int,int> st;
	while (true)
	{
		if (pq.empty())
			break;
		st = pq.top();	// first: n, second: c
		pq.pop();
		if (st.second > d[st.first])	// 우선순위큐 값보다 구해놓은 거리값이 더작을경우, continue
			continue;
		for (auto e : graph[st.first])
		{
			if (d[st.first] + e.second < d[e.first])
			{
				d[e.first] = d[st.first] + e.second;
				pq.push({ e.first,d[e.first] });
			}
		}
	}

	return d;
}

//int solve()//int N, int E, vector<MyStruct> graph[], int v1, int v2)
//{
//
//
//	if (sum >= INF)
//		return -1;
//	else
//		return sum;
//}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//in();//N, E, graph, v1, v2);
	cin >> N >> E;
	//graph = new vector<MyStruct>[(ll)N + 1];
	{
		int a, b, c;
		for (int i = 0; i < E; i++)
		{
			cin >> a >> b >> c;
			graph[a].push_back({ b,c });
			graph[b].push_back({ a,c });
		}
		cin >> v1 >> v2;
	}
	//int re = solve();// N, E, graph, v1, v2);
	{
		int minS = INF;
		int minE = INF;
		int vv;
		int* re = dijkstra(v1);//N, graph, v1);	// 정점v1 다익스트라
		minS = re[1];
		minE = re[N];
		vv = re[v2];
		re = dijkstra(v2);// N, graph, v2);	// 정점v2 다익스트라

		// S,v1,v2,E 4가지 경우의 수
		int sum;
		int a, b, c, d;
		a = minS + vv + vv + minE;		//	S-v1-v2-v1-E
		b = minS + vv + re[N];			//	S-v1-v2-E
		c = re[1] + vv + minE;			//	S-v2-v1-E
		d = re[1] + vv + vv + re[N];	//	S-v2-v1-v2-E

		sum = myMin(myMin(a, b), myMin(c, d));
		if (sum >= INF)
			cout << "-1" << "\n";
		else
			cout << sum << "\n";
	}
	//cout << re << "\n";

	return 0;
}
*/

/*
그냥 큐 한번더
우선순위큐 comp -> 기본 비교함수 lesser
MyStruct operator<: return < 에서 > 로 바꿈

*/
#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

#define INF ((int)1e6+7)

using namespace std;

struct MyStruct
{
	int n;
	int c;
	//bool operator<(const MyStruct& ms)const {	// less
	//	return c > ms.c;	// 부호바꿈
	//}
	//bool operator>(const MyStruct& ms)const {	// greater
	//	return c > ms.c;
	//}
};

//struct comp
//{
//	//bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
//	//	return a.second < b.second;
//	//}
//	bool operator()(const MyStruct& a, const MyStruct& b) const {
//		return a.c < b.c;
//	}
//
//};

int myMin(int a, int b)
{
	return a <= b ? a : b;
}

void in(int& N, int& E, vector<MyStruct>*& graph, int& v1, int& v2)
{
	cin >> N >> E;
	graph = new vector<MyStruct>[(ll)N + 1];
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(MyStruct({ b,c }));
		graph[b].push_back(MyStruct({ a,c }));
	}
	cin >> v1 >> v2;
}

int* dijkstra(int N, vector<MyStruct>* graph, int v)
{
	//priority_queue<MyStruct, vector<MyStruct>, greater<MyStruct>> pq;
	//priority_queue<MyStruct,vector<MyStruct>,less<MyStruct>> pq;
	queue<MyStruct> pq;
	//priority_queue<MyStruct, vector<MyStruct>, comp> pq;
	//priority_queue<MyStruct> pq;
	int* d = new int[(ll)N + 1];
	fill(d, d + N + 1, INF);
	d[v] = 0;
	pq.push(MyStruct({ v,0 }));

	MyStruct st;
	while (true)
	{
		if (pq.empty())
			break;
		//st = pq.top();
		st = pq.front();
		int stc = st.c;// st.second;
		int stn = st.n;// st.first;
		pq.pop();
		if (stc > d[stn])	// 우선순위큐 값보다 구해놓은 거리값이 더작을경우, continue
			continue;
		for (auto e : graph[stn])
		{
			int ec = e.c;// e.second;
			int en = e.n;//e.first;
			if (d[stn] + ec < d[en])
			{
				d[en] = d[stn] + ec;
				pq.push(MyStruct({ en,d[en] }));
			}
		}
	}

	return d;
}

int solve(int N, int E, vector<MyStruct>* graph, int v1, int v2)
{
	int minS = INF;
	int minE = INF;
	int vv;
	int* re = dijkstra(N, graph, v1);	// 정점v1 다익스트라
	minS = re[1];
	minE = re[N];
	vv = re[v2];
	re = dijkstra(N, graph, v2);	// 정점v2 다익스트라

	// S,v1,v2,E 4가지 경우의 수
	int sum;
	int a, b, c, d;
	a = minS + vv + vv + minE;		//	S-v1-v2-v1-E
	b = minS + vv + re[N];			//	S-v1-v2-E
	c = re[1] + vv + minE;			//	S-v2-v1-E
	d = re[1] + vv + vv + re[N];	//	S-v2-v1-v2-E

	sum = myMin(myMin(a, b), myMin(c, d));

	if (sum >= INF)
		return -1;
	else
		return sum;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, E;
	vector<MyStruct>* graph;
	int v1, v2;
	in(N, E, graph, v1, v2);

	int re = solve(N, E, graph, v1, v2);
	cout << re << "\n";

	return 0;
}