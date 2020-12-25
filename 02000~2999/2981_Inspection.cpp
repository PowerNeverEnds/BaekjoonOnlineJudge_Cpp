#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int arr[100] = { 0, };
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int minDifferenceValue = 1000000000;	// 어떤 모든 두 값의 차이 중 제일 작은 값
	//int minValue = 1000000000;	// 입력받은 arr 값들중 제일 작은 값
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (minDifferenceValue > abs(arr[i] - arr[j]))
			{
				minDifferenceValue = abs(arr[i] - arr[j]);
			}
		}
		//if (minValue > arr[i])
		//{
		//	minValue = arr[i];
		//}
	}

	cout << minDifferenceValue << "\n";

	stack<int> stack;
	for (int i = 1; i * i <= minDifferenceValue; i++)
	{
		//if (i > minValue)
		//	break;
		if (minDifferenceValue % i == 0)
		{
			if(i!=1)
				cout << i << " ";
			if(i*i!= minDifferenceValue)
				stack.push(minDifferenceValue / i);
		}
	}
	while (!stack.empty())
	{
		//if (stack.top() > minValue)
		//	break;
		cout << stack.top() << " ";
		stack.pop();
	}
	return 0;
}