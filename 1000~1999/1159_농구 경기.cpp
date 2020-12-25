#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int cnt[26] = { 0, };
	for (int i = 0; i < N; i++)
	{
		string str;
		cin.ignore();
		cin >> str;
		int ind = str[0] - 'a';
		cnt[ind]++;
	}
	vector<int> out;
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] >= 5)
			out.push_back(i);
	}
	if (out.size() == 0)
		cout << "PREDAJA" << "\n";
	else
	{
		for (auto e : out)
			cout << char(e + 'a');
	}

	return 0;
}