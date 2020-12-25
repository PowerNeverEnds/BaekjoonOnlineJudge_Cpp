#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	getline(cin, str);

	int* arr = new int[100001];
	for (int i = 0; i < 100001; i++)
		arr[i] = -1;
	int pArr = 0;
	int count = 0;
	int bar = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
			arr[pArr++] = 0;
		else if (str[i] == ')')
		{
			if (arr[--pArr] == 0)
			{
				arr[pArr++] = 1;
			}
			else
			{
				int sum = 0;
				do
				{
					sum += arr[pArr];

				} while (arr[--pArr] != 0);
				arr[pArr++] = sum;
				count += sum;
				bar++;
			}
		}
	}
	cout << count +bar<< "\n";

	return 0;
}
/*
()(((()())(())()))(())
*/



/*
#include <iostream>
#include <string>
#define PRINT false
using namespace std;

int ironBar(int& dimension, string str, int& point,int& laserCross, int& bar);

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string str;
	

	getline(cin, str);
//	if (PRINT) {
//		for (int i = 0; i < str.length(); i++)
//			cout << i % 10;
//		cout << "\n";
//	}
	int bar=0;	// 실제 처음 bar의 개수
	int laserCross=0;	// bar에 지나간 laser의 횟수
	int point=0;
	int dimenstion = 0;
	while (point <= str.length())
	{
//		if(PRINT)cout << point << " " << str.length() << "\n";
		int count = 0;
		count = ironBar(dimenstion, str, point, laserCross, bar);
		laserCross -= count;
//		if(PRINT)cout <<"main count "<< count << "\n";
	}
//	if(PRINT)cout <<"\nlaserCross: "<< laserCross << " bar: " << bar << "\n";
	cout << laserCross + bar << "\n";

	return 0;
}

int ironBar(int& dimension, string str, int& point, int& laserCross, int& bar)
{
	int count = 0;
	while (1)
	{
//		if (PRINT)cout << dimension << " " << point << " " << str[point] <<" count"<<count<<" laser"<<laserCross<< "\n";
		if (str[point] == '(')
		{
			if (str[point + 1] == ')')
			{
//				if (PRINT)cout << "laser" << "\n";
				point += 2;
				if (dimension == 0)
					return 0;
				else
				{
					if (str[point] == ')')
					{
//						if (PRINT)cout << "maybe out" << "\n";
						++count;
					}
					else
						count++;
				}
			}
			else
			{
//				if (PRINT)cout << "into" << "\n";
				point += 1;
				int temp;
				temp= ironBar(dimension+=1, str, point,laserCross, ++bar);
//				if (PRINT)cout << "before count" << count << "\n";
				count += temp;
//				if (PRINT)cout << "intocout " << count << "\n";
			}
		}
		else
//		else if (str[point] == ')')
		{
//			if (PRINT)cout << "out" << "\n";
			//dimension -= 1;
			point += 1;
//			if (PRINT)cout << "outcount" << count << "\n";
			laserCross += count;
			dimension--;
			return count;
		}
	}
}
*/
/*

((()())(())())

*/
