#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	long long int sum=0;
	int number;
	int* arr = new int[500001];
	int* count = new int[8001];
	for (int i = 0; i < 8001; i++)
		count[i] = 0;
	int max = -4000, min = 4000;
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		arr[i] = number;
		count[number + 4000] += 1;
		sum += number;
		if (max < number)
			max = number;
		if (min > number)
			min = number;
	}
	sort(&arr[0], &arr[n]);
	if (sum > 0)
		cout << (int)(1.0 * sum / n + 0.5) << "\n";
	else
		cout << (int)(1.0 * sum / n - 0.5) << "\n";
	cout << arr[n / 2] << "\n";
	int manyOne=0, manyTwo;
	int manyOneCount = 0;
	for (int i = 8000; i >= 0; i--)
	{
		if (manyOneCount < count[i])
		{
			manyOne = i;
			manyOneCount = count[i];
			manyTwo = manyOne;
		}
		else if (manyOneCount == count[i])
		{
			manyTwo = manyOne;
			manyOne = i;
			manyOneCount = count[i];
		}
	}
	cout << manyTwo-4000 << "\n";
	cout << max - min << "\n";
	return 0;
}