#include <iostream>
#include <string>
#include <vector>

typedef long long ll;

#define MAX ((ll)1e11)

using namespace std;

void dfs(char* chOper, bool* visited, int* arr, int depth, int ind, int k, string& min, string& max)
//void dfs(bool* bOper, bool* visited, int* arr, int depth, int ind, int k)
{
	if (depth > k + 1)
	{
		//for (int i = 1; i <= k + 1; i++)
		//{
		//	cout << arr[i] << " ";
		//}cout << "\n";
		bool isTrue = true;
		for (int i = 1; i <= k; i++)
		{
			if (chOper[i] == '<')
			{
				if (arr[i] < arr[i + 1])
					;
				else
					isTrue = false;
			}
			if (chOper[i] == '>')
			{
				if (arr[i] > arr[i + 1])
					;
				else
					isTrue = false;
			}
		}
		//cout << isTrue << "\n";
		if (isTrue == true)
		{
			string sum = "";
			for (int i = 1; i <= k + 1; i++)
			{
				//sum.push_back(char(arr[i] + '0'));
				sum += arr[i] + '0';
				//cout << sum << " ";
				//cout << char(arr[i]+'0') << " ";

			}
			max = sum > max ? sum : max;
			min = sum < min ? sum : min;
			cout << sum << "\n";
			//cout << max << " " << min << "\n";
		}

		return;
	}
	for (int i = 0; i < 10; i++)
	{
		bool isUse = false;
		for (int j = 0; j < 10; j++)
		{
			if (visited[i] == true)
				isUse = true;
		}
		if (isUse == true)
			continue;
		visited[i] = true;
		arr[depth] = i;
		dfs(chOper, visited, arr, depth + 1, ind, k, min, max);
		visited[i] = false;
	}
}

int main()
{
	int k;
	cin >> k;
	char* chOper = new char[(ll)k + 1];
	//bool* bOper = new bool [(ll)k];
	for (int i = 1; i <= k; i++)
	{
		char ch;
		cin >> ch;
		chOper[i] = ch;
		//if (ch == '<')
		//	bOper[i] = 0;
		//else
		//	bOper[i] = 1;
	}

	bool* visited = new bool[(ll)10];
	int* arr = new int[(ll)k + 2];
	fill(visited, visited + 10, false);

	//dfs(bOper, visited, arr, 1, 1, k);
	string min = "9999999999";
	string max = "0";
	dfs(chOper, visited, arr, 1, 1, k, min, max);

	cout << max << "\n";
	cout << min << "\n";

	return 0;
}