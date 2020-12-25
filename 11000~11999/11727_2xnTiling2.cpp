#include <iostream>
using namespace std;

int tiling(int n, int* arr);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int arr[1001] = { 0, };
	{
		arr[0] = 0;
		arr[1] = 1;
		arr[2] = 3;
		arr[3] = arr[2] + arr[1]*2;
	}
	cout<<tiling(n, arr)<<"\n";
	return 0;
}

int tiling(int n, int* arr)
{
	int result;
	if (arr[n] == 0)
	{
		result = arr[n] = (tiling(n - 1, arr) + tiling(n - 2, arr) * 2)%10007;
	}
	else
		result = arr[n];
	return result;
}