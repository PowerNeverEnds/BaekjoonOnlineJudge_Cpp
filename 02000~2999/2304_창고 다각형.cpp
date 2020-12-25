#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

class MyClass
{
public:
	int L;
	int H;
	MyClass(int l = 0, int h = 0) :L(l), H(h) {};
	bool operator<(MyClass& b) {
		return this->L < b.L;
	};
};

int main()
{
	int N;
	cin >> N;
	vector<MyClass> vec;
	int maxL = 0;
	int maxH = 0;
	for (int i = 0; i < N; i++)
	{
		int L, H;
		cin >> L >> H;
		vec.push_back(MyClass{ L,H });
		maxH = H > maxH ? H : maxH;
		maxL = L > maxL ? L : maxL;
	}
	sort(vec.begin(), vec.end(), [](auto a, auto b) {
		return a < b;
		});
	deque<MyClass> dq;
	for (auto e : vec)
		dq.push_back(e);

	int sum = 0;
	int max = 0;
	while (true)	// 앞부분
	{
		if (dq.front().H == maxH)
			break;
		MyClass l = dq.front();
		dq.pop_front();
		MyClass r = dq.front();
		max = l.H > max ? l.H : max;
		sum += max * (r.L - l.L);
	}

	max = 0;
	while (true)	// 뒷부분
	{
		if (dq.back().H == maxH)
			break;
		MyClass r = dq.back();
		dq.pop_back();
		MyClass l = dq.back();
		max = r.H > max ? r.H : max;
		sum += max * (r.L - l.L);
	}

	sum += maxH * (dq.back().L - dq.front().L + 1);	// 가운데

	cout << sum << "\n";

	return 0;
}


/*
#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

class MyClass
{
public:
	int L;
	int H;
	MyClass(int l = 0, int h = 0) :L(l), H(h) {};
	bool operator<(MyClass& b) {
		return this->L < b.L;
	};
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<MyClass> vec;
	int maxL = 0;
	int maxH = 0;
	for (int i = 0; i < N; i++)
	{
		int L, H;
		cin >> L >> H;
		vec.push_back(MyClass{ L,H });
		maxH = H > maxH ? H : maxH;
		maxL = L > maxL ? L : maxL;
	}
	sort(vec.begin(), vec.end(), [](auto a, auto b) {
		return a < b;
		});
	int max = 0;
	int sum = 0;
	int i = 0;
	for (i = 0;; i++)
	{
		if (vec[i].H == maxH)
			break;
		max = vec[i].H > max ? vec[i].H : max;
		sum += max * (vec[(ll)i + 1].L-vec[i].L );
	}
	for (;; i++)
	{
		if (vec[i].H != maxH)
			break;
		sum += maxH * (1);
	}
	max = 0;
	for (int j=vec.size()-1; i<=j; j--)
	{
		max = vec[j].H > max ? vec[j].H : max;
		sum += max * (vec[j].L-vec[(ll)j-1].L);
	}

	cout << sum << "\n";

	return 0;
}
*/