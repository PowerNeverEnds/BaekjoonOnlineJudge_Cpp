/**
 *    BOJ 2568
 *    - 전깃줄 - 2
 *    author:  phcdream
 *    created: 오후 10:54 2020-12-01
 */

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

struct MyStruct
{
	int ind;	//	A
	int n;		//	B
	bool operator<(const MyStruct& ms) const {
		return ind < ms.ind;
	}
};

void in(int& n, vector<MyStruct>& vec)
{
	cin >> n;
	vec.push_back(MyStruct{ 0,0 });
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		vec.push_back(MyStruct({ a,b }));
	}
}

vector<int> solve(int n, vector<MyStruct>& vec)
{
	sort(vec.begin(), vec.end(), [](auto a, auto b) {
		return a < b;
		});

	int* dp = new int[(ll)n + 1];
	fill(dp, dp + n + 1, 0);
	vector<MyStruct> reDp;	// ind는 필요없는거 vector<int>로 해도됨.
	reDp.push_back(MyStruct({ 0,0 }));
	for (int i = 1; i <= n; i++)
	{
		int l = 1;
		int r = reDp.size() - 1;
		int m = (l + r) / 2;
		//cout << i <<" "<<vec[i].n<< "\n";
		while (true)
		{
			if (l > r)
			{
				m = l;
				break;
			}
			m = (l + r) / 2;
			if (reDp[m].n == vec[i].n)
				break;
			else if (reDp[m].n < vec[i].n)
			{
				l = m + 1;
			}
			else if (vec[i].n < reDp[m].n)
			{
				r = m - 1;
			}
		}
		if (m == reDp.size())
		{
			//cout << "push " << "\n";
			reDp.push_back(MyStruct({ vec[i].ind,vec[i].n }));
			dp[i] = m;
		}
		else
		{
			if (vec[i].n < reDp[m].n)
			{
				//cout << "chage " << m << " " << reDp[m].n << "to" << vec[i].n << "\n";
				reDp[m].ind = vec[i].ind;
				reDp[m].n = vec[i].n;
			}
			dp[i] = m;
		}
	}

	vector<int> lisVec;
	int k = reDp.size() - 1;
	for (int i = vec.size() - 1; i >= 0; i--)
	{
		if (k == 0)
			break;
		if (dp[i] == k)
		{
			lisVec.push_back(vec[i].ind);
			k--;
		}
	}
	//for (int i = 0; i <= n; i++)
	//	cout << dp[i] << " ";
	//cout << "\n";
	reverse(lisVec.begin(), lisVec.end());
	vector<int> reVec;
	int p = 0;
	for (int i = 1; i < vec.size(); i++)
	{
		MyStruct e = vec[i];
		if (e.ind == lisVec[p])
		{
			p++;
		}
		else
		{
			reVec.push_back(e.ind);
		}
	}

	return reVec;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	vector<MyStruct> vec;
	in(n, vec);

	vector<int> re = solve(n, vec);
	cout << re.size() << "\n";
	for (auto e : re)
		cout << e << "\n";

	return 0;
}

/*
8
1 8
3 9
2 2
4 1
6 4
10 10
9 7
7 6


7
1 8
2 2
3 7
4 9
5 1
6 4
7 5

6
1 8
2 2
3 7
4 9
5 1
6 4
*/