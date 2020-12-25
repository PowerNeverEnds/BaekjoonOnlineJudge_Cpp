#include <iostream>
#include <algorithm>
using namespace std;

class Point {
	int x, y;
public:
	Point(int a=0, int b=0) :x{ a }, y{ b }{; }
	void setPoint(int a, int b)
	{
		x = a;
		y = b;
	}
	friend bool upGreater(Point op1, Point op2);
	void print()
	{
		cout << x << " " << y << "\n";
	}
};

bool upGreater(Point op1, Point op2)
{
	if (op1.x == op2.x)
		return op1.y < op2.y;
	else
		return op1.x < op2.x;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	Point* point = new Point[n];
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		point[i].setPoint(x, y);
	}
	sort(&point[0], &point[n], upGreater);
	for (int i = 0; i < n; i++)
	{
		point[i].print();
	}
	return 0;
}