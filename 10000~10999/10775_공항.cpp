/**
 *    BOJ 10775
 *    - 공항
 *    author:  phcdream
 *    created: 오전 4:36 2020-12-17
**/

#include <iostream>

typedef long long ll;

using namespace std;

void in(int& G, int& P, int*& arr)
{
	cin >> G;
	cin >> P;
	arr = new int[(ll)P];
	fill(arr, arr + P, 0);
	for (int i = 0; i < P; i++)
	{
		cin >> arr[i];
	}
}

//int solve1(int& G, int& P, int*& arr)
//{
//	int* visited = new int[(ll)G + 1];
//	fill(visited, visited + G + 1, 0);
//	int i = 0;
//	for (i = 0; i < P; i++)
//	{
//		//for (int i = 0; i < G + 1; i++)
//		//	cout << visited[i] << " ";
//		//cout << "\n";
//		int e = arr[i];
//		int* visE = &visited[e];
//		if (*visE == 0)
//		{
//			//cout << e << " " << *visE << "\n";
//			*visE = e;
//		}
//		else
//		{
//			int ind = e;
//			while (true)
//			{
//				if (visited[ind] == 0 || ind <= 0)
//					break;
//				ind = visited[ind];
//				ind--;
//			}
//			//cout << ind << " " << *visE << "\n";
//			visited[ind] = ind;
//			*visE = ind;
//			if (ind == 0)
//				break;
//		}
//	}
//
//	//for (int i = 0; i < G + 1; i++)
//	//	cout << visited[i] << " ";
//	//cout << "\n";
//
//	return i;
//}

/*
해당문제
https://www.acmicpc.net/source/24321481
분리집합
https://www.acmicpc.net/problem/1717
https://www.acmicpc.net/source/23755034
*/

struct DisJointSet
{
	int* root;
	void djsInit(int n)
	{
		root = new int[(ll)n + 1];
		fill(root, root + n + 1, 0);
		for (int i = 0; i <= n; i++)
		{
			root[i] = i;
		}
	}
	int djsFind(int a)
	{
		if (root[a] == a)
			return a;
		return root[a] = djsFind(root[a]);
	}

	void djsUnion(int a, int b)		// b를 a에 합치기
	{
		a = djsFind(a);
		b = djsFind(b);

		root[b] = a;
	}
};

int solve2(int& G, int& P, int*& arr)
{
	DisJointSet djs;
	djs.djsInit(G);

	int i = 0;
	for (i = 0; i < P; i++)
	{
		int e = arr[i];
		int dfE = djs.djsFind(e);
		if (dfE == 0)
			break;
		djs.djsUnion(dfE - 1, dfE);
	}

	return i;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int G;
	int P;
	int* arr;
	in(G, P, arr);

	//int re = solve1(G, P, arr);
	int re = solve2(G, P, arr);
	cout << re << "\n";

	return 0;
}

/*
4
6
2
2
3
3
4
4

4
6
2
2
3
1
4
4

4
6
3
3
2
1
4
4

1
2
1
1

2
2
2
2

2
3
2
2
2

*/