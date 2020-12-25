#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<string> vec;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin.ignore();
		cin >> str;
		vec.push_back(str);
	}
	string out = "";
	for (int i = 0; i < vec[0].length(); i++)
	{
		bool qMark = false;
		for (int j = 0; j < N; j++)
		{
			if (vec[j][i] != vec[0][i])
			{
				out += "?";
				qMark = true;
				break;
			}
		}
		if (qMark == false)
			out += vec[0][i];
	}
	
	cout << out << "\n";

	return 0;
}