/*
https://www.acmicpc.net/board/view/55526

입력
3 7
a e i o u b c

정답
abc
bce
bci
bco
bcu
*/


#include <iostream>
#include <algorithm>

typedef long long ll;

#define VOWEL_SIZE 5

using namespace std;

void dfs(char* arr, int* visited, int depth, int ind, int L, int C, char* vowel)
{
	if (depth > L)
	{
		int cntVowel = 0;
		for (int i = 1; i <= L; i++)
		{
			for (int j = 0; j < VOWEL_SIZE; j++)
			{
				if (arr[visited[i]] == vowel[j])
				{
					cntVowel++;
					break;
				}
			}
		}
		if (cntVowel>=1 && L-cntVowel>=2)
		{
			for (int i = 1; i <= L; i++)
			{
				cout << arr[visited[i]];
			}cout << "\n";
		}

		return;
	}
	for (int i = ind; i <= C; i++)
	{
		//cout << ind << "\n";
		visited[depth] = i;
		dfs(arr, visited, depth + 1, i + 1, L, C, vowel);
		//visited[i]=
	}
}

int main()
{
	int L, C;
	cin >> L >> C;

	char* arr = new char[(ll)C + 1];
	fill(arr, arr + C + 1, NULL);
	for (int i = 1; i <= C; i++)
		cin >> arr[i];
	sort(arr + 1, arr + C + 1, [](auto a, auto b) {
		return a < b;
		});
	char vowel[5] = { 'a','e','i','o','u' };

	int* visited = new int[(ll)C + 1];
	fill(visited, visited + C + 1, 0);

	dfs(arr, visited, 1, 1, L, C, vowel);
	return 0;
}

/*
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int L, C;
	cin >> L >> C;

	string str = "";
	for (int i = 0; i < C; i++)
	{
		char ch;
		cin >> ch;
		str += ch;
	}
	do
	{
		cout << str.substr(0,L) << "\n";
	} while (next_permutation(str.begin(),str.end()));

	return 0;
}
*/