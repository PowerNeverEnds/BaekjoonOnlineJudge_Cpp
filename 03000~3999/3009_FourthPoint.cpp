#include <iostream>
using namespace std;

int different(int a, int b, int c);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int p[8] = { 0 , };
	for (int i = 0; i < 6; i++)
		cin >> p[i];
	cout<<different(p[0], p[2], p[4])<<" ";
	cout<<different(p[1], p[3], p[5])<<"\n";
	

	return 0;
}

int different(int a, int b, int c)
{
	//if (a != b)
	//{
	//	if (a != c)
	//	{
	//		return a;
	//	}
	//	else
	//		return b;
	//}
	//else
	//	return c;

	return a != b ? a != c ? a : b : c;
}