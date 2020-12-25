/**
 *    BOJ 10984
 *    - 내 학점을 구해줘
 *    author:  phcdream
 *    오전 3:35 2020-12-06
**/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int cSum = 0;
		double gSum = 0;
		for (int i = 0; i < N; i++)
		{
			int C;
			double G;
			cin >> C >> G;
			cSum += C;
			gSum += C * G;
		}
		cout << cSum << " " << fixed << setprecision(1) << gSum / cSum << "\n";
	}

	return 0;
}