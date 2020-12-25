/*
둘다 맞는 코드
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
실행속도	결과는배열에저장후출력		배열저장+cin.tie(NULL);도 사용		cin.tie(NULL);만 사용
이분탐색			 748ms							328ms						320ms
map사용			시간초과							772ms						시간초과

중요한점.
1. cin.tie(NULL); 사용(기본적인거니까넘어가고)
2. 가능하면 배열에 저장후 한꺼번에 출력(입력, 계산, 출력 따로)
입력과 출력은 따로
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