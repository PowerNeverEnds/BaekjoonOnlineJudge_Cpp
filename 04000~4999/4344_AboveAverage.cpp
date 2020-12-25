#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int c;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		int n,sum=0;
		cin >> n;
		int *score = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin >> score[j];
			sum += score[j];
		}
		double avg = 1.0 * sum / n;
		int count=0;
		for (int j = 0; j < n; j++)
		{
			if (score[j] > avg)
			{
				count++;
			}
		}
		int answer=((double)count/n*1000000+5)/10;
		cout <<fixed<<setprecision(3)<< (double)answer/1000 << "%\n";
		delete[] score;
	}
	return 0;
}