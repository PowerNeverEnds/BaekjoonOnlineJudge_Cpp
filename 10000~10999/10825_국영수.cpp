#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct MyStudent
{
	string name;
	int ko;
	int en;
	int ma;
	void print() {
		cout << name << "\n";
	}
	bool operator<(MyStudent& ms) {
		if (ko == ms.ko)
			if (en == ms.en)
				if (ma == ms.ma)
					return name < ms.name;
				else
					return ma > ms.ma;
			else
				return en < ms.en;
		else
			return ko > ms.ko;
	}
};

int main()
{
	int N;
	cin >> N;
	vector<MyStudent> vec;
	for (int i = 0; i < N; i++)
	{
		string name;
		int ko, ma, en;
		cin.ignore();
		cin >> name;
		cin >> ko >> ma >> en;
		vec.push_back(MyStudent({ name,ko,ma,en }));
	}

	sort(vec.begin(), vec.end(), [](auto a, auto b)
		{
			return a < b;
		});

	for (auto e : vec)
	{
		e.print();
	}

	return 0;
}