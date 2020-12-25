#include <iostream>
using namespace std;

long long int padovan(int n, long long int* arr);
void setArr(long long int* arr);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	long long int arr[102] = { 0, };
	setArr(arr);
	while (t-- > 0)
	{
		int n;
		cin >> n;
		cout<<padovan(n,arr)<<"\n";
	}

	return 0;
}
long long int padovan(int n, long long int *arr)
{
	long long int result;
	if (arr[n] == 0)
	{
		result = arr[n] = padovan(n - 1,arr) + padovan(n - 5,arr);
	}
	else
	{
		result = arr[n];
	}
	return result;
}

void setArr(long long int* arr) {
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	arr[6] = 3;
	arr[7] = 4;
	arr[8] = 5;
	arr[9] = 7;
	arr[10] = 9;
}