#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

class MyClass
{
public:
	MyClass(string d = nullptr) :data(d) { ; };
	string data;
	int digitSum() { 
		int sum = 0;
		for (auto e : data)
			if (isdigit(e))
				sum += e - '0';

		return sum;
	};
	bool operator<(MyClass& B) {
		if (this->data.length() == B.data.length())
		{
			if (this->digitSum() == B.digitSum())
				return this->data < B.data;
			return this->digitSum() < B.digitSum();
		}
		return this->data.length() < B.data.length();
	};

};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<MyClass> vec;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin.ignore();
		cin >> str;
		vec.push_back(str);
	}

	sort(vec.begin(), vec.end(), [](auto a, auto b) {
		return a < b;
		});

	for (auto e : vec)
		cout << e.data << "\n";

	return 0;
}