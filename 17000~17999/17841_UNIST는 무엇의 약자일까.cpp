/*
https://m.blog.naver.com/jh05013/221698923493
17841 UNIST�� ������ �����ϱ�?

DP[i][j] = "ù i���� �ܾ ����ϸ鼭, UNIST�� ù j���ڸ� ����� ����� ��"�� �����մϴ�. ���̳��� ���α׷����Դϴ�. i��° �ܾ��� ���λ簡 UNIST�� L��°���� R��°������ ������, DP[i][R]�� DP[i-1][L-1]�� ���մϴ�.

http://hexa-unist.github.io/document/Uni-Code_solution.pdf
How can we solve the problem if
len(W1) = len(W2) = �� �� �� = len(WN) = 1?
We can approach using dynamic programming, by defining
D[i][j] as the number of way P1 + P2 + �� �� �� + Pi being prefix
of "UNIST" of length j, where i �� N, j �� 5.

Then, we have following recurrence relation.
D[i][j] = D[i - 1][j] + 1. D[i][j - 1]	if Wi[0] == "UNIST"[j]
						2. 0			otherwise

Then, in general, we can generalize previous recurrence
relation to solve the problem.
with same definition of D[i][j].
Since the recurrence relation is hard to write, I omitted in this
slide. However, it is still easy to implement so don��t worry.
Total time complexity is O(N), with large constant factor.
*/

#include <iostream>
#include <vector>

#define DIV ((int)1e9+7)

typedef long long ll;

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int** dp = new int* [(ll)N + 1];
	fill(dp, dp + N + 1, nullptr);
	for (int i = 0; i < (ll)N + 1; i++)
	{
		dp[i] = new int[6];
		fill(dp[i], dp[i] + 6, 0);
	}

	vector<string> vecStr;
	vecStr.push_back(" ");
	string unist = " UNIST";
	for (int i = 0; i < N; i++)
	{
		string tStr;
		cin.ignore();
		cin >> tStr;
		vecStr.push_back(" " + tStr);
	}

	for (int i = 0; i < (ll)N + 1; i++)
		dp[i][0] = 1;
	for (int i = 1; i < (ll)N + 1; i++)
	{
		int k = 1;
		bool finish = false;
		for (int j = 1; j < 6; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (!finish &&(ll)k < vecStr[i].length() && vecStr[i][(ll)k] == unist[j])
			{
				dp[i][j] += dp[i][j - k];
				dp[i][j] %= DIV;
				k++;
			}
			else if (k != 1)
				finish = true;
		}
	}
	//for (int i = 0; i < (ll)N + 1; i++)
	//{
	//	for (int j = 0; j < 6; j++)
	//	{
	//		cout << dp[i][j] << " ";
	//	}cout << "\n";
	//}cout << "\n";

	cout << dp[(ll)N][5] << "\n";

	return 0;
}


/*
exist	���ӵ����ξ� 12345
count	exist�� 1�ϰ��(���ξ�ΰ���(IS�� ��� I�� �������):sum�̶� �������,
		exist�� 1�̾ƴҰ��(IS�� ���, S�� �������):������ count�� ����.
sum		�հ�
 exist	count	sum
 I
 NS
 UITST
U10000 1		11111
N20000 1		11111
I31000 11		12222
S02010 01020	01133
T00101 00103	00114
*/
/*
#include <iostream>
#include <string>
#include <vector>

typedef long long ll;

#define DIV ((int)1e9+7)	// ��ȣ���ϱ�
							// ���ϸ�
							// a%DIV -> a%(int)1e9)+7
							// ������ ������ +7�� ��,

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<string> vecStr;	// allStr ����(allStr����ؿ�����)
	vecStr.push_back(" ");
	string unist = " UNIST";
	for (int i = 0; i < N; i++)
	{
		string allStr = " ";	// UNIST�� �ϳ��� ���ξ�����ϴ� Pi
								// Pi�� Wi�� ���� len(Pi)�� ���λ��̴�.
		string tStr;
		cin.ignore();
		cin >> tStr;
		bool start = false;
		int k = 0;
		for (int j = 0; j < unist.length(); j++)
		{
			if (tStr.length() <= k)
				break;
			if (tStr[k] == unist[j])
			{
				allStr += tStr[k];
				k++;
				start = true;
			}
			else if (start == true)
				break;
		}
		vecStr.push_back(allStr);
	}

	// ���� �ּ�����
	int** existArr = new int* [5 + 1];
	fill(existArr, existArr + 5 + 1, nullptr);
	for (int i = 0; i <= 5; i++)
	{
		existArr[i] = new int[(ll)vecStr.size() + 2];
		fill(existArr[i], existArr[i] + (ll)vecStr.size() + 2, 0);
	}
	int** countArr = new int* [5 + 1];
	fill(countArr, countArr + 5 + 1, nullptr);
	for (int i = 0; i <= 5; i++)
	{
		countArr[i] = new int[(ll)vecStr.size() + 2];
		fill(countArr[i], countArr[i] + (ll)vecStr.size() + 2, 0);
	}
	int** sumArr = new int* [5 + 1];
	fill(sumArr, sumArr + 5 + 1, nullptr);
	for (int i = 0; i <= 5; i++)
	{
		sumArr[i] = new int[(ll)vecStr.size() + 2];
		fill(sumArr[i], sumArr[i] + (ll)vecStr.size() + 2, 0);
	}

	for (int i = 0; i <= (ll)vecStr.size() - 1; i++)
	{
		int l = 0;
		for (l = 0; l <= 5; l++)
		{
			if (unist[l] == vecStr[i][1])
				break;
		}
		int r = 0;
		for (r = 0; r <= 5; r++)
		{
			if (unist[r] == vecStr[i][vecStr[i].length()-1])
				break;
		}
		for (int k = l; k <= r; k++)
		{
			existArr[k][i] = k - l + 1;
		}
	}
	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= (ll)vecStr.size() - 1; j++)
		{
			cout << existArr[i][j] << " ";
		}cout << "\n";
	}cout << "\n";

	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= (ll)vecStr.size() - 1; j++)
		{
			if (existArr[i][j] >= 1)
			{
				if (existArr[i][j] != 1)
					countArr[i][j] = countArr[i - 1][j];
				else
					countArr[i][j] = max(sumArr[i - 1][j - 1], 1);
			}
			sumArr[i][j] = (sumArr[i][j - 1] + countArr[i][j]) % DIV;
		}
	}

	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= (ll)vecStr.size() - 1; j++)
		{
			cout << countArr[i][j] << " ";
		}cout << "\n";
	}cout << "\n";
	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= (ll)vecStr.size() - 1; j++)
		{
			cout << sumArr[i][j] << " ";
		}cout << "\n";
	}cout << "\n";

	cout << sumArr[5][(ll)vecStr.size()-1] << "\n";


	return 0;
}
*/
/*
10
U
N
I
S
T
U
N
I
S
T

8
UNIS
NT
IS
ST
UNIS
NT
IS
ST

50
U
U
U
U
U
U
U
U
U
U
N
N
N
N
N
N
N
N
N
N
I
I
I
I
I
I
I
I
I
I
S
S
S
S
S
S
S
S
S
S
T
T
T
T
T
T
T
T
T
T

*/