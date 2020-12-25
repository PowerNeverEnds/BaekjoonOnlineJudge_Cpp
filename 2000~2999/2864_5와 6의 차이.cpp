#include <iostream>
#include <string>

using namespace std;

void setAtoB(string str, string& minStr, char a, char b)
{
	for (auto e : str)
	{
		if (e == a)
			minStr += b;
		else
			minStr += e;
	}
}

int main()
{
	string aStr, bStr;
	cin >> aStr >> bStr;
	string minAstr, minBstr;
	string maxAstr, maxBstr;
	minAstr = "";
	minBstr = "";
	setAtoB(aStr, minAstr,'6','5');
	setAtoB(bStr, minBstr, '6', '5');

	setAtoB(aStr, maxAstr, '5', '6');
	setAtoB(bStr, maxBstr, '5', '6');

	cout << stoi(minAstr) + stoi(minBstr) << " ";
	cout << stoi(maxAstr) + stoi(maxBstr) << "\n";

	return 0;
}