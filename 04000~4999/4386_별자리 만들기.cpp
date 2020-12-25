/**
 *    BOJ 4386
 *    - 별자리 만들기
 *    author:  phcdream
 *    created: 오전 1:39 2020-12-17
**/

#include <iostream>
#include <vector>
#include <queue>
//#include <cmath>
#include <iomanip>

typedef long long ll;

using namespace std;

struct MyPoint
{
	double y;
	double x;
};

struct MyStruct
{
	int n;
	double w;
	bool operator<(const MyStruct& ms)const {		//	less->max_heap
		return w > ms.w;
	}
};

double mySqrt(double n)
{
	//cout << n << "\n";
	double a = (double)n;
	double x = 1;
	double prev = a+x;
	double gap = 0.00001;
	for (int i = 0;; i++)
	{
		x = 0.5 * (x + a / x);
		//cout <<"s "<< x << " " << prev << "\n";
		if (prev - x < gap)
			break;
		prev = x;
	}
	return x;
}

double getDist(MyPoint a, MyPoint b)
{
	double yy = (a.y - b.y);
	yy *= yy;
	double xx = (a.x - b.x);
	xx *= xx;
	return yy + xx;
}

double solve(int n, vector<MyStruct>*& graph)
{
	int* visited = new int[(ll)n + 1];
	fill(visited, visited + n + 1, 0);
	double sum = 0;
	priority_queue<MyStruct> pq;
	MyStruct st{ 1,0 };
	sum += mySqrt(st.w);
//	visited[1] = 1;
	pq.push({ 1,0 });
	while (true)
	{
		if (pq.empty())
			break;
		st = pq.top();
		pq.pop();
		if (visited[st.n]!=0)
			continue;
		visited[st.n] = 1;
		sum += mySqrt(st.w);
		//cout << st.n <<" "<<st.w<<" "<<mySqrt(st.w)<< "\n";
		for (auto e : graph[st.n])
		{
			if (visited[e.n] == 0)
				pq.push(e);
		}
	}
	
	return sum;

}

#include <cassert>
int main()
{
	int n;
	cin >> n;
	MyPoint* star = new MyPoint[(ll)n + 1];
	for (int i = 1; i <= n; i++)
	{
		double x, y;
		cin >> x >> y;
		//assert(x-int(x)==0 && y-int(y)==0);
		star[i] = { y,x };
	}
	vector<MyStruct>* graph = new vector<MyStruct>[(ll)n + 1];
	for (int i = 1; i <= n; i++)
	{
		for (int j = i+1; j <= n; j++)
		{
			double dist = getDist(star[i], star[j]);
			graph[i].push_back({ j,dist });
			graph[j].push_back({ i,dist });
		}
	}

	double re = solve(n,graph);
	cout << fixed << setprecision(3) << re << "\n";

	return 0;
}

/*

3
1.0 1.0
2.0 2.0
2.0 4.0


2
1 1
8.1 1

*/
