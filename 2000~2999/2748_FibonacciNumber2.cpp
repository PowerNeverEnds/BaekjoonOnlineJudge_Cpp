#include <iostream>
using namespace std;

long long int fibonacci(int n, long long int* mem);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	long long int mem[91] = { 0, };

	cout << fibonacci(n,mem) << "\n";;

	return 0;
}

long long int fibonacci(int n, long long int* mem)
{
	if (n == 0 || n == 1)
		return n;
	else
	{
		if (mem[n] != 0)
		{
			return mem[n];
		}
		return mem[n]=fibonacci(n - 1, mem) + fibonacci(n - 2, mem);
	}
}