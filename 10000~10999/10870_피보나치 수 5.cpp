#include <iostream>
using namespace std;

int fibo(int);

int mem[21];

int main()
{
	int n;
	cin >> n;
	cout << fibo(n);
	return 0;
}

int fibo(int n)
{
	if (mem[n] != 0)
		return mem[n];
	if (n == 0 || n==1)
		return n;
	return fibo(n - 1) + fibo(n - 2);
}