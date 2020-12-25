/**
 *    BOJ 2460
 *    - 지능형 기차 2
 *    author:  phcdream
 *    created: 오전 4:13 2020-12-21
**/

#include <iostream>

using namespace std;

int main()
{
	int sum = 0;
	int max = 0;
	for (int i = 0; i < 10; i++)
	{
		int out, in;
		cin >> out >> in;
		sum += -out + in;
		max = sum > max ? sum : max;
	}
	cout << max << "\n";

	return 0;
}