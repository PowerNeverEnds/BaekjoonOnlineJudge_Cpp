#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[101] = { 0, };
	for (int i = 0; i < n; i++)
	{
		int e;
		cin >> e;
		arr[e]++;
	}
	//for (int i = 0; i < 50; i++)
	//{
	//	cout << arr[i] << " ";
	//}cout << "\n";
	int max1 = 0, max2 = 0, max3 = 0;
	int num1 = 0, num2 = 0, num3 = 0;
	for (int i = 0; i <= n; i++)
	{
		//cout << i << "\n";
		if (max1 < arr[i])
		{
			max1 = arr[i];
			num1 = i;
		}
		else if (max2 < arr[i])
		{
			max2 = arr[i];
			num2 = i;
		}
		else if (max3 < arr[i])
		{
			max3 = arr[i];
			num3 = i;
		}
		//cout << max1 << ": " << num1 << " " << max2 << ": " << num2 << " " << max3 << ": " << num3 << "\n";

	}
	if (max1 == max2 && max2 == max3)
	{
		cout << "skipped" << "\n";;
	}
	else if (num1 == 0)
	{
		if (max2 == max3)
		{
			cout << "skipped"<<"\n";
		}
		else
		{
			if (max2 > max3)
				cout << num2 << "\n";
			else if(max2 < max3)
				cout << num3 << "\n";
		}
	}
	else if (num2 == 0)
	{
		cout << num1 << "\n";
	}
	else if (num3 == 0)
	{
		if (max1 > max2)
			cout << num1 << "\n";
		else if (max1 < max2)
			cout << num2 << "\n";
		else if (max1 == max2)
			cout << "skipped" << "\n";
	}
	else
	{
		if (max1 > max2)
			cout << num1 << "\n";
		else if (max1 < max2)
			cout << num2 << "\n";
		else if (max1 == max2)
			cout << "skipped" << "\n";
	}
	return 0;
}