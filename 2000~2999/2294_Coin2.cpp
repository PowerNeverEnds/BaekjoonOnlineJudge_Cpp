/*
2293_Coin1 ��Ȱ��
���� �װ� ��ǰ
*/

#include <iostream>
#include <algorithm>

using namespace std;

int f(int m,short i, short p, int* arr, short& arrSize, int** ip);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

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
	sort(&arr[0], &arr[n]);
	//	int* coin = new int[k + 1];	// i��°�� i����ġ�� ����� �ִ� ������ ( ��� [k]�� �ٷ� ���ص���)
	int coin;
	//for (int i = 0; i < k+1; i++)
	//	{
	//		coin[i] = 0;
	//	}

	int** ip = NULL;	// [i����ġ][p��°] ���� 2�����迭,(p�� arr�� p��°)
	ip = new int* [10001];
	for (int i = 0; i < 10001; i++)
	{
		ip[i] = new int[100];
	}
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
	//int abc;
	//cout << "�޸� Ȯ�� �ƹ����Է�" << "\n";
	//cin >> abc;
	coin = f(1, k, 0, arr, n, ip);
	if (coin == 10001)
		cout << -1 << "\n";
	else
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
int f(int m,short i, short p, int* arr, short& arrSize, int** ip)
{
	int count = 10001;
//		cout <<m<<" "<< i << " " << p << "\n";
	if (i - arr[p] < 0)	// �ȵǴ� ����
		return -1;
	else if (i - arr[p] == 0)	// ���°� ����
	{
//				cout << " OK "<<m << "\n";
		//		count++;
		return m;	// return 1�� �ؼ� count 1������Ű�鼭 ���� p
	}
	else
	{
		int t;
		t = f(++m, i - arr[p], p, arr, arrSize, ip);
		if (t != -1)
			count = count < t ? count : t;
		if (p + 1 < arrSize && (i - arr[p + 1] >= 0))
		{
			if (ip[i][p + 1] != -1)
			{
				//				cout <<i<<" "<<p<<" "<< ip[i][p + 1] << "OOKK"<<"\n";
				count=ip[i][p + 1];
			}
			else
			{
				int t;
				t = f(--m, i, p + 1, arr, arrSize, ip);
				if (t != -1)
					count = count < t ? count : t;
				//				f(i, p + 1, arr, arrSize, ip, count);
			}
		}
	}
	ip[i][p + 1] = count;
//	cout << "MM" << count << "\n";
	return count;
}

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