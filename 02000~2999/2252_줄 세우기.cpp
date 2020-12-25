#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

void Topological_Sorting(vector<int>* graph, int* degree, int* result, int N)
{
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (degree[i] == 0)
			q.push(i);

	int st = 0;
	for (int i = 1; i <= N; i++)
	{
		if (q.empty())
			break;
		st = q.front();
		q.pop();
		result[i] = st;
		for (auto e : graph[st])
		{
			degree[e]--;
			if (degree[e] == 0)
				q.push(e);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	
	vector<int>* graph = new vector<int>[(ll)N + 1];
	int* degree = new int[(ll)N + 1];
	fill(degree, degree + N + 1, 0);
	int* result = new int[(ll)N + 1];
	fill(result, result + N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
		degree[B]++;
	}
	
	Topological_Sorting(graph, degree, result, N);
	
	for (int i = 1; i <= N; i++)
		cout << result[i] << " ";
	cout << "\n";

	return 0;
}