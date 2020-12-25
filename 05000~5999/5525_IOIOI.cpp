#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	string str;
	cin.ignore();
	cin >> str;

	int count = 0;
	for (int i = 0; i < M - N * 2; i++)
	{
		if (str[i] == 'I')
		{
			int cnt = 0;
			for (int j = i + 1; j < M - 1; j += 2)
			{
				if (str[j] == 'O' && str[(ll)j + 1] == 'I')
					cnt++;
				else
					break;
			}
			if (cnt >= N)
				count += cnt - N + 1;
			i += cnt * 2;
		}
	}

	cout << count << "\n";



	return 0;
}