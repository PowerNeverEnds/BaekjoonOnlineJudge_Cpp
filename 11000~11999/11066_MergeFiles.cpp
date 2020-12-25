#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t-- > 0)
	{
		int k;
		cin >> k;
		int* arr = new int[k];
		int size = k;
		for (int i = 0; i < k; i++)
		{
			cin >> arr[i];
		}
		int answerSum = 0;
		while (size > 1)
		{
			for (int i = 0; i < size; i++)
			{
				cout << arr[i] << " ";
			}
			cout << "\n";
			int smallTwoSum = 20001;
			int p = 0;
			for (int i = 0; i < size - 1; i++)
			{
				int t = arr[i] + arr[i + 1];
				if (smallTwoSum > t)
				{
					smallTwoSum = t;
					p = i;
				}
			}
			arr[p] = smallTwoSum;
			for (int i = p + 1; i < size - 1; i++)
			{
				arr[i] = arr[i + 1];
			}
			answerSum += smallTwoSum;
			size--;
		}
		cout << answerSum << "\n";
	}

	return 0;
}



// Á¤·Ä ÇØº­·ÈÀÚ³Ê~
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int mergeAndInsert(int* arr, int& size);
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	int t;
//	cin >> t;
//	while (t-- > 0)
//	{
//		int k;
//		cin >> k;
//		int* arr = new int[k];
//		int size = k;
//		for (int i = 0; i < k; i++)
//		{
//			cin >> arr[i];
//		}
//		sort(&arr[0], &arr[size]);
//		for (int i = 0; i < size; i++)
//		{
//			cout << arr[i] << " ";
//		}
//		cout << "\n";
//		int sum = 0;
//		while (size >= 2)
//		{
//			cout << sum << " ";
//			sum+=mergeAndInsert(arr, size);
//			for (int i = 0; i < size; i++)
//			{
//				cout << arr[i] << " ";
//			}
//			cout<< "\n";
//		}
//		cout << sum << "\n";
//	}
//
//	return 0;
//}
//int mergeAndInsert(int* arr, int& size)
//{
//	int t;
//	t = arr[0] + arr[1];
//	cout << t << " ";
//	int begin = 2;
//	int end = size - 1;
//	int p = (begin + end) / 2;
//	while (true)
//	{
//		p = (begin + end) / 2;
//		if (t < arr[p])
//		{
//			end = p - 1;
//		}
//		else if (arr[p] < t)
//		{
//			begin = p + 1;
//		}
//		else
//		{
//			break;
//		}
//		if (begin > end)
//		{
//			p = (begin + end) / 2;
//			break;
//		}
//	}
//	cout << p << " ";
//	for (int i = 0; i < p - 1; i++)
//	{
//		arr[i] = arr[i + 2];
//	}
//	arr[p - 1] = t;
//	for (int i = p; i < size-1; i++)
//	{
//		arr[i] = arr[i + 1];
//	}
//	size--;
//	cout << "\t";
//	return t;
//}