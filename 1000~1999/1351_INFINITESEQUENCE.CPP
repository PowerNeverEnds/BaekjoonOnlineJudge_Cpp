#include <iostream>
using namespace std;

class A;
long long int sequence(long long int n, long long int p, long long int q, A* arr);

class A {
	long long int data;
	long long int n;
	static int size;
public:
	A(long long int d = 0) : data(d) { n=0; }	// waring 때문에 n=0추가
	long long int getData() { return data; }
	void setA(long long n, long long int d) { this->n = n; this->data = d;  size++; }
	long long int operator==(long long int op2)
	{
		return (data == op2);
	}
	long long int operator=(long long int op2)
	{
		data = op2;
		return data;
	}
	void arr(long long int n, long long data)
	{
		this->n = n;
		this->data = data;
	}
	bool find(long long int n) {
		return (this->n == n);
	}
	static int getSize() { return size; }
};

int A::size=0;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long int n, p, q;
	cin >> n >> p >> q;
	
	A *arr = new A[1001];
	arr[0].setA(0, 1);

	cout << sequence(n, p, q, arr) << "\n";

	return 0;
}

long long int sequence(long long int n, long long int p, long long int q, A* arr)
{
	long long int result;
	int i = 0;
	bool isitfind = false;
	for (i = 0;i<A::getSize(); i++)
	{
		if (arr[i].find(n) == true) {
			isitfind = true;
			break;
		}
	}
	if (isitfind==false)
		//	if (arr[n] == 0)
	{
		result = sequence((long long int)(n / p), p, q, arr) + sequence((long long int)(n / q), p, q, arr);
		arr[i].setA(n, result);
	}
	else
		result = arr[i].getData();
	return result;
}

/*
1000000000000 100000000 1000000000
*/