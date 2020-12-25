// 배낭문제 인터넷검색후 코드 짜기
// https://dheldh77.tistory.com/232

#include <iostream>
#include <algorithm>
using namespace std;

int W[102];
int V[102];
int dp[102][100001];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> W[i] >> V[i];
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			if (j < W[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j - W[i]] + V[i], dp[i - 1][j]);
		}
	}
	//for (int i = 0; i <= N; i++)
	//{
	//	for (int j = 0; j <= K; j++)
	//	{
	//		cout << dp[i][j] << " ";
	//	}cout << "\n";
	//}
	cout << dp[N][K] << "\n";

	return 0;
}

/*
#include <iostream>
#include <algorithm>
using namespace std;


class VW {
public:
	int W;
	int V;
	double VdW;
};
//int W[100];
//int V[100];
//double VdW[100];

int mem[100001][2];	// 100 -> 101 // 101 -> 100001
int n, k;

int dp(int w, VW* vw)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (w >= vw[i].W && mem[i][1]==0)
		{
			mem[i][1] = 1;
			break;
		}
	}
	if (i == n)
		return 0;
	int d = vw[i].V + dp(w - vw[i].W, vw);
	mem[w][0] = d > mem[w][0] ? d : mem[w][0];
	return mem[w][0];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	VW* vw = new VW[n];
	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		vw[i].W = w;
		vw[i].V = v;
		vw[i].VdW = (double)v / w;
	}
	sort(&vw[0], &vw[n], [](VW a, VW b) {
		return a.VdW > b.VdW;
		});

	for (int i = 0; i < n; i++)
	{
		cout << dp(i, vw) << "\n";
	}
	//for (int i = 0; i < n; i++)
	//{
	//	int j;
	//	for (j = k - vw[i].W; j > 0; j--)
	//	{
	//		if (mem[j][0] > 0)
	//		{
	//			if (mem[j + vw[i].W][0] < (mem[j][0] + vw[i].V))	// 현재값이랑 비교 조건문추가
	//				mem[j + vw[i].W][0] = mem[j][0] + vw[i].V;
	//			break;
	//		}
	//	}
	//	if (j == 0)
	//	{
	//		mem[vw[i].W][0] = vw[i].V;
	//	}
	//	//for (int i = 0; i < k; i++)
	//	//{
	//	//	cout << mem[i][0] << " ";
	//	//}
	//	//cout << mem[k][0] << "\n";
	//}

	// for문 추가
	int max = 0;
	for (int i = k; i > 0; i--)
	{
		max = mem[i][0] > max ? mem[i][0] : max;
	}
//	cout << mem[k][0] << "\n";	// mem[k][0] 대신 max 출력
	cout << max;

	for (int i = 0; i <= k; i++)
	{
		cout << mem[i][0] << " ";
	}cout << "\n";
	return 0;
}
*/