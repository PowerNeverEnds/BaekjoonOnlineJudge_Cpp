#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

struct MyStruct
{
	int n;
	int c;
};

void dfs(vector<MyStruct>& cnt, int* visited, int depth, int ind, int M)
{
	if (depth > M)
	{
		for (int i = 1; i <= M; i++)
			cout << cnt[visited[i]].n << " ";
		cout << "\n";
		return;
	}
	for (int i = ind; i < cnt.size(); i++)
	{
		if (cnt[i].c != 0)
			;
		else
			continue;
		//cout << i << " " << depth << "\n";
		visited[depth] = i;
		//cnt[i].c--;
		dfs(cnt, visited, depth + 1, i, M);
		//cnt[i].c++;
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	int* arr = new int[(ll)N + 1];
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	sort(arr + 1, arr + N + 1, [](auto a, auto b) {
		return a < b;
		});
	vector<MyStruct> cnt;
	cnt.push_back(MyStruct({ 0,0 }));
	for (int i = 1; i <= N; i++)
	{
		if (cnt.back().n == arr[i])
			cnt.back().c++;
		else
			cnt.push_back(MyStruct({ arr[i],1 }));
	}
	//cout << cnt.size() << "\n";
	int* visited = new int[(ll)M + 1];
	fill(visited, visited + M + 1, 0);
	//for(int i=1;i<=M;i++)
	//	visited[i]=

	dfs(cnt, visited, 1, 1, M);


	return 0;
}