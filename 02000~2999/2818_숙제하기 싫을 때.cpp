#include <iostream>

typedef unsigned long long ull;

using namespace std;

class MyClass
{
public:
	int front;	// 하늘쪽
	int back;	// 종이쪽
	int up;		// 표의 위쪽
	int down;	// 표의 아래쪽
	int left;
	int right;
	void rollsRight() {
		int t = front;
		front = left;
		left = back;
		back = right;
		right = t;
	};
	void rollsLeft() {
		int t = front;
		front = right;
		right = back;
		back = left;
		left = t;
	};
	void rollsDown() {
		int t = front;
		front = up;
		up = back;
		back = down;
		down = t;
	};
	int rollsOne() {
		return front + left + right + back;
	}
};

int main()
{
	MyClass mc;
	mc.front = 1;
	mc.back = 6;
	mc.up = 5;
	mc.down = 2;
	mc.left = 4;
	mc.right = 3;

	int R, C;
	cin >> R >> C;
	ull sum = 0;
	for (int i = 0; i < R; i++)
	{
		int cnt = C / 4;
		if (cnt >= 1)
		{
			sum += mc.rollsOne() * cnt;
			if (i % 2 == 0)
				mc.rollsLeft();
			else
				mc.rollsRight();
			sum -= mc.front;
		}
		// -1: 마지막칸에서 돌리지 않음.	(cnt!=0): 4번돌리기했으면 돌려야함.
		for (int j = 0; j < C % 4 + (cnt != 0) - 1; j++)
		{
			sum += mc.front;
			if (i % 2 == 0)
				mc.rollsRight();
			else
				mc.rollsLeft();
		}
		sum += mc.front;
		mc.rollsDown();
	}
	cout << sum << "\n";

	return 0;
}