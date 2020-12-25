#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int exist(const vector<int>& vec, int n)
{
	int l, r;
	l = 0;
	r = vec.size();
	if (n < vec[0] || vec[vec.size()-1] < n)
		return 0;
	while (true)
	{
		if (l > r)
		{
			return 0;
		}
		int m = (l + r) / 2;
		if (vec[m] == n)
		{
			return 1;
		}
		else
		{
			if (vec[m] < n)
				l = m + 1;
			else
				r = m - 1;
		}
	}

}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> A;
	int e;
	for (int i = 0; i < N; i++)
	{
		cin >> e;
		A.push_back(e);
	}
	sort(A.begin(), A.end(), [](auto a, auto b) {
		return a < b;
		});

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> e;
		cout<<exist(A, e)<<"\n";
	}
	return 0;
}