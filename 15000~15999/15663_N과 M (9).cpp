#include <iostream>
#include <algorithm>
#include <vector>

typedef	long long ll;

using namespace std;


struct MyStruct
{
	int n;
	int c;
};

void dfs(int depth, int ind, int* arr, int* visited, int N, int M, vector<MyStruct> cnt)
{
	if (depth > M)
	{
		for (int i = 1; i <= M; i++)
		{
			cout << cnt[visited[i]].n << " ";
		}cout << "\n";
		return;
	}
	for (int i = 1; i < cnt.size(); i++)
	{
		bool isSame = false;
		for (int j = 1; j < depth; j++)
		{
			if (i == visited[j] && cnt[i].c == 0)
			{
				isSame = true;
				break;
			}
		}
		//cout << "isSame " << isSame << "\n";
		if (isSame == true)
			continue;
		visited[depth] = i;
		cnt[i].c--;
		dfs(depth + 1, ind, arr, visited, N, M, cnt);
		cnt[i].c++;
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	int* arr = new int[(ll)N + 1];
	fill(arr, arr + N + 1, 0);
	int* visited = new int[(ll)N + 1];
	for (int i = 0; i <= N; i++)
		visited[i] = i;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];



	sort(arr, arr + N + 1, [](auto a, auto b) {
		return a < b;
		});

	vector<MyStruct> cnt;
	cnt.push_back(MyStruct({ 0,0 }));
	for (int i = 1; i <= N; i++)
	{
		if (cnt.empty())
		{
			cnt.push_back(MyStruct({ arr[i],1 }));
		}
		else
		{
			if (cnt.back().n == arr[i])
				cnt.back().c++;
			else
			{
				cnt.push_back(MyStruct({ arr[i],1 }));
			}
		}
	}

	//for (auto e : cnt)
	//{
	//	cout << e.n << " " << e.c << "\n";
	//}cout << "\n";

	dfs(1, 1, arr, visited, N, M, cnt);

	return 0;
}

/*
5 3
9 7 9 1 9

3 1
1 1 1

4 1
1 2 1 2

*/