/**
 *    BOJ 1202
 *    - 보석 도둑
 *    author:  phcdream
 *    created: 오전 3:36 2020-12-04
**/

#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

struct MyStruct
{
	int m;		//	무게
	int v;		//	가격
	//bool operator>(const MyStruct& ms) const {
	//	return v > ms.v;
	//}
	//bool operator<(const MyStruct& ms) const {
	//	return m < ms.m;
	//}
};

void in(int& N, int& K, MyStruct*& arr, MyStruct*& cArr)
{
	cin >> N >> K;
	arr = new MyStruct[(ll)N];
	for (int i = 0; i < N; i++)
	{
		int M, V;
		cin >> M >> V;
		arr[i] = MyStruct({ M,V });			//	보석점의 보석
	}
	cArr = new MyStruct[(ll)K];
	for (int i = 0; i < K; i++)
	{
		int C;
		cin >> C;
		cArr[i] = MyStruct({ C,-1 });		//	가방
	}
}

int binSearch(int begin, int end, int n, MyStruct* cArr)
{
	int l = begin;
	int r = end - 1 + 1;
	int mid = (l + r) / 2;
	//cout <<"bS "<< n << "\n";
	while (true)
	{
		//cout << l << " " << r << "\n";
		mid = (l + r) / 2;
		if (l >= r)
		{
			break;
		}
		if (cArr[mid].m < n)
			l = mid + 1;
		if (n <= cArr[mid].m)
			r = mid;
	}
	return mid;
}

ll solve(int& N, int& K, MyStruct*& arr, MyStruct*& cArr)
{
	sort(arr, arr + N, [](auto a, auto b) {
		return a.v > b.v;
		});
	sort(cArr, cArr + K, [](auto a, auto b) {
		return a.m < b.m;
		});
	ll sum = 0;
	for (int i = 0; i < N; i++)
	{
		int re = binSearch(0, K, arr[i].m, cArr);
		//cout <<"re "<< re << "\n";
		int k = re;
		while (true)
		{
			if (k >= K)
				break;
			if (cArr[k].v == -1)
				break;
			else if (cArr[k].v != k)
			{
				k = cArr[k].v;			// cArr[k].v 번째로 건너뛰기
				continue;
			}
			k++;
		}
		if (k >= K)
		{
		}
		else
		{
			//cout << k << "\n";
			//cArr[k].v = arr[i].v;
			cArr[k].v = k;
			cArr[re].v = k;		// k번째로 건너뛰기 
			sum += arr[i].v;

			//while (true)		//	erase
			//{
			//	if (k + 1 >= K)
			//		break;
			//	cArr[k] = cArr[k + 1];
			//	k++;
			//}
			//K--;
		}
	}

	return sum;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	MyStruct* arr;		//	보석점의 보석
	MyStruct* cArr;		//	가방
	in(N, K, arr, cArr);

	ll re = solve(N, K, arr, cArr);
	cout << re << "\n";

	return 0;
}

/*
3 2
1 65
5 23
2 99
10
2

3 3
1 65
5 23
2 99
10
2
1

4 3
1 65
5 23
2 99
11 50
10
2
1

5 3
1 65
5 23
2 99
11 50
1 50
10
2
1

8 6
0 9
1 8
2 7
3 6
4 5
5 4
6 3
7 2
8 1
1
2
4
5
5
6

8 6
1 8
2 7
3 6
4 5
5 4
6 3
7 2
8 1
1
2
4
5
5
6


*/