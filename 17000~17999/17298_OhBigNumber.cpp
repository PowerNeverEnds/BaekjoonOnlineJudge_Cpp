/*
알고리즘:
1.뒤에서 부터 pair<값,위치> 으로 첫번째 stack에 저장, 스택의 top에는 <arr[0],0>이옴
2.if 두번째스택이 비어있다면, 첫번째스택top을 두번째스택push으로후 pop,
3-1.else 아니라면, if첫번째스택의top이 두번째스택의 top보다 작거나 같다면, 첫번째스택top을 두번째스택push으로후 pop,
3-2............, else 같거나 크다면, 두번째스택의 top을 배열에[<위치>]에 저장 후 pop
4.첫번째 스택이 empty 일때까지, 2-3반복,
5.두번째스택이 empty 일때까지 배열[<위치>]에 -1저장후 pop
6.배열 0~n까지 출력
*/
#include <iostream>
#include <utility>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// 0번 입력받기
	int n;
	cin >> n;
	int* arr = new int[1000000];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	// 1번
	stack<pair<int,int>> stackOne;
	for (int i = n-1; i >=0; i--)
	{
		stackOne.push(make_pair(arr[i],i));
	}
	//cout << stackOne.top().first <<" "<<stackOne.top().second << "\n";
	
	stack<pair<int, int>> stackTwo;
	int* nge = new int[1000000];

	// 4번
	while (stackOne.empty() == false)
	{
		// 2번
		if (stackTwo.empty() == true)
		{
			stackTwo.push(stackOne.top());
			stackOne.pop();
		}
		// 3번
		else
		{
			// 3-1번 .else 아니라면, if첫번째스택의top이 두번째스택의 top보다 작거나 같다면, 첫번째스택top을 두번째스택push으로후 pop,
			if (stackOne.top().first <= stackTwo.top().first)
			{
				stackTwo.push(stackOne.top());
				stackOne.pop();
			}
			// 3-2번 ..........., else  크다면, 첫번째스택의<값> 을 배열에[두번째스택<위치>]에 저장 후 pop
			else if (stackOne.top().first > stackTwo.top().first)
			{
				nge[stackTwo.top().second] = stackOne.top().first;
				stackTwo.pop();
			}
		}
	}
	// 5번 두번째스택이 empty 일때까지 배열[<위치>]에 - 1저장후 pop
	while (stackTwo.empty() == false)
	{
				nge[stackTwo.top().second] = -1;
				stackTwo.pop();
	}

	for (int i = 0; i < n; i++)
	{
		cout << nge[i] << " ";
	}
	//cout << "\n";

	return 0;
}



///*
//알고리즘:
//0.저장된그림파일참고
//1.for(arr[i] 0~n 까지), 증가하는숫자vector에저장,감소하고 다시 증가할때는 그다음의 다른vector에 저장
//2.for(arr[i] 0~n 까지), 각vector 마지막값이 잴크니까(증가하는저장), i이후의 vector중 처음나오는 vector 마지막값이 큰거 찾기
//3-1.없으면 -1
//3-2.있으면 그 벡터에서 binarySecarch로 자신보다 큰값찾기
//4.출력
//
//*/
//
//#include <iostream>
//#include <vector>
//#include <deque>
//using namespace std;
//
//int binarySearch(int num, vector<int> vec);
//void printVec(vector<vector<int>> vec);
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	int n;
//	cin >> n;
//	int* arr = new int[1000000];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	vector<vector<int>> vec;
//	deque<int> arrVecPoint;
//	int p = -1;
//	bool up = false;
//	//printVec(vec);
//	for (int i = 1; i < n; i++)
//	{
//		if (arr[i - 1] < arr[i])
//		{
//			if (up == true)
//			{
//				vec[p].push_back(arr[i]);
//				arrVecPoint.pop_back();
//				arrVecPoint.push_back(i);
//			}
//			else if (up == false)
//			{
//				vector<int> tVec = { arr[i] };
//				vec.push_back(tVec);
//				arrVecPoint.push_back(i);
//				p += 1;
//				up = true;
//			}
//		}
//		else if (arr[i - 1] >= arr[i])
//		{
//			if (up == true)
//			{
//				up = false;
//			}
//			else if (up == false)
//			{
//			}
//		}
//	}
//	//printVec(vec);
//
//
//	int pj = 0;
//	for (int i = 0; i < n; i++)
//	{
//		//if (arrVecPoint.front() == i)
//		//{
//		//	for(int j=0;j<vec[])
//		//}
//		int j;
//		bool exist = false;
//		if (arrVecPoint.empty() == false)
//		{
//			if (i >= arrVecPoint.front())
//			{
//				arrVecPoint.pop_front();
//				pj++;
//			}
//		}
//		for (j = pj; j <= p; j++)
//		{
//			if (arr[i] < vec[j].back())
//			{
//				exist = true;
//				break;
//			}
//		}
//		if (exist == false)
//		{
//			cout << "-1" << " ";
//			continue;
//		}
//		else if (exist == true)
//		{
//			cout << vec[j][binarySearch(arr[i], vec[j])] << " ";
//		}
//	}
//
//
//	return 0;
//}
//
//int binarySearch(int num, vector<int> vec)
//{
//	int begin = 0;
//	int end = vec.size() - 1;
//	int p = (begin + end) / 2;
//	while (true)
//	{
//		p = (begin + end) / 2;
//		//cout <<num<<" "<< begin << " "<<end <<" "<<p<<" "<<vec[p]<< "\n";
//		if (begin > end)
//		{
//			p = end + 1;
//			break;
//		}
//		if (num < vec[p])
//		{
//			begin = begin;
//			end = p - 1;
//		}
//		else if (vec[p] < num)
//		{
//			begin = p + 1;
//			end = end;
//		}
//		else if (vec[p] == num)
//		{
//			p = p + 1;
//			break;
//		}
//
//	}
//	return p;
//}
//
//
//void printVec(vector<vector<int>> vec)
//{
//	for (int i = 0; i < vec.size(); i++)
//	{
//		for (int j = 0; j < vec[i].size(); j++)
//		{
//			cout << vec[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	cout << "\n";
//}