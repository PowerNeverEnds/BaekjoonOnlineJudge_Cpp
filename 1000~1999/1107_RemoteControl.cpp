/*
1107_RemoteControl
알고리즘: 
1. 원하는 채널에서 +만 혹은 -만 한번 눌른다.
2. 그 채널이 리모컨으 버튼으로 눌러서 올수있는 경우, minButton값이랑 비교,
3. +- 어느 한쪽이 100 채널까지 올때까지, 1~2반복
4. 원하는 채널에서 100번 채널까지 +- 버튼 횟수 minButton값이랑 비교,
5. 출력

*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int n;	// 원하는 채널
	int m;	// 고장난 버튼 개수
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

	int minButton = 1000000;	// 적게 누른 버튼 값
	for (int i = 0;i<500001; i++)
	{
		if ((n + i) == 100 || (n - i) == 100)	// 100 도달 하면 break
			break;
		bool upMatch = true;	//  +버튼 눌러서 올려서 가는쪽, (true는 그채널 리모컨 숫자가 모두 존재)
		int nTemp = n + i;	// n에서 +버튼을 i번 눌렀을때,
		int c = 0;	// c는 자릿수, 예) 345 -> c=3
		do
		{	// 0 일때도 한번을 돌게 do while
			// 각자리수의 버튼이 있는지 확인
			++c;
			int nMod = nTemp % 10;
			nTemp /= 10;
			if (remote[nMod] == false)
			{
				upMatch = false;
				break;
			}
		} while (nTemp != 0);
		if (upMatch == true)	// 버튼이 전부 존재할때
		{
			minButton = minButton < (i + c) ? minButton : (i + c);
		}
		bool downMatch = true;	// -버튼눌러서 내려가는쪽
		nTemp = n - i;	// n에서 -버튼을 i번 눌렀을때,
		if (nTemp >= 0)	// 0 이상일때만
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
	minButton = minButton < abs(100 - n) ? minButton : abs(100 - n);	// n채널에서 100채널까지랑 비교
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
//			tChannel[0] = 0;	// 아무것도 안 누름. 1234 이면 0999 처럼 999만눌러도 0999랑 같음.
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
//	if (remote[0] == false && t == 0)	// 아무것도 안누를 경우 (값이 0인데 버튼0 이없을때)
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
//			for (int j = 1; j <= 9; j++)	// 0제외(맨앞에자리니까)
//			{
//				if (remote[j] == true)
//				{
//					up = (j);	// 100 일경우 1100 이런식으로 맨앞잴큰 자리 1누름
//					position = 1;
//					break;
//				}
//			}
//			for (int j = 0; j <= 9; j++) // 여긴 0부터
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
//	if (remote[0] == false && t == 0)	// 아무것도 안누를 경우 (값이 0인데 버튼0 이없을때)
//		return -1;
//	return t;
//}