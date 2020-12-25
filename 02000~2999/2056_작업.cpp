/**
 BOJ 2056
 - 작업
 - 오후 6:06 2020-11-28
 */

#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

//struct MyStruct
//{
//	int n;
//	int w;
//};

struct MyCompare
{
	bool operator()(const int& a, const int& b) {
		return a > b;
	}
};

void init(int& N, vector<int>*& graph, int*& weight, int*& indegree, int*& sum)
{
	cin >> N;
	graph = new vector<int>[(ll)N + 1];
	weight = new int[(ll)N + 1];
	fill(weight, weight + N + 1, 0);
	sum = new int[(ll)N + 1];
	fill(sum, sum + N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		int w;
		cin >> w;
		weight[i] = w;
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int e;
			cin >> e;
			graph[e].push_back(i);
		}
		sum[i] = w;
	}

	indegree = new int[(ll)N + 1];
	fill(indegree, indegree + N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		for (auto e : graph[i])
		{
			indegree[e]++;
		}
	}

}

void print(int& N, int*& indegree, int*& sum)
{
	for (int i = 1; i <= N; i++)
		cout << indegree[i] << " ";
	cout << "\n";
	for (int i = 1; i <= N; i++)
		cout << sum[i] << " ";
	cout << "\n";
}

int solve(int& N, vector<int>*& graph, int*& weight, int*& indegree, int*& sum)
{
	//priority_queue<int,vector<int>,MyCompare> pq;
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0)
			//pq.push(i);
			q.push(i);

	int st;
	for (int i = 1; i <= N; i++)
	{
		//if (pq.empty())
		if (q.empty())
			break;
		//st = pq.top();
		//cout << q.size() << "\n";
		st = q.front();
		//pq.pop();
		q.pop();
		//cout <<"st "<< st << "\n";
		for (auto e : graph[st])
		{
			//cout << e << "\n";
			if (sum[st] + weight[e] > sum[e])
				sum[e] = sum[st] + weight[e];
			indegree[e]--;
			if (indegree[e] == 0)
				//pq.push(i);
				q.push(e);
		}
		//print(N,indegree,sum);
	}

	int max = 0;
	for (int i = 1; i <= N; i++)
		max = sum[i] > max ? sum[i] : max;

	return max;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	vector<int>* graph;
	int* weight;
	int* indegree;
	int* sum;
	init(N, graph, weight, indegree, sum);

	int re = solve(N, graph, weight, indegree, sum);

	cout << re << "\n";

	return 0;
}