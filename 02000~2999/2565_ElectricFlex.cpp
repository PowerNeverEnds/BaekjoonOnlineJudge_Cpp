/*
1.�˰���
.ù��° �����뿡 ����� �������� �ι�° ��ȣ�� ����,
.LIS ����
2.�˰���
.ù��° �����뿡 �����ϴ� �������� ����,
.ū ������� ����(������ �����ϴ� �������� (�����ϴ°�����) �� ������ ����)
��:x�� ������,:�����ϴ������ٹ�ȣ
1��: 3 4 7 �� 3��,2�� 2��1�� 7�� 3�� -> 6��
7��: 1 2 3 �� 3+2+2=7��
3��: 1 2 7 �� 3+2+3=8��
2��: 3 7
4��: 1
1�� 6��, 7��7�� 3��8���̱⶧���� 1�����ͻ���

*/
/*
8
1 8
3 9
2 2
4 1
6 4
10 10
9 7
7 6

16
1 0
2 8
3 4
4 12
5 2
6 10
7 6
8 14
9 1
10 9
11 5
12 13
13 3
14 11
15 7
16 15

*/
// 20200528 ����¥�� �� �˰����̶� �������
// �������� ���ִ°� �ƴ�, �´� ������ �����ؼ� ��ġ�ϱ�
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr1[500];
	int arr2[500];
	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i] >> arr2[i];
	}
	int arr[501] = { 0, };	// arr[������ 1��] = ������2��(1���� ����� 2��������) ��) arr[0]=8, arr[3]=9
	for (int i = 0; i < n; i++)
	{
		arr[arr1[i]] = arr2[i];
	}
	int d[501] = { 0, };
	for (int i = 0; i < 501; i++)
	{
		d[i] = 501;
	}
	int dSize = 0;
	for (int i = 0; i < 501; i++)
	{
		int j=dSize;
		for (j = dSize; j >= 0; j--)
		{
			if (arr[i] > d[j])
			{
				break;
			}
		}
		if (j == dSize)
			dSize++;
		d[j+1] = arr[i];
	}
	//for (int i = 0; i < 11; i++)
	//{
	//	cout << arr[i] << " ";
	//}
	//cout << "\n";
	cout << n - dSize << "\n";
	return 0;
}


//
// �˰��� 1�� Ǯ��

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	return 0;
//}




// �˰��� 2�� Ǯ��( Ʋ�Ƚ��ϴ�!!)
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//bool upToDown(int* a, int* b);
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	int n;
//	cin >> n;
//	int** arr = new int*[500];
//	for (int i = 0; i < 500; i++)
//	{
//		arr[i] = new int[2];
//		for (int j = 0; j < 2; j++)
//		{
//			arr[i][j] = -1;
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i][0] >> arr[i][1];
//	}
//	int** cross = new int* [501];
//	for (int i = 0; i < 501; i++)
//	{
//		cross[i] = new int[501];
//		for (int j = 0; j < 501; j++)
//		{
//			cross[i][j] = -1;
//		}
//	}
//	int* size = new int[501];
//	for (int i = 0; i < 501; i++)
//	{
//		size[i] = 0;
//	}
//	for (int i = 0; i < 500; i++)
//	{
//		for (int j = 0; j < 500; j++)
//		{
//			if (arr[i][0] > arr[j][0] && arr[i][1] < arr[j][1])
//			{
//				int y = arr[i][0];
//				cross[y][size[y]++] = arr[j][0];
//			}
//			if (arr[i][0] < arr[j][0] && arr[i][1] > arr[j][1])
//			{
//				int y = arr[i][0];
//				cross[y][size[y]++] = arr[j][0];
//			}
//		}
//	}
//	//for (int i = 0; i < 11; i++)
//	//{
//	//	for (int j = 0; j < 11; j++)
//	//	{
//	//		cout<<cross[i][j]<<" ";
//	//	}
//	//	cout << "\n";
//	//}
//	int** count = new int* [501];
//	for (int i = 0; i < 501; i++)
//	{
//		count[i] = new int[2];
//		count[i][0] = count[i][1] = 0;
//		if (size[i] != 0)
//		{
//			count[i][0] = i;
//			count[i][1] = size[i];
//		}
//	}
//	sort(&count[0], &count[501], upToDown);
//
//	//for (int i = 0; i < 11; i++)
//	//{
//	//	cout << count[i][0] << " " << count[i][1] << "\n";
//	//}
//
//	//for (int i = 0; i < 11; i++)	// 501
//	//{
//	//	int y = count[i][0];
//	//	cout << y << " ";
//	//	for (int j = 0; j < size[y]; j++)
//	//	{
//	//		cout << cross[y][j] << " ";
//	//	}
//	//	cout << "\n";
//	//}
//	int deleteCount = 0;
//	bool deleteOn = false;
//	for (int i = 0; i < 501; i++)	// 501
//	{
//		//cout <<"i:"<< i <<"\t delete: "<<deleteCount<< "\n";
//		//for (int a = 0; a < 11; a++)	// 501
//		//{
//		//	int y = count[a][0];
//		//	cout << y << " ";
//		//	for (int b= 0; b< size[y]; b++)
//		//	{
//		//		cout << cross[y][b] << " ";
//		//	}
//		//	cout <<"\t"<<count[a][1]<< "\n";
//		//}
//		int min = -1;
//		int minPosition = 0;
//		for (int o = 0; o < 501; o++)
//		{
//			if ((i+o-1)>=0)
//				if(count[i + o][1] != count[i + o - 1][1])
//					break;
//			int y = count[i + o][0];
//			int sum = 0;
//			for (int j = 0; j < size[y]; j++)
//			{
//				int yy = cross[y][j];
//				for (int k = 0; k < 501; k++)
//				{
//					if (yy == count[k][0])
//					{
//						sum += count[k][1];
//						break;
//					}
//				}
//				//cout <<o<<" "<<" "<<i<<" "<<j<< "min: " << min << "\t sum" << sum << "\n";
//
//			}
//			if (min == -1)
//				{
//					min = sum;
//					minPosition = o;
//				}
//				if (min > sum)
//				{
//					min = sum;
//					minPosition = o;
//				}
//		}
//		//cout <<"min: "<<min<< "\t minPosition: " << minPosition << "\n";
//		if (min == 0)
//			break;
//		int y = count[i+minPosition][0];
//		deleteOn = false;
//		for (int j = 0; j < size[y]; j++)
//		{
//			int yy = cross[y][j];
//			for (int k = 0; k < size[yy]; k++)
//			{
//				if (cross[yy][k] == y)
//				{
//					cross[yy][k] = cross[yy][--size[yy]];
//					for (int o = 0; o < 501; o++)
//					{
//						if (count[o][0] == yy)
//						{
//							count[o][1] = size[yy];
//							break;
//						}
//					}
//					deleteOn = true;
//					break;
//				}
//			}
//			if(deleteOn==true)
//				cross[y][j] = 0;
//		}
//		if (deleteOn == true)
//		{
//			size[y] = 0;
//			count[i+minPosition][1] = size[y];
//			//cout <<"deleteOn "<<y<<" "<< size[y] << " "<<count[y][1]<<"\n";
//			deleteCount++;
//			i--;
//		}
//			sort(&count[0], &count[501], upToDown);
//	}
//	cout << deleteCount << "\n";
//	return 0;
//}
//
//bool upToDown(int* a, int* b)
//{
//	return a[1] > b[1];
//}