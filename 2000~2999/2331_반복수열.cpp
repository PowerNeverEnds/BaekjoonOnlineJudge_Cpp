/**
 *    BOJ 2331
 *    - 반복수열
 *    author:  phcdream
 *    created: 오전 6:16 2020-12-05
**/

#include <iostream>
#include <vector>

using namespace std;

int myPow(int A, int P)
{
	int sum = 1;
	for (int i = 0; i < P; i++)
	{
		sum *= A;
	}
	return sum;
}

int D(int A, int P)
{
	int sum = 0;
	while (A)
	{
		sum += myPow((A % 10), P);
		A /= 10;
	}
	return sum;
}

int main()
{
	vector<int> vec;
	int A, P;
	cin >> A >> P;
	vec.push_back(A);
	while (true)
	{
		vec.push_back(D(A, P));
		A = vec.back();
		//cout << vec.back() << "\n";
		for (int i = 0; i < vec.size() - 1; i++)
		{
			if (vec[i] == vec[vec.size() - 1])
			{
				cout << i << "\n";
				return 0;
			}
		}
	}
	return 0;
}