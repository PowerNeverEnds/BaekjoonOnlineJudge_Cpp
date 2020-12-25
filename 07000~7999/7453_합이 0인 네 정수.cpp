/**
 *    BOJ 7453
 *    - ���� 0�� �� ����
 *    author:  phcdream
 *    created: ���� 8:37 2020-12-13
**/
/*
https://leetcode.com/submissions/detail/431645396/?from=explore&item_id=3569

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

typedef long long ll;

#define dout if(false) cout

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cerr.setstate(ios_base::failbit);

	int N;
	cin >> N;
	vector<int> A, B, C, D;
	for (int i = 0; i < N; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}

	unordered_map<int, int> mp;
	//map<int, int> mp;
	ll count = 0;
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B.size(); j++)
		{
			mp[A[i] + B[j]]++;
		}
	}

	vector<int> CD;
	for (int i = 0; i < C.size(); i++)
	{
		for (int j = 0; j < D.size(); j++)
		{
			CD.push_back(C[i] + D[j]);
		}
	}

	sort(CD.begin(), CD.end());

	dout << CD[0] << "\n";
	auto l = lower_bound(CD.begin(), CD.end(), CD[0]);
	auto r = upper_bound(CD.begin(), CD.end(), CD[0]);
	while (true)
	{
		if (l == CD.end())
			break;
		r = upper_bound(CD.begin(), CD.end(), *l);
		if (mp.find(-*l) != mp.end())
		{
			count += (mp[-*l] * (r - l));
		}
		l = r;
	}
	//for (int i = 0; i < C.size(); i++)
	//{
	//	for (int j = 0; j < D.size(); j++)
	//	{
	//		if (mp.find(-(C[i] + D[j])) != mp.end())
	//		{
	//			count += mp[-(C[i] + D[j])];
	//		}
	//	}
	//}

	cout << count << "\n";

	return 0;
}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <fstream>
//
//typedef long long ll;		// long long �߰�
//
//#define dout if(false) cout
//
//using namespace std;
//
//void someThing(int& stg)
//{
//	stg *= stg;
//	return;
//}
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//	
//	//ofstream out;
//	//out.open("input.txt");
//	//out.setstate(ios_base::failbit);
//	//out.close();
//
//
//	int N;
//	cin >> N;
//	vector<int> A, B, C, D;
//	for (int i = 0; i < N; i++)
//	{
//		int a, b, c, d;
//		cin >> a >> b >> c >> d;
//		A.push_back(a);
//		B.push_back(b);
//		C.push_back(c);
//		D.push_back(d);
//	}
//	vector<int> abVec, cdVec;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			abVec.push_back(A[i] + B[j]);
//			cdVec.push_back(C[i] + D[j]);
//		}
//	}
//	sort(abVec.begin(), abVec.end(), [](auto a, auto b) {
//		return a < b;
//		});
//	sort(cdVec.begin(), cdVec.end(), [](auto a, auto b) {
//		return a < b;
//		});
//
//	ll cnt = 0;		// cnt ���� long long 
//	bool bPrev = false;
//	ll prevCnt = 0;
//	for (int i = 0; i < N*N; i++)
//	{
//		if (0 < i && bPrev == true && abVec[i] == abVec[(ll)i - 1])		// abVec[i-1]==abVec[i] �߰�
//		{
//			cnt += prevCnt;
//			continue;		// abVec[i-1]==abVec[i] ��ŵ
//		}
//		else
//			bPrev = false;
//		int l, r;
//		l = 0;
//		r = N * N ;	// N*N-1 -> N*N ���� -1 ����
//		int m;
//		while (true)	// lower_bound
//		{
//			//int stg = 0;
//			//someThing(stg);
//			dout << l << " " << r << "\n";
//			if (l >= r)
//				break;
//			m = (l + r) / 2;
//			if (abVec[i] + cdVec[m] < 0)
//			{
//				l = m + 1;
//			}
//			else if(0<=abVec[i]+cdVec[m])
//			{
//				r = m;
//			}
//		}
//		int lowerL = r;
//		if (r<N*N && abVec[i] + cdVec[r] == 0)	// r�����߰�
//		{
//			int l, r;
//			l = 0;
//			r = N * N;		// -1 ����
//			int m;
//			while (true)	// upper_bound
//			{
//				//cerr << l << " " << r << "\n";
//				if (l >= r)
//					break;
//				m = (l + r) / 2;
//				if (abVec[i] + cdVec[m] <= 0)
//				{
//					l = m + 1;
//				}
//				else if (0 < abVec[i] + cdVec[m])
//				{
//					r = m;
//				}
//			}
//			dout << lowerL<<" "<<r << "\n";
//			prevCnt = (ll)((ll)r - 1) - ((ll)lowerL - 1);	// abVec[i-1]==abVec[i] �߰�
//			bPrev = true;									// abVec[i-1]==abVec[i] �߰�
//			cnt += (ll)((ll)r-1 ) - ((ll)lowerL - 1);
//		}
//	}
//	cout << cnt << "\n";
//
//
//	return 0;
//}
/*
6
-45 22 42 -16
-41 -27 56 30
-36 53 -37 77
-36 30 -75 -46
26 -38 -10 62
-32 -54 -6 45

3
-1 0 1 0
-1 0 1 0
-1 0 1 0

-1 -1 -1 X3
1 1 1 X3
81

1
-1 -1 -1 -1

1
1 1 1 1

1
1 0 1 1

1
1 0 1 0

1
0 0 0 0

1
-1 1 -1 1

*/