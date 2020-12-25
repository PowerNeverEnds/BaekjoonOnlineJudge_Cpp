#include <iostream>
using namespace std;

int fibonacci(int n);

int mem[41];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	mem[0] = 0;
	mem[1] = 1;
	fibonacci(40);
	int t;
	cin >> t;
	while (t-- > 0)
	{
		int n;
		cin >> n;
		if (n == 0)
			cout << "1 0" << "\n";
		else if (n == 1)
			cout << "0 1" << "\n";
		else
			cout << mem[n - 1] << " " << mem[n] << "\n";
	}
	return 0;
}
int fibonacci(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		if (mem[n] != 0)
			return mem[n];
		return mem[n]=fibonacci(n-1) + fibonacci(n-2);
	}
}