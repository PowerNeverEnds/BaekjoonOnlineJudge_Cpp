#include <iostream>
#include <vector>
#include <cassert>

#define MAX 1000000

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> pn;	//prime number
	bool* num = new bool[MAX];
	fill(num, num + MAX, true);
	num[0] = false;
	num[1] = false;
	for (int i = 2; i < MAX; i++)
	{
		if (num[i] == true)
			for (int j = i + i; j < MAX; j += i)
				num[j] = false;
	}

	for (int i = 0; i < MAX; i++)
	{
		if (num[i] == true)
			pn.push_back(i);
	}
	//for (int i = 0; i < pn.size(); i++)
	//	cout << pn[i] << " ";

	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;
		bool match = false;
		for (int i = 0; i < pn.size(); i++)
		{
			int l = i, r = pn.size();
			while (true)
			{
				if (l > r)
					break;
				int m = (l + r) / 2;
				if (pn[i] + pn[m] == n)
				{
					cout << n << " = " << pn[i] << " + " << pn[m] << "\n";
					match = true;
					break;
				}
				else
				{
					if (pn[i] + pn[m] > n)
						r = m - 1;
					else
						l = m + 1;
				}
			}
			if (match == true)
				break;
		}
		if (match == false)
			assert(false);
			//cout << "Goldbach's conjecture is wrong." << "\n";
	}

	return 0;
}