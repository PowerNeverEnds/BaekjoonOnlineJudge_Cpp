#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;

	//...................A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,T,S,T,U,V,W,X,Y,Z
	int alphabat[27] = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9 };
	int sum = 0;
	for (int i = 0; i < str.length(); i++)
	{
		sum += alphabat[str[i] - 'A'];
	}

	cout << sum + str.length() << "\n";
}