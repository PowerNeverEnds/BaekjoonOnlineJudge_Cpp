/**
 *    BOJ 1544
 *    - 사이클 단어
 *    author:  phcdream
 *    created: 오전 4:25 2020-12-08
**/

#include <iostream>
#include <string>
#include <vector>

typedef long long ll;

using namespace std;

bool isSame(string str1, string str2)
{
	bool same = false;
	for (int i = 0; i < str2.length(); i++)
	{
		if (str1[0] == str2[i])
		{
			same = true;
			for (int k = 0; k < str1.length(); k++)
			{
				if (str1[k] != str2[(ll)i + k])
				{
					same = false;
					break;
				}
			}
			if (same == true)
				return true;
		}
	}

	return false;	
}

int main()
{
	int N;
	cin >> N;
	vector<string> vec1;
	vector<string> vec2;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin.ignore();
		cin >> str;
		vec1.push_back(str);
		vec2.push_back(str + str);
	}

	bool* visited = new bool[(ll)N];
	fill(visited, visited + N, false);
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (visited[i] == true)
			continue;
		bool same = false;
		for (int j = i; j < N; j++)
		{
			if (visited[j] == true)
				continue;
			if (vec1[i].length() * 2 == vec2[j].length())
			{
				if (isSame(vec1[i], vec2[j]) == true)
				{
					visited[i] = true;
					visited[j] = true;
					same = true;
				}
			}
		}
		if (same == true)
			cnt++;
	}
	cout << cnt << "\n";

	return 0;
}


/*
aaba

aaab
aabaaaba
*/