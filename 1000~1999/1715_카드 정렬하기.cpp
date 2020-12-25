/**
 *    BOJ 1715
 *    - 카드 정렬하기
 *    author:  phcdream
 *    created: 오전 9:20 2020-12-07
**/

#include <iostream>
#include <queue>

using namespace std;

struct comp
{
	bool operator()(const int& a, const int& b) const{	// '<' less -> max-heap		'>': min-heap
		return a > b;
	}
};

int main()
{
	int N;
	cin >> N;
	priority_queue<int, vector<int>, comp> pq;
	for (int i = 0; i < N; i++)
	{
		int e;
		cin >> e;
		pq.push(e);
	}
	if (N == 1)
	{
		cout << 0 << "\n";
		return 0;
	}
	int sum = 0;
	while (true)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		sum += a + b;
		if (pq.empty())
			break;
		pq.push(a + b);
	}

	cout << sum << "\n";

	return 0;
}