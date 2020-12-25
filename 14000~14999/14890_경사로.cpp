#include <iostream>

using namespace std;

int myAbs(int a, int b)
{
	return a > b ? a - b : b - a;
}

bool defPass(int** arr, int& prev1, int& L1, const int i, const int j, int& remain1, const int L)
{
	if (prev1 == arr[i][j])
		if (remain1)
			remain1--;
		else
			L1++;
	else if (myAbs(prev1, arr[i][j]) != 1)
		return false;
	else
		if (prev1 > arr[i][j])
			if (remain1)
				return false;
			else
			{
				remain1 = L - 1;
				L1 = 0;
			}
		else if (prev1 < arr[i][j])
			if (L1 < L)
				return false;
			else
				L1 = 1;
	prev1 = arr[i][j];

	return true;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, L;
	cin >> N >> L;
	int** arr = new int* [N];
	fill(arr, arr + N, nullptr);
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		fill(arr[i], arr[i] + N, 0);
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int L1 = 0, L2 = 0;
		int prev1 = arr[i][0];
		int prev2 = arr[0][i];
		bool isPassed1 = true;
		bool isPassed2 = true;
		int remain1 = 0, remain2 = 0;
		for (int j = 0; j < N; j++)
		{
			if (isPassed1)
				isPassed1 = defPass(arr, prev1, L1, i, j, remain1, L);
			if (isPassed2)
				isPassed2 = defPass(arr, prev2, L2, j, i, remain2, L);
			if (!isPassed1 && !isPassed2)
				break;
		}
		if (remain1)
			isPassed1 = false;
		if (remain2)
			isPassed2 = false;
		cnt += isPassed1 + isPassed2;
	}

	cout << cnt << "\n";

	return 0;
}


/*

#include <iostream>

using namespace std;

int myAbs(int a, int b)
{
	return a > b ? a - b : b - a;
}

bool defPass(int** arr, int& prev1, int& L1, const int i, const int j, int& remain1, const int L)
{
	//cout <<i<<" "<<j<<", "<< prev1 << " " << arr[i][j] <<", "<<remain1<<" "<<L1<< "\n";
	if (prev1 == arr[i][j])
	{
		if (remain1)
			remain1--;
		else
			L1++;
	}
	else if (myAbs(prev1, arr[i][j]) != 1)
	{
		//cout << "!1" << "\n";
		return false;
	}
	else
	{
		if (prev1 > arr[i][j])
		{
			if (remain1)
			{
				//cout << "remain1" << "\n";
				return false;
			}
			else
			{
				remain1 = L - 1;
				L1 = 0;
			}
		}
		else if (prev1 < arr[i][j])
		{
			if (L1 < L)
			{
				//cout << "L1<L" <<" "<<L1<<" "<<L<< "\n";
				return false;
			}
			else
			{
				L1 = 1;
			}
		}
	}
	prev1 = arr[i][j];

	return true;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, L;
	cin >> N >> L;
	int** arr = new int* [N];
	fill(arr, arr + N, nullptr);
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		fill(arr[i], arr[i] + N, 0);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int L1 = 0, L2 = 0;
		int prev1 = arr[i][0];
		int prev2 = arr[0][i];
		bool isPassed1 = true;
		bool isPassed2 = true;
		int remain1 = 0, remain2 = 0;
		for (int j = 0; j < N; j++)
		{
			if (isPassed1)
				isPassed1 = defPass(arr, prev1, L1, i, j, remain1, L);
			if (isPassed2)
				isPassed2 = defPass(arr, prev2, L2, j, i, remain2, L);
			if (!isPassed1 && !isPassed2)
				break;
		}
		if (remain1)
			isPassed1 = false;
		if (remain2)
			isPassed2 = false;
		//cout << isPassed1 << " " << isPassed2 << "\n";
		cnt += isPassed1 + isPassed2;
	}

	cout << cnt << "\n";

	return 0;
}


*/