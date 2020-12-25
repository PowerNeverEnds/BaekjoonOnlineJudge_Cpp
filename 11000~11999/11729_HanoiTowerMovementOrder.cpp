#include <iostream>
using namespace std;

int pow(int n, int m);
void hanoi(int i, int n, int m);

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	cout << pow(2, n) - 1<<"\n";
	hanoi(n,1,3);
	return 0;
}

int pow(int n, int m)
{
	int sum = 1;
	for (int i = 0; i < m; i++)
	{
		sum *= n;
	}
	return sum;
}

void hanoi(int i,int n,int m)
{
	if (i == 1)
	{
		cout << n << " " << m << "\n";
		return;
	}
	else
	{
		int key = 6 - (n + m);
		hanoi(i - 1, n, key);
		cout << n << " " << m << "\n";
		hanoi(i - 1, key, m);
		return;
	}
}