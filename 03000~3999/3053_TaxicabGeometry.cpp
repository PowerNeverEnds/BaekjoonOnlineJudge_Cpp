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
	// �ý� �����п����� �Ÿ��� x�� y�� ����(��, �밢���̾ƴ� x�Ǵ� y�࿡ �����ϰ� ���� ����)
	// ������� �� �������� �߽ɿ��� ���������� �Ÿ��� 1
	cout << pow(r,2)*2 << "\n";

	return 0;
}