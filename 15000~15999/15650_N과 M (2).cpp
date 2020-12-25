#include <iostream>
using namespace std;

void arrPrint(int* arr, int M)
{
	for (int i = 0; i < M; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

void nmPrint(int n, int m, int* arr, const int N, const int M)
{
	if (m <= 0)
		return;
	for (int i = n; i <=N; i++)
	{
			arr[M-m] = i;
		if (m == 1)
		{
			arrPrint(arr, M);
		}
		nmPrint(i+1, m - 1, arr, N, M);
	}
	return;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	int arr[9] = { 0, };
	nmPrint(1, M, arr, N, M);

	return 0;
}

/*
#include <iostream>
using namespace std;

void arrPrint(int* arr, int M)
{
	for (int i = 0; i <= M; i++)
		cout << arr[i] << " ";
	cout << "\n";
}
//void nmPrint(int n, int m, int* arr, const int N, const int M)
//{
//	cout << n << " "<<m << "\n";
//	//while (true)
//	//{
//		if (m == M)
//		{
//			arrPrint(arr, M);
//			return;
//		}
//		//if(n==N)
//		//	n=
//		nmPrint(n, m + 1, arr, N, M);
//	//}
//}

void nmPrint(int n, int m, int* arr, const int N, const int M)
{
	//cout << n << " " << m << "\n";
	if (m < 0)
		return;
	for (int i = n; i <=N; i++)
	{
			//cout <<i<<" "<< n << " " << m << "\n";
			arr[M-m] = i;
		if (m == 0)
		{
			arrPrint(arr, M);
//			return;
		}
		nmPrint(i+1, m - 1, arr, N, M);
	}
	return;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	int arr[9] = { 0, };
	//for (int i = 1; i <= 8; i++)
	//	arr[i] = i;

	//nmPrint(N, 1, arr, N, M);
	nmPrint(1, M-1, arr, N, M);

	return 0;
}
*/