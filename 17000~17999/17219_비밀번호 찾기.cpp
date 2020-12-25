#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	map<string, string> m;

	cin.ignore();
	string email, pass;
	for (int i = 0; i < N; i++)
	{
		cin >> email >> pass;
		m[email] = pass;
	}

	vector<string> out;
	for (int i = 0; i < M; i++)
	{
		cin >> email;
		out.push_back(m[email]);
	}

	for (int i = 0; i < M; i++)
	{
		cout << out[i] << "\n";
	}

	return 0;
}