#include <iostream>

#define MAX ((int)(1e9))

using namespace std;

int myMax(int a, int b, int c = 0)
{
	a = a > b ? a : b;
	return a > c ? a : c;
}
int myMin(int a, int b, int c = MAX)
{
	a = a < b ? a : b;
	return a < c ? a : c;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int maxArr[3] = { 0, };
	int minArr[3] = { 0, };
	int nArr[3] = { 0, };
	int tArr[3] = { 0, };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> nArr[j];

		tArr[0] = nArr[0] + myMax(maxArr[0], maxArr[1]);
		tArr[1] = nArr[1] + myMax(maxArr[0], maxArr[1], maxArr[2]);
		tArr[2] = nArr[2] + myMax(maxArr[1], maxArr[2]);
		for (int j = 0; j < 3; j++)
			maxArr[j] = tArr[j];

		tArr[0] = nArr[0] + myMin(minArr[0], minArr[1]);
		tArr[1] = nArr[1] + myMin(minArr[0], minArr[1], minArr[2]);
		tArr[2] = nArr[2] + myMin(minArr[1], minArr[2]);
		for (int j = 0; j < 3; j++)
			minArr[j] = tArr[j];

		//for (int j = 0; j < 3; j++)
		//	cout << maxArr[j] << " ";
		//cout << "\n";
		//for (int j = 0; j < 3; j++)
		//	cout << minArr[j] << " ";
		//cout << "\n";
	}

	cout << myMax(maxArr[0], maxArr[1], maxArr[2]) << " ";
	cout << myMin(minArr[0], minArr[1], minArr[2]) << "\n";

	return 0;
}