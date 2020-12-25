#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct MyStruct
{
	int id;
	int num;
};
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int  N;
	cin >> N;
	int* arr = new int[N];
	vector<MyStruct> vec;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		arr[i] = x;
		vec.push_back(MyStruct{ i,x });
	}
	sort(vec.begin(), vec.end(), [](auto a, auto b) {
		return a.num < b.num;
		});

	int prev = vec[0].num;
	int count = 0;
	int* out = new int[N];
	
	for (int i = 0; i < N; i++)
	{
		if (prev == vec[i].num)
		{
		}
		else
		{
			count++;
		}
		out[vec[i].id] = count;
		prev = vec[i].num;
	}

	for (int i = 0; i < N; i++)
	{
		cout << out[i] << " ";
	}
	cout << "\n";

	return 0;
}