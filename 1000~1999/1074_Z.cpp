#include <iostream>
using namespace std;

class Point;
int findZ(int n, Point myP, Point& visitP);
int pow(int n, int m);
class Point {
public:
	int r, c;
public:
	Point(int a, int b) :r(a), c(b) { ; }
	bool operator==(Point op2) {
		if (this->r == op2.r && this->c == op2.c)
			return true;
		else
			return false;
	}
	Point operator+(int op2) {
		Point temp(this->r, this->c);
		temp.r += op2;
		temp.c += op2;
		return temp;
	}
	bool operator<=(Point op2) {
		if (this->r <= op2.r && this->c <= op2.c)
			return true;
		else
			return false;
	}
	bool operator<=(Point* op2) {
		if (this->r <= op2->r && this->c <= op2->c)
			return true;
		else
			return false;
	}
	void print() { cout << "(" << r << " " << c << ")\n"; }

};
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, r, c;
	cin >> n >> r >> c;
	Point myP(r, c);
	Point visitP(0, 0);
	cout << findZ(n, myP, visitP) << "\n";
	return 0;
}

int findZ(int n, Point myP, Point& visitP)
{
	if (n == 1)
	{
		if (myP == visitP)
			return 0;
		else if (visitP <= myP && myP <= visitP + 1)
		{
			if (myP.r == visitP.r)
				return 1;
			else if (myP.c == visitP.c)
				return 2;
			else
				return 3;

		}
		else
			return 4;
	}
	else {
		Point t(pow(2, n), pow(2, n));
		if (visitP <= myP && (myP <= (visitP + pow(2, n))))
		{
			//myP.print();
			//visitP.print();
			//cout << "pown-1: " << pow(2, n - 1) << "\n";
			if ((myP.r <= visitP.r + pow(2, n - 1)-1) && (myP.c <= visitP.c + pow(2, n - 1)-1))
			{
				//cout << "dd0" << "\n";
				return findZ(n - 1, myP, visitP);
			}
			if (myP.r <= visitP.r + pow(2, n - 1)-1)
			{
				//cout << "dd1" << "\n";
				visitP.c += pow(2, n - 1);
				return pow(pow(2, n), 2) / 4 + findZ(n - 1, myP, visitP);
			}
			else if (myP.c <= visitP.c + pow(2, n - 1)-1)
			{
				//cout << "dd2" << "\n";
				visitP.r += pow(2, n - 1);
				return pow(pow(2, n), 2) / 4 * 2 + findZ(n - 1, myP, visitP);
			}
			else
			{
				//cout << "dd3" << "\n";
				visitP.r += pow(2, n - 1);
				visitP.c += pow(2, n - 1);
				return pow(pow(2, n), 2) / 4 * 3 + findZ(n - 1, myP, visitP);
			}
		}
		return pow(pow(2, n), 2) / 4 * 4 + findZ(n - 1, myP, visitP);

	}
}

int pow(int n, int m)
{
	int sum = 1;
	for (int i = 0; i < m; i++)
		sum *= n;
	return sum;
}