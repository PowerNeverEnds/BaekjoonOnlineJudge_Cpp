#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int* dp = new int[(ll)k + 1];
	fill(dp, dp + k + 1, 0);
	int* arr = new int[(ll)n];
	fill(arr, arr + n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (0 <= j - arr[i])
				dp[j] += dp[j - arr[i]];
		}
	//for (int i = 1; i <= k; i++)
	//{
	//	cout << dp[i] << " ";
	//}cout << "\n";
	}

	cout << dp[k] << "\n";

	return 0;
}



























/*

#include <iostream>
//#include <vector>
using namespace std;

//int f(short i, short p, int* arr, short& arrSize, vector<vector<int>> ip);
int f(short i, short p, int* arr, short& arrSize, int** ip);
int main()
{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);

	short n;
	cin >> n;
	int* arr = new int[100];	// n���� ���� ����ġ ���� ex) 3�� 1 2 5
	int k;
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		arr[i] = number;
	}
//	int* coin = new int[k + 1];	// i��°�� i����ġ�� ����� �ִ� ������ ( ��� [k]�� �ٷ� ���ص���)
	int coin;
//for (int i = 0; i < k+1; i++)
//	{
//		coin[i] = 0;
//	}

	int** ip=NULL;	// [i����ġ][p��°] ���� 2�����迭,(p�� arr�� p��°)
	ip = new int* [10001];
	for (int i = 0; i < 10001; i++)
	{
		ip[i] = new int[100];
	}
//	vector<vector<int>> ip(10001,vector<int>(100));
	for (int i = 0; i < k + 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ip[i][j] = -1;
		}
	}
	//for (int i = 0; i < k + 1; i++)
	//{
	//	coin[i] = f(i, 0, arr, n);
	//}
	int abc;
	cout << "�޸� Ȯ�� �ƹ����Է�" << "\n";
	cin >> abc;
	coin = f(k, 0, arr, n, ip);
	cout << coin << "\n";
	//for (int i = 0; i < k + 1; i++)
	//{
	//	for (int j = 0; j < n + 1; j++)
	//	{
	//		cout << ip[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	return 0;
}
// ���� �ȵ��� �𸣰����� �۵����� ��. �ȵǸ� �¿�Ʋ?
// i ���ռ��� ( �Ƹ� i, p ���� �غ����� �̷��� �ǰ���??)
// 1 1111111111
// 2 111111112
// 3 X
// 4 11111122
// 5 111115
// 6 1111222
// 7 11125
// 8 112222
// 9 1225
// 10 22222 55
//int f(short i, short p ,int* arr,short& arrSize, vector<vector<int>> ip)
int f(short i, short p ,int* arr,short& arrSize, int** ip)
{
	int count = 0;
//	cout << i << " " << p << "\n";
	if (i - arr[p] < 0)	// �ȵǴ� ����
		return 0;
	else if (i - arr[p] == 0)	// ���°� ����
	{
//		cout << " OK" << "\n";
//		count++;
		return 1;	// return 1�� �ؼ� count 1������Ű�鼭 ���� p
	}
	else
	{
		count += f(i - arr[p], p, arr, arrSize, ip);
//		f(i - arr[p], p, arr, arrSize, ip,count);
		if (p + 1 < arrSize && (i - arr[p + 1] >= 0))
		{
			if (ip[i][p + 1] != -1)
			{
//				cout <<i<<" "<<p<<" "<< ip[i][p + 1] << "OOKK"<<"\n";
				count += ip[i][p + 1];
			}
			else
			{
				count += f(i, p + 1, arr, arrSize, ip);
//				f(i, p + 1, arr, arrSize, ip, count);
			}
		}
	}
	ip[i][p] = count;
	return count;
}
*/

/*
���� 2013845695�Դϴ�.

100 10000
3
6
9
12
15
18
21
24
27
30
33
36
39
42
45
48
51
54
57
60
63
66
69
72
75
78
81
84
87
90
93
96
99
102
105
108
111
114
117
120
123
126
129
132
135
138
141
144
147
150
153
156
159
162
165
168
171
174
177
180
183
186
189
192
195
198
201
204
207
210
213
216
219
222
225
228
231
234
237
240
243
246
249
252
255
258
261
264
267
270
273
276
279
282
285
288
9640
9703
9856
9859

*/