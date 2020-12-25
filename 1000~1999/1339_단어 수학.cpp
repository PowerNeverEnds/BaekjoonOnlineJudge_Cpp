/**
 BOJ 1339
 - 단어 수학
 - 오전 1:49 2020-11-28
 */


#include <iostream>

using namespace std;

int main()
{
	return 0;
}


/*
https://www.acmicpc.net/source/24082326
*/
/*
#include <iostream>
#include <string>
int n, w[28], ans;
std::string s;
int main() {
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin.ignore();
		std::cin >> s;
		int l = s.length(), j = l - 1;
		while (j >= 0) {
			int ten = 1;
			for (int k = 1; k < l - j; k++)
				ten *= 10;
			w[s[j] - 'A'] += ten;
			j--;
		}
	}

	for (int i = 0; i < 28; i++)
		std::cout << w[i] << " ";
	std::cout << "\n";

	for (int i = 9; i >= 1; i--) {
		int mmax = 0, maxi = 0;
		for (int j = 0; j < 26; j++)
			if (w[j] > mmax)
				mmax = w[j], maxi = j;
		ans += mmax * i, w[maxi] = -1;
	}
	printf("%d", ans);
}
*/



/*
dfs 풀이 방법
*/
/*
#include <iostream>
#include <string>
#include <vector>

#define ALPHA_SIZE 26

using namespace std;

void init(int& N, int**& cnt)
{
	cin >> N;
	cnt = new int* [10];
	fill(cnt, cnt + 10, nullptr);
	for (int i = 0; i < 10; i++)
	{
		cnt[i] = new int[ALPHA_SIZE];
		fill(cnt[i], cnt[i] + ALPHA_SIZE, 0);
	}

	for (int i = 0; i < N; i++)
	{
		string str;
		cin.ignore();
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			cnt[i][str[str.length() - 1 - i] - 'A']++;
		}
	}
}

int dfs(int**& cnt, int depth, int md, vector<int>& vec, bool* bVis, int* visited)
{
	int max = 0;
	if (depth >= md)
	{
		int sum = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			int y = 1;
			for (int j = 0; j < 10; j++)
			{
				sum += cnt[j][vec[i]] * y * visited[i];
				y *= 10;
			}
		}
		return sum;
	}
	for (int i = 0; i < 10; i++)
	{
		//cout << depth << " " <<i<< "\n";
		if (bVis[i] != false)
		{
			continue;
		}
		bVis[i] = true;
		visited[depth] = i;
		int re = dfs(cnt, depth + 1, md, vec, bVis, visited);
		max = re > max ? re : max;
		bVis[i] = false;
	}
	return max;
}

int solve(int& N, int**& cnt)
{
	vector<int> vec;
	for (int j = 0; j < ALPHA_SIZE; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			if (cnt[i][j] > 0)
			{
				vec.push_back(j);
				break;
			}
		}
	}
	//for (auto e : vec)
	//	cout << e << "\n";
	bool* bVis = new bool[10];
	fill(bVis, bVis + 10, false);
	int* visited = new int[10];
	fill(visited, visited + 10, 0);

	int re = dfs(cnt, 0, vec.size(), vec, bVis, visited);

	return re;
}


void print(int& N, int**& cnt)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < ALPHA_SIZE; j++)
		{
			cout << cnt[i][j] << " ";
		}cout << "\n";
	}cout << "\n";
}

int main()
{
	int N;
	int** cnt;

	init(N, cnt);

	//print(N, cnt);

	int re = solve(N, cnt);

	cout << re << "\n";

	return 0;
}
*/