#include <iostream>
#include <string>
#include <vector>

typedef long long ll;

using namespace std;


vector<int> defFail(string P)
{
	vector<int> fail;
	int i = 1;
	int j = 0;
	fail.push_back(0);
	while (i < P.length())
	{
		while (true)
		{
			if (P[i] == P[j] || j == 0)
				break;
			//cout << j << "\n";
			j = fail[(ll)j - 1];
		}
		if (P[i] == P[j])
		{
			fail.push_back(j + 1);
			j++;
		}
		else
			fail.push_back(0);
		i++;
	}

	return fail;
}

vector<int> kmp(string T, string P)
{
	vector<int> re;
	auto fail = defFail(P);
	//for (int i = 0; i < fail.size(); i++)
	//{
	//	cout << i << " " << fail[i] << "\n";
	//}

	int i = 0;
	int j = 0;
	for (; i != T.length(); i++)
	{
		//if (i == T.length())
		//	break;
		while (true)
		{
			//cout << i << " " << j << " " << T[i] << " " << P[j] << "\n";
			if (T[i] == P[j] || j == 0)
			{
				break;
			}
			//cout << j << "to" << fail[(ll)j - 1] << "\n";
			j = fail[(ll)j - 1];
		}
		//cout << i << " " << j << "\n";
		if (T[i] == P[j])
		{
			if (j == P.length() - 1)
			{
				//cout << i << " " << j << " " << T[i - 1] << T[i] << T[i + 1] << "\n";
				//re.push_back(i - j + 1 - 1);
				re.push_back(i - P.length() + 2 - 1);
				j = fail[(ll)j - 1 + 1];
			}
			else
				j++;
		}
	}

	return re;
}

int main()
{
	string T;
	string P;
	getline(cin, T);
	getline(cin, P);
	//cout << T << "\n";
	//cout << P << "\n";
	vector<int> re;
	re = kmp(T, P);

	cout << re.size() << "\n";
	for (auto e : re)
	{
		cout << e + 1 << "\n";
	}

	return 0;
}

/*
ABC ABCDAB ABCDABCDABDE
ABCDABD

ABABABABBABABABABC
ABABABABC

a
ababaca

a
abacabad

a
abcabaa

abcabcabc
abcabc

ababab
abab

aaa
aa

abcabcabc
abc


*/