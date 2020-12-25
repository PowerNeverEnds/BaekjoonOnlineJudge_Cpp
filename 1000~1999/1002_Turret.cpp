#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t-- > 0)
	{
		double x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double distance, disX, disY;
		disX = x1 - x2;
		disY = y1 - y2;
		distance = sqrt(pow(disX, 2) + pow(disY, 2));
		
		// 외접
		if (distance == (r1 + r2))
		{
			cout << 1 << "\n";
		}
		// 동일
		else if (distance == 0 && r1 == r2)
		{
			cout << -1 << "\n";
		}
		// 내접
		else if (distance == abs(r1-r2))
		{
			cout << 1 << "\n";
		}
		// 포함(작은원이 큰원안에 들어갈 경우)
		else if (distance < abs(r1 - r2))
		{
			cout << 0 << "\n";
		}
		// 포함되지도 않으면서 만나지도 않을 경우
		else if (distance > (r1 + r2))
		{
			cout << 0 << "\n";
		}
		// 두점에서 만나는 경우
		else
		{
			cout << 2 << "\n";
		}
	}

	return 0;
}