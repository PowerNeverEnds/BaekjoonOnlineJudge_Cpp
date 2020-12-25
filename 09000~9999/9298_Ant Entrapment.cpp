#include <iostream>

#define INF 1000

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		double minX=INF, minY=INF, maxX=-INF, maxY=-INF;
		for (int i = 0; i < N; i++)
		{
			double x, y;
			cin >> x >> y;
			minX = x < minX ? x : minX;
			minY = y < minY ? y : minY;
			maxX = x > maxX ? x : maxX;
			maxY = y > maxY ? y : maxY;
		}
		double area = (maxY - minY) * (maxX - minX);
		double perimeter = (maxY - minY) + (maxX - minX);
		perimeter *= 2;
		cout << fixed;
		cout.precision(9);
		cout << "Case " << t + 1 << ": Area " << area << ", Perimeter " << perimeter << "\n";
	}

	return 0;
}