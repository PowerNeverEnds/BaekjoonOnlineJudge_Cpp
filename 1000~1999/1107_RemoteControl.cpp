/*
1107_RemoteControl
�˰���: 
1. ���ϴ� ä�ο��� +�� Ȥ�� -�� �ѹ� ������.
2. �� ä���� �������� ��ư���� ������ �ü��ִ� ���, minButton���̶� ��,
3. +- ��� ������ 100 ä�α��� �ö�����, 1~2�ݺ�
4. ���ϴ� ä�ο��� 100�� ä�α��� +- ��ư Ƚ�� minButton���̶� ��,
5. ���

*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int n;	// ���ϴ� ä��
	int m;	// ���峭 ��ư ����
	cin >> n >> m;
	int arr[10] = { 0, };	// broken button
	for (int i = 0; i < m; i++)
	{
		cin >> arr[i];
	}
	bool remote[10] = { 0, };	// is remote button operate?
	for (int i = 0; i < 10; i++)
	{
		remote[i] = true;	// all operate
	}
	for (int i = 0; i < m; i++)
	{
		remote[arr[i]] = false;	// broken button
	}

	int minButton = 1000000;	// ���� ���� ��ư ��
	for (int i = 0;i<500001; i++)
	{
		if ((n + i) == 100 || (n - i) == 100)	// 100 ���� �ϸ� break
			break;
		bool upMatch = true;	//  +��ư ������ �÷��� ������, (true�� ��ä�� ������ ���ڰ� ��� ����)
		int nTemp = n + i;	// n���� +��ư�� i�� ��������,
		int c = 0;	// c�� �ڸ���, ��) 345 -> c=3
		do
		{	// 0 �϶��� �ѹ��� ���� do while
			// ���ڸ����� ��ư�� �ִ��� Ȯ��
			++c;
			int nMod = nTemp % 10;
			nTemp /= 10;
			if (remote[nMod] == false)
			{
				upMatch = false;
				break;
			}
		} while (nTemp != 0);
		if (upMatch == true)	// ��ư�� ���� �����Ҷ�
		{
			minButton = minButton < (i + c) ? minButton : (i + c);
		}
		bool downMatch = true;	// -��ư������ ����������
		nTemp = n - i;	// n���� -��ư�� i�� ��������,
		if (nTemp >= 0)	// 0 �̻��϶���
		{
			c = 0;
			//if (nTemp == 0 && remote[0] == true)
			//	c = 1;
			do
			{
				
				++c;
				int nMod = nTemp % 10;
				nTemp /= 10;
				if (remote[nMod] == false)
				{
					downMatch = false;
					break;
				}
			} while (nTemp != 0);
			if (downMatch == true)
			{
				minButton = minButton < (i + c) ? minButton : (i + c);
			}
		}
	}
	minButton = minButton < abs(100 - n) ? minButton : abs(100 - n);	// nä�ο��� 100ä�α����� ��
	cout << minButton << "\n";

	return 0;
}



//#include <iostream>
//#include <string>
//#include <cmath>
//using namespace std;
//
//int downFunction(int* wantedChannel, bool* remote, string str);
//int upFunction(int* wantedChannel, bool* remote, string str);
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	int n;
//	int m;
//	string str;
//	cin >> str;
//	n = stoi(str);
//	cin >> m;
//	int arr[10] = { 0, };	// broken button
//	for (int i = 0; i < m; i++)
//	{
//		cin >> arr[i];
//	}
//	bool remote[10] = { 0, };	// is remote button operate?
//	for (int i = 0; i < 10; i++)
//	{
//		remote[i] = true;	// all operate
//	}
//	for (int i = 0; i < m; i++)
//	{
//		remote[arr[i]] = false;	// broken button
//	}
//	int wantedChannel[6] = { 0, };
//	int tChannel[6] = { 0, };
//	for (int i = 0; i < str.length(); i++)
//	{
//		wantedChannel[i] = (int)(str[i] - '0');
//	}
//
//	int downValue = downFunction(wantedChannel, remote, str);
//	int upValue = upFunction(wantedChannel, remote, str);
//	int minPressButton = 0;
//	if (downValue == -1)
//	{
//		downValue = 100;
//	}
//	if (upValue == -1)
//	{
//		upValue = 100;
//	}
//	cout << downValue << "\n";
//	cout << upValue << "\n";
//	if ((abs(n - downValue)+to_string(downValue).length()) <= (abs(upValue - n)+to_string(upValue).length()))
//	{
//		minPressButton = abs(n - downValue);
//		minPressButton += to_string(downValue).length();
//	}
//	else
//	{
//		minPressButton = abs(upValue - n);
//		minPressButton += to_string(upValue).length();
//	}
//	cout << minPressButton << "\n";
//	minPressButton = minPressButton < abs(100 - n) ? minPressButton : abs(100 - n);
//	cout << minPressButton << "\n";
//	return 0;
//}
//
//int downFunction(int* wantedChannel, bool* remote, string str)
//{
//	int tChannel[6] = { 0, };
//	int position = 0;	// -1: down, 0: keep, 1:up
//	if (remote[wantedChannel[0]] == true)
//	{
//		tChannel[0] = wantedChannel[0];
//	}
//	else
//	{
//		for (int j = 1; j < 10; j++)
//		{
//			if (0 <= (wantedChannel[0] - j))
//			{
//				if (remote[wantedChannel[0] - j] == true)
//				{
//					tChannel[0] = (wantedChannel[0] - j);
//					position = -1;
//					break;
//				}
//			}
//			//if ((wantedChannel[0] + j) <= 9)
//			//{
//			//	if (remote[wantedChannel[0] + j] == true)
//			//	{
//			//		tChannel[0] = (wantedChannel[0] + j);
//			//		position = 1;
//			//		break;
//			//	}
//			//}
//		}
//		if (position != -1)
//		{
//			tChannel[0] = 0;	// �ƹ��͵� �� ����. 1234 �̸� 0999 ó�� 999�������� 0999�� ����.
//			position = -1;
//			//return -1;
//		}
//	}
//	for (int i = 1; i < str.length(); i++)
//	{
//		if (position == 0)
//		{
//			if (remote[wantedChannel[i]] == true)
//			{
//				tChannel[i] = wantedChannel[i];
//			}
//			else
//			{
//				for (int j = 1; j < 10; j++)
//				{
//					if (0 <= (wantedChannel[i] - j))
//					{
//						if (remote[wantedChannel[i] - j] == true)
//						{
//							tChannel[i] = (wantedChannel[i] - j);
//							position = -1;
//							break;
//						}
//					}
//					//if ((wantedChannel[i] + j) <= 9)
//					//{
//					//	if (remote[wantedChannel[i] + j] == true)
//					//	{
//					//		tChannel[i] = (wantedChannel[i] + j);
//					//		position = 1;
//					//		break;
//					//	}
//					//}
//				}
//				if (position != -1)
//				{
//					tChannel[0] = 0;
//					//return -1;
//				}
//			}
//		}
//		else if (position == -1)
//		{
//			for (int j = 9; j >= 0; j--)
//			{
//				if (remote[j] == true)
//				{
//					tChannel[i] = (j);
//					position = -1;
//					break;
//				}
//			}
//		}
//		//else if (position == 1)
//		//{
//		//	for (int j = 0; j <=9; j++)
//		//	{
//		//		if (remote[j] == true)
//		//		{
//		//			tChannel[i] = (j);
//		//			position = 1;
//		//			break;
//		//		}
//		//	}
//		//}
//	}
//	int t = 0;
//	for (int i = 0; i < str.length(); i++)
//	{
//		t *= 10;
//		t += tChannel[i];
//	}
//	if (remote[0] == false && t == 0)	// �ƹ��͵� �ȴ��� ��� (���� 0�ε� ��ư0 �̾�����)
//		return -1;
//	return t;
//}
//int upFunction(int* wantedChannel, bool* remote, string str)
//{
//	int up = 0;
//	int tChannel[6] = { 0, };
//	int position = 0;	// -1: down, 0: keep, 1:up
//	if (remote[wantedChannel[0]] == true)
//	{
//		tChannel[0] = wantedChannel[0];
//	}
//	else
//	{
//		for (int j = 1; j < 10; j++)
//		{
//			//if (0 <= (wantedChannel[0] - j))
//			//{
//			//	if (remote[wantedChannel[0] - j] == true)
//			//	{
//			//		tChannel[0] = (wantedChannel[0] - j);
//			//		position = -1;
//			//		break;
//			//	}
//			//}
//			if ((wantedChannel[0] + j) <= 9)
//			{
//				if (remote[wantedChannel[0] + j] == true)
//				{
//					tChannel[0] = (wantedChannel[0] + j);
//					position = 1;
//					break;
//				}
//			}
//		}
//		if (position != 1)
//		{
//			for (int j = 1; j <= 9; j++)	// 0����(�Ǿտ��ڸ��ϱ�)
//			{
//				if (remote[j] == true)
//				{
//					up = (j);	// 100 �ϰ�� 1100 �̷������� �Ǿ���ū �ڸ� 1����
//					position = 1;
//					break;
//				}
//			}
//			for (int j = 0; j <= 9; j++) // ���� 0����
//			{
//				if (remote[j] == true)
//				{
//					tChannel[0]  = (j);	
//					position = 1;
//					break;
//				}
//			}
//			position = 1;
//			//			return -1;
//		}
//	}
//	for (int i = 1; i < str.length(); i++)
//	{
//		if (position == 0)
//		{
//			if (remote[wantedChannel[i]] == true)
//			{
//				tChannel[i] = wantedChannel[i];
//			}
//			else
//			{
//				for (int j = 1; j < 10; j++)
//				{
//					//if (0 <= (wantedChannel[i] - j))
//					//{
//					//	if (remote[wantedChannel[i] - j] == true)
//					//	{
//					//		tChannel[i] = (wantedChannel[i] - j);
//					//		position = -1;
//					//		break;
//					//	}
//					//}
//					if ((wantedChannel[i] + j) <= 9)
//					{
//						if (remote[wantedChannel[i] + j] == true)
//						{
//							tChannel[i] = (wantedChannel[i] + j);
//							position = 1;
//							break;
//						}
//					}
//				}
//				if (position != 1)
//					return -1;
//			}
//		}
//		//else if (position == -1)
//		//{
//		//	for (int j = 9; j >= 0; j--)
//		//	{
//		//		if (remote[j] == true)
//		//		{
//		//			tChannel[i] = (j);
//		//			position = -1;
//		//			break;
//		//		}
//		//	}
//		//}
//		else if (position == 1)
//		{
//			for (int j = 0; j <=9; j++)
//			{
//				if (remote[j] == true)
//				{
//					tChannel[i] = (j);
//					position = 1;
//					break;
//				}
//			}
//		}
//	}
//	int t = 0;
//	t *= 10;
//	t += up;
//	for (int i = 0; i < str.length(); i++)
//	{
//		t *= 10;
//		t += tChannel[i];
//	}
//	if (remote[0] == false && t == 0)	// �ƹ��͵� �ȴ��� ��� (���� 0�ε� ��ư0 �̾�����)
//		return -1;
//	return t;
//}