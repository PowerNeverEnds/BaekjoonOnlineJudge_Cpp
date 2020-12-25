#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, sum=0, score, max=-1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> score;
		sum += score;
		if (max < score)
			max = score;
	}
	cout <<fixed<<setprecision(10)<< sum * 100.0 / max / n << "\n";
	return 0;
}