#include <iostream>
using namespace std;

int findCount(int n);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	while (n-- > 0)
	{
		int x, y;
		cin >> x >> y;
		cout<<findCount(y - x)<<"\n";
	}
	
	return 0;
}

int findCount(int n)
{
	int count = 0;
	int speed = 1;
	while (n > 0)
	{
		if (speed * 2 <= n)	// 출발과 도착 속도 대칭.
		{
			count += 2;
			n -= speed * 2;
			speed++;
		}
		else if (speed <= n)	// 대칭되진않지만 속도+1 할수있을때
		{
			count++;
			n -= speed;
		}
		else
		{
			// 최고속도 이하남은거리( 중간에 증속안하고 이동하면됨, 예: (거리 11) 1 2 3 2 2 1 )
			count++;
			n -= n;
		}
	}
	return count;
}