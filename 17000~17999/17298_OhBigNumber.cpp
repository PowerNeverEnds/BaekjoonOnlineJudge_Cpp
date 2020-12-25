/*
�˰���:
1.�ڿ��� ���� pair<��,��ġ> ���� ù��° stack�� ����, ������ top���� <arr[0],0>�̿�
2.if �ι�°������ ����ִٸ�, ù��°����top�� �ι�°����push������ pop,
3-1.else �ƴ϶��, ifù��°������top�� �ι�°������ top���� �۰ų� ���ٸ�, ù��°����top�� �ι�°����push������ pop,
3-2............, else ���ų� ũ�ٸ�, �ι�°������ top�� �迭��[<��ġ>]�� ���� �� pop
4.ù��° ������ empty �϶�����, 2-3�ݺ�,
5.�ι�°������ empty �϶����� �迭[<��ġ>]�� -1������ pop
6.�迭 0~n���� ���
*/
#include <iostream>
#include <utility>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// 0�� �Է¹ޱ�
	int n;
	cin >> n;
	int* arr = new int[1000000];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	// 1��
	stack<pair<int,int>> stackOne;
	for (int i = n-1; i >=0; i--)
	{
		stackOne.push(make_pair(arr[i],i));
	}
	//cout << stackOne.top().first <<" "<<stackOne.top().second << "\n";
	
	stack<pair<int, int>> stackTwo;
	int* nge = new int[1000000];

	// 4��
	while (stackOne.empty() == false)
	{
		// 2��
		if (stackTwo.empty() == true)
		{
			stackTwo.push(stackOne.top());
			stackOne.pop();
		}
		// 3��
		else
		{
			// 3-1�� .else �ƴ϶��, ifù��°������top�� �ι�°������ top���� �۰ų� ���ٸ�, ù��°����top�� �ι�°����push������ pop,
			if (stackOne.top().first <= stackTwo.top().first)
			{
				stackTwo.push(stackOne.top());
				stackOne.pop();
			}
			// 3-2�� ..........., else  ũ�ٸ�, ù��°������<��> �� �迭��[�ι�°����<��ġ>]�� ���� �� pop
			else if (stackOne.top().first > stackTwo.top().first)
			{
				nge[stackTwo.top().second] = stackOne.top().first;
				stackTwo.pop();
			}
		}
	}
	// 5�� �ι�°������ empty �϶����� �迭[<��ġ>]�� - 1������ pop
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
//�˰���:
//0.����ȱ׸���������
//1.for(arr[i] 0~n ����), �����ϴ¼���vector������,�����ϰ� �ٽ� �����Ҷ��� �״����� �ٸ�vector�� ����
//2.for(arr[i] 0~n ����), ��vector ���������� ��ũ�ϱ�(�����ϴ�����), i������ vector�� ó�������� vector ���������� ū�� ã��
//3-1.������ -1
//3-2.������ �� ���Ϳ��� binarySecarch�� �ڽź��� ū��ã��
//4.���
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