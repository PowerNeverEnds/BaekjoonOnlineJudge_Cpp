#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

int dy[8] = {
	-1,-1,
	0,
	1,1,1,
	0,
	-1
};
int dx[8] = {
	0,
	1,1,1,
	0,
	-1,-1,-1
};

class MyClass
{
public:
	// 위치는 (ri, ci), 질량은 mi이고, 방향은 di, 속력은 si이다. 위치 (r, c)는 r행 c열을 의미한다.
	int r, c, m, s, d;
	MyClass(int r, int c, int m, int s, int d) :r(r), c(c), m(m), s(s), d(d) {};
	void move(int N) {
		r = (r + dy[d] * s - 1 + N * (s + 1)) % N + 1;
		c = (c + dx[d] * s - 1 + N * (s + 1)) % N + 1;
	};
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	list<MyClass> l;	// 파이어볼

	int N, M, K;
	cin >> N >> M >> K;



	for (int i = 0; i < M; i++)
	{
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		l.push_back(MyClass{ r, c, m, s, d });
	}
	for (int k = 0; k < K; k++)
	{
		//		map<pair<int, int>, vector<MyClass*>> m;
		map<pair<int, int>, vector<list<MyClass>::iterator>> m;	// 각점에 해당하는 파이어볼

		int lSize = l.size();
		list<MyClass>::iterator lIter = l.begin();

		// 파이어볼이동과 이동후점에 저장
		for (int i = 0; i < lSize; i++)
		{
			lIter->move(N);
			m[make_pair(lIter->r, lIter->c)].push_back(lIter);
			lIter++;
		}

		// 겹치는 파이어볼 합친후 나누기
		for (auto mE : m)
		{
			if (mE.second.size() > 1)
			{
				vector<list<MyClass>::iterator>& tVec = m[mE.first];
				int mass = 0, speed = 0;
				bool odd = true, even = true;
				for (auto vE : tVec)
				{
					mass += vE->m;
					speed += vE->s;
					if (vE->d % 2 != 1)
						odd = false;
					if (vE->d % 2 != 0)
						even = false;
					l.erase(vE);
				}
				mass /= 5;
				if (mass == 0)
					continue;
				speed /= (tVec.size());
				if (odd == true || even == true)
					for (int i = 0; i < 8; i += 2)
						l.push_back(MyClass{ mE.first.first,mE.first.second,mass,speed,i });
				else
					for (int i = 1; i < 8; i += 2)
						l.push_back(MyClass{ mE.first.first,mE.first.second,mass,speed,i });


			}
		}

	}

	//int** arr = new int* [(long long)N + 1];
	//for (int i = 0; i < N + 1; i++)
	//{
	//	arr[i] = new int[(long long)N + 1];
	//	fill(arr[i], arr[i] + N + 1, 0);
	//}

	int sum = 0;
	//cout << l.size() << "\n";
	for (auto lE : l)
	{
		//cout << lE.r << " " << lE.c << " " << lE.m << " " << lE.s << " " << lE.d << "\n";
		//arr[lE.r][lE.c] = lE.m;
		sum += lE.m;
	}
	cout << sum << "\n";
	//for (int i = 1; i <= N; i++)
	//{
	//	for (int j = 1; j <= N; j++)
	//	{
	//		cout << arr[i][j] << " ";
	//	}cout << "\n";
	//}

	return 0;
}


/*
#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

int dy[8] = {
	-1,-1,
	0,
	1,1,1,
	0,
	-1
};
int dx[8] = {
	0,
	1,1,1,
	0,
	-1,-1,-1
};

class MyClass
{
public:
	// 위치는 (ri, ci), 질량은 mi이고, 방향은 di, 속력은 si이다. 위치 (r, c)는 r행 c열을 의미한다.
	int r, c, m, s, d;
	MyClass(int r, int c, int m, int s, int d) :r(r), c(c), m(m), s(s), d(d) {};
	void move(int N) {
		r = (r + dy[d] * s - 1 + N * (s + 1)) % N + 1;
		c = (c + dx[d] * s - 1 + N * (s + 1)) % N + 1;
	};
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	list<MyClass> l;	// 파이어볼

	int N, M, K;
	cin >> N >> M >> K;



	for (int i = 0; i < M; i++)
	{
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		l.push_back(MyClass{ r, c, m, s, d });
	}
	for (int k = 0; k < K; k++)
	{
		//		map<pair<int, int>, vector<MyClass*>> m;
		map<pair<int, int>, vector<list<MyClass>::iterator>> m;	// 각점에 해당하는 파이어볼

		int lSize = l.size();
		list<MyClass>::iterator lIter = l.begin();

		// 파이어볼이동과 이동후점에 저장
		for (int i = 0; i < lSize; i++)
		{
			lIter->move(N);
			m[make_pair(lIter->r, lIter->c)].push_back(lIter);
			lIter++;
		}

		// 겹치는 파이어볼 합친후 나누기
		for (auto mE : m)
		{
			if (mE.second.size() > 1)
			{
				vector<list<MyClass>::iterator>& tVec = m[mE.first];
				int mass = 0, speed = 0;
				bool odd = true, even = true;
				for (auto vE : tVec)
				{
					mass += vE->m;
					speed += vE->s;
					if (vE->d % 2 != 1)
						odd = false;
					if (vE->d % 2 != 0)
						even = false;
					l.erase(vE);
				}
				mass /= 5;
				if (mass == 0)
					continue;
				speed /= (tVec.size());
				if (odd == true || even == true)
					for (int i = 0; i < 8; i += 2)
						l.push_back(MyClass{ mE.first.first,mE.first.second,mass,speed,i });
				else
					for (int i = 1; i < 8; i += 2)
						l.push_back(MyClass{ mE.first.first,mE.first.second,mass,speed,i });


			}
		}

	}

	int sum = 0;
	for (auto lE : l)
	{
		sum += lE.m;
	}
	cout << sum << "\n";

	return 0;
}

*/