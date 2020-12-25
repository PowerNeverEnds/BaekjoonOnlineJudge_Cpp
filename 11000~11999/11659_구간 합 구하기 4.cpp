#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int init(vector<int>& vec, vector<int>& sTree, int node, int begin, int end)
{
	if (begin == end)
		return sTree[node] = vec[begin];
	int mid = (begin + end) / 2;
	return sTree[node] = init(vec, sTree, node * 2, begin, mid) + init(vec, sTree, node * 2 + 1, mid + 1, end);
}

int sum(vector<int>& sTree,int node, int begin, int end, int left, int right)
{
	if (left<=begin && end<=right)
		return sTree[node];
	if (end < left || right < begin)
		return 0;
	int mid = (begin+end) / 2;
	return sum(sTree, node * 2, begin, mid, left, right) + sum(sTree, node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N,M;
	cin >> N >> M;
	
	vector<int> sTree((ll)N*4);
	vector<int> vec;
	int e;
	vec.push_back(NULL);
	for (int i = 1; i <= N; i++)
	{
		cin >> e;
		vec.push_back(e);
	}

	init(vec, sTree, 1, 1, N);

	int i, j;
	while (M--)
	{
		cin >> i >> j;
		cout << sum(sTree,1, 1, N,i,j) << "\n";
	}

	//for (int i = 1; i < N*4; i++)
	//{
	//	cout << sTree[i] << " ";
	//}

	return 0;
}