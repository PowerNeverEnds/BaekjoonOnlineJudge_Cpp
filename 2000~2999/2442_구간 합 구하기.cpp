#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

ll init(vector<ll>& vec, vector<ll>& sTree, int node, int begin, int end)
{
	if (begin == end)
		return sTree[node] = vec[begin];
	int mid = (begin + end) / 2;
	return sTree[node] = init(vec, sTree, node * 2, begin, mid) + init(vec, sTree, node * 2 + 1, mid + 1, end);
}

// left, right 구해야하는 범위
// begin, end 재귀 돌면서 변하는 범위
// node: begin~end범위에 포함되는 합의 인덱스
ll sum(int node, vector<ll>& sTree, int begin, int end, int left, int right)
{
	//cout << sTree[node] << " " << node <<" "<<begin<<" "<<end<<" "<<left<<right<< "\n";
	//cout << (end < right) << " " << (left < begin) << "\n";
	//cout << (left <= begin) << " " << (end <= right) << "\n";

	if (end < left || right < begin)
		return 0;
	if (left <= begin && end <= right)
	{
		//cout << "sum" << "\n";
		return sTree[node];
	}
	int mid = (begin + end) / 2;
	return sum(node * 2, sTree, begin, mid, left, right) + sum(node * 2 + 1, sTree, mid + 1, end, left, right);
}

// begin~end가 index범위 안이면(->즉, 'index를 포함한다.'는 의미)
// index를 포함하는 노드는 diff만큼 더하기
void update(int node, vector<ll>& sTree, int begin, int end, int index, ll diff)
{
	if (index < begin || end < index)
		return;
	sTree[node] += diff;
	if (begin == end)
		return;
	int mid = (begin + end) / 2;
	update(node * 2, sTree, begin, mid, index, diff);
	update(node * 2 + 1, sTree, mid + 1, end, index, diff);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//ll abc;
	//cin >> abc;
	//cout << (int)abc << "\n";
	int N, M, K;
	cin >> N >> M >> K;

	vector<ll> vec;
	vector<ll> sTree((ll)N * 4);

	vec.push_back(NULL);	// 0~n-1 아니고, 1~N까지로
	for (int i = 1; i <= N; i++)
	{
		ll e;
		cin >> e;
		vec.push_back(e);
	}

	init(vec, sTree, 1, 1, N);

	//for (int i = 0; i < N * 4; i++)
	//	cout << sTree[i] << " ";
	//cout << "\n";

	for (int i = 0; i < M + K; i++)
	{
		int a, b;
		ll c;
		cin >> a >> b >> c;
		switch (a)
		{
		case 1:
		{
			ll diff = c - vec[b];	// vec도 변경. 이후에 update시 vec에서 차이 계산하기때문
			vec[b] = c;
			update(1, sTree, 1, N, b, diff);
			break;
		}
		case 2:
		{
			cout << sum(1, sTree, 1, N, b, (int)c) << "\n";
			break;
		}
		default:
			break;
		}

		//for (int i = 0; i < N * 4; i++)
		//	cout << sTree[i] << " ";
		//cout << "\n";
	}

	return 0;
}