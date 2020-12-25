/*
map사용	:	168ms
sort사용	:	348ms

입력받고 한번에 정렬하는게 적게 걸릴줄알았는데
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void useMap()
{
	int N, M;
	cin >> N >> M;
	map<string, int> m;
	string* arr = new string[200000]();
	string* out = new string[200000]();

	string tStr;
	for (int i = 0; i < N; i++)
	{
		cin.ignore();
		cin >> tStr;
		arr[i] = tStr;
		m[tStr] = i + 1;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> tStr;
		if (isdigit(tStr[0]))
		{
			out[i] = arr[stoi(tStr) - 1];
		}
		else
		{
			out[i] = to_string(m[tStr]);
		}
	}
	for (int i = 0; i < M; i++)
	{
		cout << out[i] << "\n";
	}
}


struct MyStruct
{
	string str="";
	int n=0;
};
int find(const vector<MyStruct>& sortedArr, string tStr)
{
	int left, right;
	left = 0;
	right = sortedArr.size();
	int mid=0;
	while (true)
	{
		if (left > right)
			break;
		mid = (left + right) / 2;

		if (sortedArr[mid].str == tStr)
		{
			return sortedArr[mid].n;
		}
		else if (sortedArr[mid].str < tStr)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return sortedArr[mid].n;
}
void useSort()
{
	int N, M;
	cin >> N >> M;
	vector<MyStruct> sortedArr;
	string* arr = new string[200000]();
	string* out = new string[200000]();

	string tStr;
	for (int i = 0; i < N; i++)
	{
		cin.ignore();
		cin >> tStr;
		arr[i] = tStr;
		MyStruct* tms = new MyStruct;
		tms->str = tStr;
		tms->n = i+1;
		sortedArr.push_back(*tms);
	}
	sort(sortedArr.begin(), sortedArr.end(), [](auto a, auto b) {
		return a.str < b.str;
		});
	//cout << sortedArr.back().str << "\n";
	for (int i = 0; i < M; i++)
	{
		cin.ignore();
		cin >> tStr;
		if (isdigit(tStr[0]))
		{
			out[i] = arr[stoi(tStr) - 1];
		}
		else
		{
			out[i] = to_string(find(sortedArr,tStr));
		}
	}
	for (int i = 0; i < M; i++)
	{
		cout << out[i] << "\n";
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	useMap();
	//useSort();

	return 0;
}