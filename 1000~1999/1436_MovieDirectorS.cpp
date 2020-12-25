#include <iostream>
using namespace std;

int findEnd(int end);

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	
	cout<< findEnd(n)<<"\n";

	return 0;
}

int findEnd(int end)
{
	int n=0;
	for (int i = 0;; i++)
	{
		int m = i;
		int count = 0;
		for (int j = 0;; j++)
		{
			if (m % 10 == 6 && 0 < m)
			{
				count++;
				if (count == 3)
				{
					n++;
				}
			}
			else if (m == 0)
				break;
			else
				count = 0;
			m /= 10;
		}
		if (n == end)
			return i;
	}
}