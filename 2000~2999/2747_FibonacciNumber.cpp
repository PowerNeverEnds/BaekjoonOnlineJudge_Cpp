#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n, vector<int>& fibo);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> fibo;
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		fibo.push_back(0);
	}
	fibo[0] = 0;
	fibo[1] = 1;
	cout << fibonacci(n,fibo) << "\n";
	
}

int fibonacci(int n, vector<int> &fibo)
{
	int result;
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
	{
		if (fibo[n]==0)
			result =fibo[n]= fibonacci(n - 1,fibo) + fibonacci(n - 2,fibo);
		else
		{
			result = fibo[n];
		}
	}
	return result;
}