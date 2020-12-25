/*
알고리즘:
1.입력받는대로 작은거 절반 큰거절반되게 (min, max) priority_queue에 저장
2.후 출력
*/
#include <iostream>
#include <queue>
using namespace std;

void swap(int& a, int& b);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	priority_queue<int,vector<int>> maxPQ;	// 절반중작은값, (top는큰값(작은값은 계속 들어가있어야하기때문))
	priority_queue<int,vector<int>,greater<int>> minPQ;	// 절반중큰값, top는작은값
	{
		if (n == 1)
		{
			int a;
			cin >> a;
			cout << a << "\n";
			n--;	// 이거 추가( 안하면 뒤에 while문돌음)
		}
		else if (n > 1)
		{
			int a, b;
			cin >> a >> b;
			cout << a << "\n";	// 옴기면서 그냥 a 출력
			if (a < b)
			{
				swap(a, b);
			}
			maxPQ.push(b);
			minPQ.push(a);
			cout << maxPQ.top() << "\n";	// 여기있는 Cout 위로 옴김
			n -= 2;
		}
	}
	while (n-- > 0)
	{
		int number;
		cin >> number;
		if (maxPQ.top() >= number)
		{
			if (maxPQ.size() > minPQ.size())
			{
				minPQ.push(maxPQ.top());
				maxPQ.pop();
			}
			maxPQ.push(number);
		}
		else if (minPQ.top()<=number)	// 조건 변경
		{
			if (maxPQ.size() < minPQ.size())
			{
				maxPQ.push(minPQ.top());
				minPQ.pop();
			}
			minPQ.push(number);
		}
		else if (maxPQ.top() < number && minPQ.top() > number)	// 가운데값 추가
		{

			if (maxPQ.size() <= minPQ.size())
			{
				maxPQ.push(number);
			}
			else if (maxPQ.size() > minPQ.size())
			{
				minPQ.push(number);
			}
		}
		if (maxPQ.size() >= minPQ.size())
		{
			cout << maxPQ.top() << "\n";
		}
		else if (maxPQ.size() < minPQ.size())
		{
			cout << minPQ.top() << "\n";
		}
	}

	return 0;
}

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}