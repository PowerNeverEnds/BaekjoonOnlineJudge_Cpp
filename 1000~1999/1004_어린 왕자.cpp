#include <iostream>

using namespace std;

struct Point
{
	int y;
	int x;
};

struct Planet
{
	Point point;
	int r;
};

int myPow(int a)
{
	return a * a;
}

bool isContain(Planet pl, Point po)
{
	int dis = 0;
	int pX, pY, pR;
	pX = pl.point.x;
	pY = pl.point.y;
	pR = pl.r;
	dis = myPow((pX - po.x)) + myPow((pY - po.y));

	if (myPow(pR) > dis)
		return true;
	else
		return false;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{

		Point st, end;
		cin >> st.x >> st.y >> end.x >> end.y;
		int n;
		cin >> n;

		Planet* planet = new Planet[n];
		//fill(planet, planet + n, nullptr);
		for (int i = 0; i < n; i++)
		{
			int x, y, r;
			cin >> x >> y >> r;
			planet[i].point.x = x;
			planet[i].point.y = y;
			planet[i].r = r;
		}

		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (isContain(planet[i],st) ^ isContain(planet[i],end))
				cnt++;

		cout << cnt << "\n";
	}

	return 0;
}