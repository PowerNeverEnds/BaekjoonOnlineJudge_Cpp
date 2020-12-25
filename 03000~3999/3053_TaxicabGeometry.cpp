#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define PI 3.141592653589793238

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	const double pi = acos(-1.0);
	cout << fixed << setprecision(20) << pi << "\n";
	cout << fixed  << PI << "\n";
	double r;
	cin >> r;

	cout << fixed << PI * pow(r, 2) << "\n";
	// 택시 기하학에서의 거리는 x와 y의 차이(즉, 대각선이아닌 x또는 y축에 평행하게 그은 직선)
	// 마름모꼴 ◇ 마름모의 중심에서 꼭짓점까지 거리가 1
	cout << pow(r,2)*2 << "\n";

	return 0;
}