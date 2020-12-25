/**
 *    BOJ 2407
 *    - 조합
 *    author:  phcdream
 *    created: 오전 3:01 2020-12-04
**/
/*
https://jaimemin.tistory.com/1076
*/

/*
nCm=n!/(n-m)!m!
nCm=nCn-m
nCm=(n*n-1*n-2...2*1)/((n-m*n-m-1*...2*1)*(m*m-1*m-2*...2*1))
5C2=5*4*3*2*1/3*2*1*2*1=5*4/2*1
nCm=n-1Cm-1+n-1Cm
=4C1+4C2=4!/3!1!+4!/2!2!

nCm=n-1Cm-1+n-1Cm
kCk=1
nC0=1
*/

#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

template <typename T>
T myMax(T a, T b);

struct MyInt
{
	string str;
	MyInt operator+(const MyInt& mi)  {
		MyInt tmi{ myAdd(str, mi.str) };
		//cout << tmi.str << "\n";
		return tmi;
	}
	//bool operator==(const MyInt& mi)const {
	//	return str == str;
	//}
	string myAdd(string str1, string str2)
	{
		string tStr(myMax(str1.length(),str2.length()),'0');
		bool carry = false;
		//cout << str1 << " " << str2 << "\n";
		for (int i = 0; i < tStr.length(); i++)
		{
			//cout <<i<<" "<< tStr << "\n";
			int sum = 0;
			if (carry == true)
			{
				sum = 1;
				carry = false;
			}
			//cout << "ok?" << "\n";
			//cout << str1.length() - 1 - i << " " << str2.length() - 1 - i << "\n";
			if(0<=(ll)str1.length()-1-i)
				sum += str1[str1.length() - 1 - i] - '0';
			if (0<=(ll)str2.length() - 1 - i )
				sum += str2[str2.length() - 1 - i] - '0';
			//cout << "yes" << "\n";
			if (10 <= sum)
			{
				carry = true;
				sum -= 10;
			}
			tStr[tStr.length() - 1 - i] = sum + '0';
		}
		if (carry == true)
		{
			tStr.insert(tStr.begin(), '1');
		}
		//cout << tStr << "\n";
		return tStr;
	}
};

template <typename T>
T myMax(T a, T b)
{
	return a >= b ? a : b;
}

MyInt combi(int n, int m, MyInt**& miMem)
{
	if (miMem[n][m].str!="")
		return miMem[n][m];
	if (n == m || m==0)
		return MyInt{ "1" };
	return miMem[n][m] = combi(n - 1, m - 1,miMem) + combi(n - 1, m,miMem);
}

string solve(int n, int m)
{
	MyInt** miMem;
	miMem = new MyInt * [(ll)n+1];
	for (int i = 0; i < n + 1; i++)
	{
		miMem[i] = new MyInt[m + 1];
		fill(miMem[i], miMem[i] + m + 1, MyInt{ "" });
	}
	MyInt re = combi(n, m,miMem);

	return re.str;
}

int main()
{
	int n, m;
	cin >> n >> m;
	
	string re = solve(n, m);
	cout << re << "\n";

	return 0;
}