#include <iostream>
#include <string>
#include <vector>
#include <queue>

typedef long long ll;

#define ALPHA_SIZE 26

using namespace std;

struct MyStruct
{
public:
	string str;
	bool alpha[ALPHA_SIZE] = { 0, };
	int cnt = 0;
};

// o�� 1�� ���� x�� ����ϰ� �־����� ����ǰ�, o�� 2�� ���� x�� �ذ� �־����� ����ȴ�.
// ����Ǳ⶧���� ���Ե� �����϶�, 1�϶� e.cnt++ 2�϶� e.cnt--
// e.cnt�� 0�϶�. ��, �������ڰ� ������, cnt++
int setV(vector<MyStruct>& vec, int x, bool* posiArr, bool posi)
{
	int cnt = 0;
	posiArr[x - 'a'] = posi;
	for (auto& e : vec)
	{
		if (e.alpha[x - 'a'] == true)
		{
			if (posi == true)
			{
				e.cnt--;
			}
			else if (posi == false)
			{
				e.cnt++;
			}
		}
		if (e.cnt == 0)
			cnt++;
	}
	return cnt;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<string> strVec;
	vector<MyStruct> vec;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin.ignore();
		cin >> str;
		strVec.push_back(str);
	}

	for (auto e : strVec)
	{
		vec.push_back(MyStruct());
		vec.back().str = e;
		for (int i = 0; i < ALPHA_SIZE; i++)
		{
			if (e.find('a' + i) != string::npos)
			{
				vec.back().alpha[i] = true;
			}
		}
	}

	bool posiArr[ALPHA_SIZE];
	fill(posiArr, posiArr + ALPHA_SIZE, true);

	for (int i = 0; i < M; i++)
	{
		int o;
		char x;
		cin >> o >> x;
		int cnt = 0;
		switch (o)
		{
		case 1:
			cnt = setV(vec, x, posiArr, false);
			//cout << cnt << "\n";
			break;
		case 2:
			cnt = setV(vec, x, posiArr, true);
			//cout << cnt << "\n";
			break;
		default:
			break;
		}
		//cout << "ans ";
		cout << cnt << "\n";
	}

	return 0;
}