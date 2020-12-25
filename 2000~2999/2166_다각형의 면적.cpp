/**
 *    BOJ 2166
 *    - 다각형의 면적
 *    author:  phcdream
 *    created: 오후 7:11 2020-11-29
 */

#include <iostream>
#include <vector>
#include <iomanip>

typedef long long ll;

using namespace std;

struct MyStruct
{
	ll a;
	ll b;
};

void init(int& N, vector<MyStruct>& vec)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		ll x, y;
		cin >> x >> y;
		vec.push_back(MyStruct({ x,y }));
	}
}

//template <typename T>
//T myAbs(T a)
//{
//	return a > 0 ? a : -a;
//}

double myAbs(double a)
{
	return a >= 0 ? a : -a;	// a>0 으로 하면, 0일때 -0 이나옴,
}

double solve(int N, vector<MyStruct> vec)
{
	ll sum = 0;
	ll a = vec[0].a;
	ll b = vec[0].b;
	// a c e a
	// b d f b
	for (int i = 1; i < N - 1; i++)
	{
		ll c, d, e, f;
		c = vec[i].a; e = vec[(ll)i + 1].a;
		d = vec[i].b; f = vec[(ll)i + 1].b;
		c -= a; e -= a;		// c-=a; e-=b;
		d -= b; f -= b;		// d-=a; f-=b; ab위치 잘못됨.
		//ll p = a * d + c * f + e * b;
		//ll m = b * c + d * e + f * a;
		ll p = c * f;
		ll m = d * e;
		sum += p - m;
	}

	return myAbs(sum * 0.5);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	vector<MyStruct> vec;
	init(N, vec);

	long double re = solve(N, vec);
	//cout << re << "\n";
	cout << fixed << setprecision(1) << re << "\n";

	return 0;
}

/*
4
0 0
0 10
10 10
10 0

3
0 0
5 0
2 2

3
0 0
3 0
3 4

4
0 0
2 0
5 0
2 2


4
-100000 -100000
100000 -100000
100000 100000
-100000 100000

3
0 0
0 1
1 1

4
0 0
5 0
2 4
3 3

3
0 0
0 0
0 0

3
1 1
2 2
-1 -1

3
-1 -1
2 2
1 1

3
-3 3
2 2
7 1

4
0 0
10 0
0 10
10 10
*/