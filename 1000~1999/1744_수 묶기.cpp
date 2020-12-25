/**
 *    BOJ 1744
 *    - 수 묶기
 *    author:  phcdream
 *    created: 오전 12:24 2020-12-07
**/

#include <iostream>
#include <algorithm>
#include <deque>

typedef long long ll;

using namespace std;

void in(int& N, int*& arr)
{
	cin >> N;
	arr = new int[(ll)N];
	fill(arr, arr + N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
}

ll solve(int N, int*& arr)
{
	sort(arr, arr + N, [](auto a, auto b) {
		return a < b;
		});

	deque<int> dq;
	for (int i = 0; i < N; i++)
	{
		int e;
		e = arr[i];
		dq.push_back(e);
	}

	ll sum = 0;
	while (true)
	{
		if (dq.empty() || dq.front() >= 0)
			break;
		ll a, b;
		a = dq.front();
		dq.pop_front();
		if (dq.empty())
		{
			sum += a;		// a += sum; 기묘한 수식 변경
			break;
		}
		b = dq.front();
		dq.pop_front();
		// 음 음	if
		// 음 양	else-if
		// 음 0	if
		// 0 0
		// 0 양
		// 양 양
		if (a < 0 && b <= 0)	// 음 음,0
		{
			sum += a * b;
		}
		else 
		{
			if (a < 0 && b>0)		// 음 양
			{
				sum += a;
				dq.push_front(b);
			}
									// 0 0, 0양, 양양
			else
			{
				dq.push_front(b);
				dq.push_front(a);
			}
			break;
		}
	}


	while (true)
	{
		if (dq.empty() || dq.back()==0)
			break;
		ll a, b;
		a = dq.back();
		dq.pop_back();
		if (dq.empty())
		{
			sum += a;
			break;
		}
		b = dq.back();
		dq.pop_back();
		// 양 양	
		// 0 양	
		// 0 0	
		if (0 < b && 0 < a)	// 양 양
		{
			if (a == 1 || b == 1)
			{
				sum += a + b;
			}
			else
				sum += a * b;
		}
		else
		{
			sum += a + b;
			break;
		}
	}

	return sum;
}
int main()
{
	int N;
	int* arr;
	in(N, arr);

	ll re = solve(N, arr);
	cout << re << "\n";

	return 0;
}
/*
1
-5

2
1 1
*/