/*
�Ѵ� �´� �ڵ�
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
����ӵ�	����¹迭�����������		�迭����+cin.tie(NULL);�� ���		cin.tie(NULL);�� ���
�̺�Ž��			 748ms							328ms						320ms
map���			�ð��ʰ�							772ms						�ð��ʰ�

�߿�����.
1. cin.tie(NULL); ���(�⺻���ΰŴϱ�Ѿ��)
2. �����ϸ� �迭�� ������ �Ѳ����� ���(�Է�, ���, ��� ����)
�Է°� ����� ����
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int arr[500000] = { 0, };
int arr_out[500000] = { 0, };
int arr_M[500000] = { 0, };
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N, [](auto a, auto b) {
		return a < b;
		});

	int M;
	cin >> M;
	//int e;
	for (int i = 0; i < M; i++)
	{
		cin >> arr_M[i];
	}
	for (int i = 0; i < M; i++)
	{
		arr_out[i] = upper_bound(arr, arr + N, arr_M[i]) - lower_bound(arr, arr + N, arr_M[i]);
	}
	for (int i = 0; i < M; i++)
	{
		cout << arr_out[i] << " ";
	}
	return 0;
}
*/

/*
#include <iostream>
#include <map>
using namespace std;

int arr[500000] = { 0, };
int arr_out[500000] = { 0, };
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	map<int, int> m;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int e;
		cin >> e;
		//if (m.find(e) != m.end())
		//{
		m[e]++;
		//}
		//else
		//{
		//	m[e] = 1;
		//}
	}
	//map<int,int>::iterator iter;
	//for (iter = m.begin(); iter != m.end(); iter++)
	//{
	//	cout << iter->first << " " << iter->second << "\n";
	//}

	int M;
	cin >> M;
	int e;
	for (int i = 0; i < M; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < M; i++)
	{
		if (m.find(arr[i]) != m.end())
		{
			arr_out[i] = m.find(arr[i])->second;
		}
		else
		{
			arr_out[i] = 0;
		}
	}
	for (int i = 0; i < M; i++)
	{
		cout << arr_out[i] << " ";
	}
	cout << "\n";
	return 0;
}
*/