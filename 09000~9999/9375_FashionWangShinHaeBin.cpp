#include <iostream>
#include <vector>
#include<utility>
using namespace std;

bool exist(string str, vector<pair<string, int>> vec, int& p);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t-- > 0)
	{
		int n;
		cin >> n;
		cin.ignore();
		string str[30];
		vector<pair<string, int>> vec;
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;	// 버리는 값 (의상이름)
			cin >> str;	// 의상종류
			int p;	//vector 내의 위치
			if (exist(str, vec, p))	// vector에 의상종류str이 존재하면(p 위치참조 후), true 반환 
			{
				get<int>(vec[p]) += 1;	// 존재하는 의상종류니까 count+1 하기
			}
			else
				vec.push_back(make_pair(str, 1));	// 없으면 vector에 push_back( 1은 처음추가하는 의상종류이니까 count =1)
		}

		int sum = 1;
		for (int i = 0; i < vec.size(); i++)
		{
			sum *= (get<int>(vec[i]) + 1);	// 의상종류 안고르는것 +1
		}
		cout << sum - 1 << "\n";	// 알몸 1개빼기(모두 안고른거)
	}
	return 0;
}
// vector내에 str이 존재하면 p에 위치참조 후 true 반환
bool exist(string str, vector<pair<string, int>> vec, int& p)
{
	int j;
	for (j = 0; j < vec.size(); j++)
	{
		if (str == get<string>(vec[j]))
		{
			p = j;
			return true;
		}
	}
	return false;
}