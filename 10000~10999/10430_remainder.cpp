#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a + b) % c << endl;
	cout << (a % c + b % c) % c << endl;
	cout << (a * b) % c << endl;
	cout << (a % c * b % c) % c << endl;
	return 0;
}

/*

A%C = a
B%C = b
A = C*n + a
B = C*m + b
(A+B)%C = (C(n+m)+a+b)%C
=(C(n+m)+A%C+B%C)%C
=(A%C+B%C)%C	// �����յ�
.
�����յ�
A�յ�B(mod m)
a mod m = b mod m
a=b+km �������Ҷ�

*/