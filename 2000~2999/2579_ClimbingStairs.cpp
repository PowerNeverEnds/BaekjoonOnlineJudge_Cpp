#include <iostream>
#include <queue>
using namespace std;

int climb(int n, int* arr, bool oneStep, int* mem, int* memoOne);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int* arr = new int[n + 1];	// ĭ�� ��
	int* memoization = new int[n + 1];	// ������ ��ĭ�� ��
	int* memoOne = new int[n + 1];	// ������ ��ĭ�� ��
	arr[0] = 0;
	memoization[0] = 0;	// 0 ��°ĭ���� ��
	memoOne[0] = 0;
	for (int i = 1; i < n + 1; i++)
	{
		int number;
		cin >> number;
		arr[i] = number;
		memoization[i] = -1;	// ���� ������ ���� ��
		memoOne[i] = -1;
	}
	memoization[1] = arr[1];	// 1��° ��ܱ����� ��
	memoOne[1] = arr[1];
	cout<<climb(n, arr, false, memoization, memoOne)<<"\n";
	return 0;
}

int climb(int n, int* arr, bool oneStep, int* mem, int* memoOne)
{
	int result = 0;
	if (n == 0 || n == 1)
	{
		result = arr[n];
	}
	else if (oneStep == true)
	{
		int b;
		if (memoOne[n - 2] != -1 && mem[n - 2] != -1)
		{
			b = arr[n] + (memoOne[n - 2] > mem[n - 2] ? memoOne[n - 2] : mem[n - 2]);
		}
		b = arr[n] + climb(n - 2, arr, false, mem,memoOne);
		result = b;
		mem[n] = b;
	}
	else if (oneStep == false)
	{
		int a;
		int b;
		if (mem[n-1] != -1)	// ��ĭ�۰��̱� ������ ������ 2ĭ�ڰ��� ���� ������ �������
		{
			a = arr[n] + mem[n-1];
		}
		else
			a = arr[n] + climb(n - 1, arr, true, mem, memoOne);
		if (memoOne[n-2] != -1 && mem[n-2] != -1)
		{
			b = arr[n] + (memoOne[n - 2] > mem[n - 2] ? memoOne[n - 2] : mem[n - 2]);
		}
		else 
			b = arr[n] + climb(n - 2, arr, false, mem,memoOne);
		result = a > b ? a : b;
			memoOne[n] = a;
			mem[n] = b;
	}
	return result;
}
/*
#include <iostream>
#include <queue>
using namespace std;

int climb(int n, int* arr, bool oneStep, int* mem, int* memoOne);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int* arr = new int[n + 1];
	int* memoization = new int[n + 1];
	int* memoOne = new int[n + 1];
	arr[0] = 0;
	memoization[0] = 0;
	memoOne[0] = 0;
	for (int i = 1; i < n + 1; i++)
	{
		int number;
		cin >> number;
		arr[i] = number;
		memoization[i] = 0;
		memoOne[i] = 0;
	}

	cout << climb(n, arr, false, memoization, memoOne) << "\n";
	//	for (int i = 0; i < n + 1; i++)
	//	{
	//		cout << memoization[i]<<" "<< memoOne[i]<< "\n";
	//	}
	return 0;
}

int climb(int n, int* arr, bool oneStep, int* mem, int* memoOne)
{
	int result = 0;
	//	cout << "n: " << n << " arr[n]: " << arr[n] << " oneStep: " << oneStep << "\n";
	if (n == 0 || n == 1)
	{
		result = arr[n];
	}
	else if (oneStep == true)
	{
		int b;
		//		if (mem[n] != 0)
		//			b = arr[n] + mem[n];
		//		else
		b = arr[n] + climb(n - 2, arr, false, mem, memoOne);
		result = b;
		//		mem[n] = b;
	}
	else if (oneStep == false)
	{
		int a;
		int b;
		if (mem[n - 1] != 0)
		{
			a = arr[n] + mem[n - 1];
			//			cout <<mem[n-1]<< "!";
		}
		else
			a = arr[n] + climb(n - 1, arr, true, mem, memoOne);
		if (memoOne[n - 2] != 0)
		{
			b = arr[n] + memoOne[n - 2];
			//			cout <<memoOne[n-2]<< "@";
		}
		else
			b = arr[n] + climb(n - 2, arr, false, mem, memoOne);
		result = a > b ? a : b;
		//		cout << a << " " << b << " ";
		//		if (a > b)
		//			cout << "a";
		//		if (a > b)
		memoOne[n] = a;
		mem[n] = b;
	}
	//	mem[n] = result;
	//	cout << n << " " << mem[n] <<" "<<memoOne[n]<< "\n";
	return result;
}
*/