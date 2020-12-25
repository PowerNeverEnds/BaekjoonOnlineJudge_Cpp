
/*
https://www.acmicpc.net/problem/14888
*/
#include <iostream>
#include <cstring>


using namespace std;

int n;
int a[11];
int oper[10];
bool visit[10];

int maxvalue = -2147483648LL;
int minvalue = 2147483647;
int cnt = 0;



void dfs(int num, int sum) {
	int tmp;

	if (num == n - 1) {
		if (sum > maxvalue) {
			maxvalue = sum;
		}
		if (sum < minvalue) {
			minvalue = sum;
		}

		return;
	}
	else {
		for (int i = 0; i < n - 1; i++) {
			if (!visit[i]) {
				if (oper[i] == 1) {
					tmp = sum + a[num + 1];
				}
				else if (oper[i] == 2) {
					tmp = sum - a[num + 1];
				}
				else if (oper[i] == 3) {
					tmp = sum * a[num + 1];
				}
				else if (oper[i] == 4) {
					tmp = sum / a[num + 1];
				}
				visit[i] = true;
				dfs(num + 1, tmp);
				visit[i] = false;
			}
		}
	}
}


int main() {
	int tmp, cnt = 0;
	cin >> n;


	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	for (int i = 0; i < 4; i++) {
		cin >> tmp;
		for (int j = 0; j < tmp; j++) {
			oper[cnt++] = (i + 1);
		}
	}

	for (int i = 0; i < 10; i++)
		cout << oper[i] << " ";
	cout << "\n";

	dfs(0, a[0]);

	cout << maxvalue << '\n' << minvalue << '\n';

	return 0;
}
/*
6
1 2 3 4 5 6
2 1 1 1

*/



/*
#include <iostream>
#include <algorithm>

#define MAX (int(1e9));

using namespace std;

void dfs(int sum, int operCnt[],int arr[],int d,int N,int& min,int& max)
{
	if (d == N)
	{
		min = sum < min ? sum : min;
		max = sum > max ? sum : max;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nOperCnt[4];
		copy(operCnt, operCnt + 4, nOperCnt);

		//cout << d << "\n";
		//for (int i = 0; i < 4; i++)
		//	cout << nOperCnt[i] << " ";
		//cout << "\n";

		if (operCnt[i] > 0)
		{
			nOperCnt[i]--;
			switch (i)
			{
			case 0:
				dfs(sum + arr[d], nOperCnt, arr, d + 1, N,min,max);
				break;
			case 1:
				dfs(sum - arr[d], nOperCnt, arr, d + 1, N,min,max);
				break;
			case 2:
				dfs(sum * arr[d], nOperCnt, arr, d + 1, N,min,max);
				break;
			case 3:
				dfs(sum / arr[d], nOperCnt, arr, d + 1, N,min,max);
				break;
			default:
				break;
			}
		}
	}

}

int main()
{
	int N;
	cin >> N;

	int A[12] = { 0, };
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int operCnt[4];
	for (int i = 0; i < 4; i++)
		cin >> operCnt[i];

	int max = -MAX;
	int min = MAX;

	dfs(A[0],operCnt,A,1,N,min,max);

	//for (int i = 0; i < 4; i++)
	//	cout << operCnt[i] << " ";
	//cout << "\n";

	cout << max << "\n";
	cout << min << "\n";

	return 0;
}
*/