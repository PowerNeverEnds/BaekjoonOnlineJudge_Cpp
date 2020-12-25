/**
 *    BOJ 1946
 *    - ���� ���
 *    author:  phcdream
 *    created: ���� 2:41 2020-12-02
 */

#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;


struct MyStruct
{
	int a;
	int b;
	//MyStruct& operator=(const MyStruct& ms) {
	//	a = ms.a;
	//	b = ms.b;
	//	return *this;
	//}
};

void in(int& N, MyStruct*& arr)
{
	cin >> N;
	arr = new MyStruct[(ll)N+1];
	for (int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[i].a = a;
		arr[i].b = b;
	}
}

void print(int N, MyStruct* arr)
{
	for (int i = 1; i <= N; i++)
	{
		cout << arr[i].a << " " << arr[i].b << "\n";
	}cout << "\n";
}

//int solve(int N, MyStruct* arr)
//{
//	MyStruct* aArr=new MyStruct[(ll)N+1];	// a�� �������� ����, ���� aArr[i].a==i
//	MyStruct* bArr=new MyStruct[(ll)N+1];
//	copy(arr, arr + N+1, aArr);
//	copy(arr, arr + N+1, bArr);
//	sort(aArr, aArr + N+1, [](auto a, auto b) {
//		return a.a < b.a;
//		});
//	sort(bArr, bArr + N+1, [](auto a, auto b) {
//		return a.b < b.b;
//		});
//
//	//print(N, arr);
//	//print(N,aArr);
//	//print(N, bArr);
//
//	int aMin = N + 7;
//	int bMin = N + 7;
//	int cnt = 0;
//
//	// ������ �Ͽ���, ����� 1����� N����� �ߺ����� �����Ƿ�,
//	// ��� aArr[i].a �� bArr[i].b�� i�� ����.
//	// aArr�� �����ϸ�,
//	// (prev<i �϶�) aArr[prev].a < aArr[i].a �̹Ƿ�(=a�� ����� ������ ����),
//	// aArr[prev].b �� aArr[i].b�� ���ϸ��(=b�� ����� ��).
//	// ����, aArr[i].b �� min(aArr[i-1].b, aArr[i-2].b,...aArr[2].b,aArr[1].b) ��
//	// min>aArr[i].b min���� �������(����� �������)
//	// min�� �缳���ϰ�,cnt�� ����.
//	// bArr�� �Ȱ��� ����ϸ� �ȴ�.
//	for (int i = 1; i <= N; i++)
//	{
//		bool compA = bArr[i].a < aMin;
//		bool compB = aArr[i].b < bMin;
//		if (compA || compB)
//		{
//			if (compA)
//			{
//				aMin = bArr[i].a;
//				cnt++;
//			}
//			if (compB)
//			{
//				bMin = aArr[i].b;
//				cnt++;
//			}
//		}
//		else
//		{
//		}
//	}
//	//cout << cnt << "\n";
//
//	return cnt/2;
//}


// ������ �����Ͽ� �ٸ��ʸ� ���ص� ��.
int solve(int N, MyStruct* arr)
{
	MyStruct* aArr=new MyStruct[(ll)N+1];	// a�� �������� ����, ���� aArr[i].a==i
	copy(arr, arr + N+1, aArr);
	sort(aArr, aArr + N + 1, [](auto a, auto b) {
		return a.a < b.a;
		});
	int bMin = N + 7;
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		bool compB = aArr[i].b < bMin;
		if (compB)
		{
			if (compB)
			{
				bMin = aArr[i].b;
				cnt++;
			}
		}
		else
		{
		}
	}
	//cout << cnt << "\n";

	//return cnt / 2;
	return cnt;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		MyStruct* arr;
		in(N, arr);

		int re = solve(N, arr);
		cout << re << "\n";
	}

	return 0;
}

/*
2
5
3 2
1 4
4 1
2 3
5 5
7
3 6
7 3
4 2
1 4
5 7
2 5
6 1

1
6
4 2
1 5
5 1
2 4
3 3
6 6

1
6
1 3
2 5
3 2
4 6
5 1
6 4
3

1
6
1 3
2 5 x
3 2
4 6 x
5 1
6 4 x
3

1
3
1 1
2 2
3 3
1

1
3
1 3
2 2
3 1
3

1
4
1 2
2 3
3 4
4 1
2

1
5
1 3
2 5
3 2
4 4
5 1
3

1
5
1 3
2 5
3 2
4 4
5 1
3

1
6
1 5
2 4
3 6
4 2
5 1
6 3
4

1
6
1 5
2 4
3 3
4 2
5 1
6 6
5

*/