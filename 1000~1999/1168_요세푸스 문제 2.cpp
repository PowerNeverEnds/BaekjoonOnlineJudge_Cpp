#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> vec;
	for(int i=1;i<=N;i++)
		vec.push_back(i);
	string out = "<";
	
	int k = 0;
	while (true)
	{
		k += K-1;
		k %= vec.size();
		out += to_string(vec[k]);
		if (vec.size() == 1)
		{
			out +=">";
			break;
		}
		else
			out +=", ";
		vec.erase(vec.begin() + k);
	}
	cout << out << "\n";
	return 0;
}


/*
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}
	queue<int> out;
	while (true)
	{
		if (q.empty())
			break;
		for (int i = 0; i < K - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}
		out.push(q.front());
		q.pop();
	}
	cout << "<";
	while (true)
	{
		if (out.empty())
			break;
		cout << out.front();
		if (out.size() > 1)
			cout << " ,";
		else if (out.size() == 1)
			;
		out.pop();
	}
	cout << ">" << "\n";

	return 0;
}
*/