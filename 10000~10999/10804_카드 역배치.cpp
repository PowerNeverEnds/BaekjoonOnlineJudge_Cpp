/**
 *    BOJ 10804
 *    - 카드 역배치
 *    author:  phcdream
 *    created: 오전 5:41 2020-12-07
**/

/*
solve1
*/
#include <iostream>

using namespace std;

void mySwap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void myIterSwap(int* a, int* b)
{
	//cout << a << "\n";
	mySwap(*a, *b);
	//cout << a << "\n";
}


void myReverse(int* left, int* right)
{
	while ((left != right) && (left != --right))
	{
		//cout << left<<" "<<*left <<" "<<*right<< "\n";
		myIterSwap(left++, right);
		//cout << left<<" "<<*left <<" "<<*right<< "\n";
	}
}

void solve1()
{
	int arr[21];
	for (int i = 1; i <= 20; i++)
		arr[i] = i;

	for (int i = 0; i < 10; i++)
	{
		int a, b;
		cin >> a >> b;
		//cout <<"for "<< arr[a] <<" "<<a<< "\n";
		myReverse(&arr[a], &(arr[b + 1]));
		//cout << arr[a] <<" "<<a<< "\n";
	}

	for (int i = 1; i <= 20; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

#include <algorithm>
void solve2()
{
	int arr[21];
	for (int i = 1; i <= 20; i++)
		arr[i] = i;

	for (int i = 0; i < 10; i++)
	{
		int a, b;
		cin >> a >> b;
		reverse(&arr[a], &(arr[b + 1]));
	}

	for (int i = 1; i <= 20; i++)
		cout << arr[i] << " ";
	cout << "\n";

}
int main()
{
	solve1();
	//solve2();

	return 0;
}
