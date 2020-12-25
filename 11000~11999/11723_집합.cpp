#include <iostream>
#include <string>
#include <map>

#define OPER_NUM 6

using namespace std;

//map<string, int> oper = { {"add",0},{"remove",1},{"check",2},{"toggle",3},{"all",4},{"empty",5} };

int outCount = 0;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string str;
	bool arr[21];
	//bool out[10];
	string oper[OPER_NUM] = { "add","remove","check","toggle","all","empty" };

	//bool* out = new bool[3000000]();
	while (n--)
	{
		cin.ignore();
		cin >> str;
		int operNum = 0;
		int x;
		for (int i = 0; i < OPER_NUM; i++)
		{
			if (oper[i] == str)
			{
				operNum = i;
				break;
			}
		}
		switch (operNum)
		{
		case 0:
			cin >> x;
			arr[x] = true;
			break;
		case 1:
			cin >> x;
			arr[x] = false;
			break;
		case 2:
			cin >> x;
			//out[outCount++] = arr[x];
			cout << (arr[x] == true ? 1 : 0) << "\n";
			break;
		case 3:
			cin >> x;
			arr[x] = arr[x] == true ? false : true;
			break;
		case 4:
			for (int i = 0; i < 21; i++)
			{
				arr[i] = true;
			}
			break;
		case 5:
			for (int i = 0; i < 21; i++)
			{
				arr[i] = false;
			}
			break;
		}

	}
	//for (int i = 0; i < outCount; i++)
	//{
	//	cout << (out[i] == true ? 1 : 0) << "\n";
	//}
	return 0;
}