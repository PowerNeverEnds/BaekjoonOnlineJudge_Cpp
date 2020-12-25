#include <iostream>
using namespace std;

#define MAX 100000
#define PUSH true
#define POP false

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int* arr = new int[MAX + 1];
	int pArr = n - 1;
	for (int i = 0; i < MAX + 1; i++)
		arr[i] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int* stack = new int[MAX + 1];
	int pStack = 0;
	for (int i = 0; i < MAX + 1; i++)
		stack[i] = 0;
	bool* pushpop = new bool[MAX * 2 + 1];
	int pPushpop = 0;
	for (int i = 0; i < MAX + 1; i++)
		pushpop[i] = true;
	int max = n;
	for (int i = 0; i < n * 2; i++)
	{
		if (pStack > 0 && stack[pStack - 1] == (max))
		{
			pStack--;
			max--;
			pushpop[pPushpop++] = POP;
		}
		else if (1)
		{
			stack[pStack++] = arr[pArr--];
			pushpop[pPushpop++] = PUSH;
		}

	}
	if (pStack==0)
	{
		for (int i = n * 2 - 1; i >= 0; i--)
		{
			if (!pushpop[i] == PUSH)
				cout << "+" << "\n";
			else
				cout << "-" << "\n";
		}
	}
	else
		cout << "NO" << "\n";
	return 0;
}