/**
 *    BOJ 2143
 *    - 두 배열의 합
 *    author:  phcdream
 *    created: 오전 2:03 2020-12-19
**/

#include <iostream>
//#include <vector>
//#include <algorithm>

typedef long long ll;

#define ALL false
#define dfor if(true && ALL) for
#define dout if(true && ALL) cout

using namespace std;

void in(ll& T, int& n, int*& nArr, int& m, int*& mArr)
{
	cin >> T;
	cin >> n;
	nArr = new int[(ll)n + 1];
	fill(nArr, nArr + n + 1, 0);
	nArr[0] = n;
	for (int i = 1; i <= n; i++)
		cin >> nArr[i];
	cin >> m;
	mArr = new int[(ll)m + 1];
	fill(mArr, mArr + m + 1, 0);
	mArr[0] = m;
	for (int i = 1; i <= m; i++)
		cin >> mArr[i];
}

struct MySegTree
{
	ll* sTree;
	ll(*comp)(ll,ll);
	int N;
	ll init(int*& vec, ll(*comp)(ll,ll))
	{
		this->comp = comp;
		this->N = vec[0];
		sTree = new ll[(ll)N * 4];
		return init(vec, 1, 1, N);
	}
	ll init(int*& vec, int node, int begin, int end)
	{
		if (begin == end)
		{
			return sTree[node] = vec[begin];
		}
		int mid = (begin + end) / 2;
		return sTree[node] = comp(init(vec, node*2, begin, mid),init(vec,node*2+1,mid+1,end));
	}

	ll sum(int left, int right)
	{
		return sum(1, 1, N, left, right);
	}
	// left, right 구해야하는 범위
	// begin, end 재귀돌면서 변하는 범위
	// node: begin~end 범위에 포함되는 합의 인덱스
	ll sum(int node, int begin, int end, int left, int right)
	{
		if ( end<left || right<begin)	//	(둘다 범위밖으로 )겹치지 않으면
		{
			return 0;
		}
		if (left <= begin && end <= right)	// (둘다 안으로 )쏘옥 들어와있으면
		{
			return sTree[node];
		}
		int mid = (begin + end) / 2;
		return comp(sum(node * 2, begin, mid, left, right), sum(node * 2 + 1, mid + 1,end, left, right));
	}

	void update(int index, ll diff)
	{
		update(1, 1, N, index, diff);
	}
	//	index가 begin-end 사이면(index를 포함하면)
	//	index를 포함하는 노드는 전부 diff만큼 comp함수적용하기
	void update(int node, int begin, int end, int index, ll diff)
	{
		if (index < begin || end < index)
		{
			return;
		}
		sTree[node]=comp(sTree[node], diff);
		if (begin == end)
			return;
		int mid = (begin + end) / 2;
		update(node * 2, begin, mid, index, diff);
		update(node * 2 + 1, mid + 1, end, index, diff);
	}
};

int myLowerBound(ll n, ll*& arr, ll& size)
{
	int l = 0;
	int r = (int)size;
	int mid = (l + r) / 2;
	while (true)
	{
		mid = (l + r) / 2;
		if (l == r)
			break;
		if (arr[mid] < n)
			l = mid + 1;
		else
			r = mid;
	}
	return r;
}

int myUpperBound(ll n, ll*& arr, ll& size)
{
	int l = 0;
	int r = (int)size;
	int mid = (l + r) / 2;
	while (true)
	{
		mid = (l + r) / 2;
		if (l == r)
			break;
		if (arr[mid] <= n)
			l = mid + 1;
		else
			r = mid;
	}
	return r;
}

void myMerge(ll* begin, ll* mid, ll* end, bool(*comp)(ll, ll), ll* tArr)
{
	ll i = 0;
	ll j = mid - begin+1;
	ll p = 0;
	ll llMid = mid - begin;
	ll llEnd = end - begin;
	while (true)
	{
		if (!(i <= llMid && j <= llEnd))
			break;
		if (comp(begin[i], begin[j]) || begin[i]==begin[j])
		{
			tArr[p] = begin[i];
			i++;
		}
		else
		{
			tArr[p] = begin[j];
			j++;
		}
		p++;
	}

	while (true)
	{
		if (i <= llMid)
			tArr[p] = *(begin + i);
		else
			break;
		p++; i++;
	}
	while (true)
	{
		if (j <= llEnd)
			tArr[p] = *(begin + j);
		else
			break;
		p++; j++;
	}

	for (int i = 0; i <= llEnd; i++)
	{
		dout << begin[i] << "->" << tArr[i] << "\n";
		begin[i] = tArr[i];
		
	}
	dfor(int i = 0; i <= llEnd; i++)
	{
		dout << begin[i] << " ";
	}
	dout << "\n";
}

void myMergeSort(ll* begin, ll* end, bool(*comp)(ll, ll), ll* tArr)
{
	if (begin >= end)
		return;
	ll l = 0;
	ll r = end - begin;
	ll mid = (l + r) / 2;
	myMergeSort(begin, begin + mid, comp,tArr);
	myMergeSort(begin + mid + 1, end, comp,tArr);

	myMerge(begin, begin+mid, end, comp,tArr);
}

void mySort(ll* begin, ll* end, bool (*comp)(ll, ll))
{
	ll l = 0;
	ll r = end - begin;
	ll* tArr = new ll[(ll)(end - begin + 1)];
	myMergeSort(begin, end-1, comp,tArr);
	//for (int i = 0; i < r; i++)
	//{
	//	cout << begin[i] << " ";
	//}
}

ll solve(ll& T, int& n, int*& nArr, int& m, int*& mArr)
{
	MySegTree mstN;
	MySegTree mstM;
	//mstA.init(nArr, [](auto a, auto b) {
	//	return a + b;
	//	});
	ll (*comp)(ll,ll)=[](auto a, auto b) {
		return (ll)a + b;
			};
	mstN.init(nArr, comp);
	mstM.init(mArr, comp);
	dout << "!" << "\n";

	ll sumNsize = ((ll)(n) * n + 1);
	ll* sumN = new ll[(ll)((ll)n) * n + 1];
	fill(sumN, sumN + (ll)n * n + 1, 0);
	int c = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			sumN[c++] = mstN.sum(i, j);
			dout << sumN[c - 1] << " ";
		}
		dout << " ";
	}
	dout << "\n";
	sumNsize = c;
	ll sumMsize = ((ll)(m) * m + 1);
	ll* sumM = new ll[(ll)((ll)m) * m + 1];
	fill(sumM, sumM + (ll)m * m + 1, 0);
	c = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = i; j <= m; j++)
		{
			sumM[c++] = mstM.sum(i, j);
			dout << sumM[c - 1] << " ";
		}
	}
	dout << "\n";
	sumMsize = c;

	mySort(sumN, sumN + sumNsize, [](auto a, auto b) {
		return a < b;
		});
	mySort(sumM, sumM + sumMsize, [](auto a, auto b) {
		return a < b;
		});
	//sort(sumN, sumN + sumNsize, [](auto a, auto b) {
	//	return a < b;
	//	});
	//sort(sumM, sumM + sumMsize, [](auto a, auto b) {
	//	return a < b;
	//	});

	dout << "!" << "\n";
	dfor(int i = 0; i < sumNsize; i++)
	{
		dout << sumN[i] << " ";
	}
	dout << "\n";
	dfor(int i = 0; i < sumMsize; i++)
	{
		dout << sumM[i] << " ";
	}
	dout << "\n";

	ll i = 0;
	ll lN = myLowerBound(sumN[0], sumN, sumNsize);
	ll uN = myUpperBound(sumN[0], sumN, sumNsize);
	ll cnt = 0;
	while (true)
	{
		i = lN;
		if (lN == (n*(n+1))/2)
			break;
		uN= myUpperBound(sumN[lN], sumN, sumNsize);
		dout << "\n";
		dout << lN << " " << uN << "\n";
		ll lM = myLowerBound(T - sumN[i], sumM, sumMsize);
		ll uM = myUpperBound(T - sumN[i], sumM, sumMsize);
		dout << lM << " " << uM << "\n";
		cnt += (ll)((ll)uN - lN) * ((ll)uM - lM);
		dout <<((ll)uN - lN) * ((ll)uM - lM)<<" "<< cnt << "\n";
		lN = uN;
	}

	return cnt;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll T;
	int n;
	int* nArr;
	int m;
	int* mArr;
	in(T, n, nArr, m, mArr);

	ll re = solve(T, n, nArr, m, mArr);
	cout << re << "\n";

	return 0;
}

/*

5
4
1 3 1 2
3
1 3 2

5
4
1 2 3 4
5
1 1 2 3 4

0
3
-1 0 1
3
-1 0 1

*/

