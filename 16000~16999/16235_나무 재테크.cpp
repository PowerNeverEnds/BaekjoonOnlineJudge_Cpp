/*
pq 전체 나무에서
각칸별로 pq 변경

pq 에서 dq로 변경 
*/

#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>

typedef long long ll;

using namespace std;

// 12시부터 반시계방향
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,-1,-1,-1,0,1,1,1 };

struct MyTree
{
	int y;
	int x;
	int age;

	bool operator<(const MyTree& mt) const {
		return age > mt.age;
	}
};

void simul(int K, deque<int>*** dq, int** A, int** visited, int N)
{
	while (K--)
	{
		queue<MyTree> deadT;
		queue<MyTree> fiveT;
		int ind = K % 2;

		// 봄
		MyTree st;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				while (true)
				{
					if (dq[i][j][ind].empty())
						break;
					st = MyTree({ i,j,dq[i][j][ind].front() });
					dq[i][j][ind].pop_front();
					if (visited[st.y][st.x] < st.age)
					{
						deadT.push(MyTree({ st.y,st.x,st.age }));
					}
					else
					{
						visited[st.y][st.x] -= st.age;
						if ((st.age + 1) % 5 == 0)
						{
							fiveT.push(MyTree({ st.y,st.x,st.age + 1 }));
						}
						dq[i][j][!ind].push_back(st.age + 1);
					}
				}

			}
		}


		// 여름
		while (true)
		{
			if (deadT.empty())
				break;
			st = deadT.front();
			deadT.pop();
			visited[st.y][st.x] += st.age / 2;
		}

		// 가을
		while (true)
		{
			if (fiveT.empty())
				break;
			st = fiveT.front();
			fiveT.pop();
			for (int i = 0; i < 8; i++)
			{
				int nY = st.y + dy[i];
				int nX = st.x + dx[i];
				if (1 <= nY && nY <= N && 1 <= nX && nX <= N)
				{
					dq[nY][nX][!ind].push_front(1);
				}
			}
		}

		// 겨울
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				visited[i][j] += A[i][j];
			}
		}

	}
}

int main()
{
	int N, M, K;
	cin >> N >> M >> K;

	int** A = new int* [(ll)N + 2];
	fill(A, A + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		A[i] = new int[(ll)N + 2];
		fill(A[i], A[i] + N + 2, 0);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];
		}
	}

	deque<int>*** dq=new deque<int>**[(ll)N+2];
	fill(dq, dq + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		dq[i] = new deque<int> * [(ll)N + 2];
		fill(dq[i], dq[i] + N + 2, nullptr);
		for (int j = 0; j < N + 2; j++)
		{
			dq[i][j] = new deque<int>[2];
		}
	}
	vector<int>** tVec = new vector<int>*[(ll)N+2];
	for (int i = 0; i < N + 2; i++)
	{
		tVec[i] = new vector<int> [(ll)N + 2];

	}
	for (int i = 0; i < M; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		tVec[x][y].push_back(z);
		//dq[x][y][!(K % 2)].push(z);	// x,y 위치 바꿈
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			sort(tVec[i][j].begin(), tVec[i][j].end(), [](auto a, auto b) {
				return a < b;
				});
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (auto e : tVec[i][j])
			{
				dq[i][j][!(K % 2)].push_back(e);
			}
		}
	}


	int** visited = new int* [(ll)N + 2];
	fill(visited, visited + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		visited[i] = new int[(ll)N + 2];
		fill(visited[i], visited[i] + N + 2, 0);
	}
	for (int i = 1; i <= N; i++)
	{
		fill(visited[i] + 1, visited[i] + N + 1, 5);
	}

	simul(K, dq, A, visited, N);


	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cnt += (int)dq[i][j][1].size();
		}
	}


	cout << cnt << "\n";

	return 0;
}

///*
//https://www.acmicpc.net/board/view/60528
//*/
//#include <iostream>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//#define N_MAX 10
//
//int dr[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
//int dc[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
//
//int age, cnt;
//vector<pair<int, int> > tree[N_MAX + 1][N_MAX + 1];
//int map[N_MAX + 1][N_MAX + 1];
//int A[N_MAX + 1][N_MAX + 1];
//
//int N, M, K;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> N >> M >> K;
//
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			cin >> A[i][j];
//			map[i][j] = 5;
//		}
//	}
//
//	for (int i = 0; i < M; i++) {
//		int x, y, z;
//		cin >> x >> y >> z;
//		tree[x][y].push_back({ z, 1 });
//	}
//
//	while (K--) {
//		int reproduce[N_MAX + 1][N_MAX + 1] = { 0 };
//
//		// 봄 여 번식 저장
//		for (int i = 1; i <= N; i++) {
//			for (int j = 1; j <= N; j++) {
//				if (!tree[i][j].empty()) {
//					for (auto it = tree[i][j].rbegin(); it != tree[i][j].rend(); it++) {
//						int age = it->first;
//						int cnt = it->second;
//
//						if (map[i][j] >= age * cnt) {
//							map[i][j] -= age * cnt;
//							it->first++;
//
//							if (it->first % 5 == 0) {
//								for (int dir = 0; dir < 8; dir++) {
//									int nr, nc;
//									nr = i + dr[dir];
//									nc = j + dc[dir];
//
//									if (nr < 1 || nr > N || nc < 1 || nc > N) {
//										continue;
//									}
//									reproduce[nr][nc] += it->second;
//								}
//							}
//						}
//						else {
//							int canLive = map[i][j] / age;
//							if (canLive > 0) {
//								int die = cnt - canLive;
//
//								map[i][j] -= age * canLive;
//								map[i][j] += (age / 2) * die;
//								it->first++;
//								it->second = canLive;
//								if (it->first % 5 == 0) {
//									for (int dir = 0; dir < 8; dir++) {
//										int nr, nc;
//										nr = i + dr[dir];
//										nc = j + dc[dir];
//
//										if (nr < 1 || nr > N || nc < 1 || nc > N) {
//											continue;
//										}
//										reproduce[nr][nc] += it->second;
//									}
//								}
//								it++;
//							}
//							while (it != tree[i][j].rend()) {
//								map[i][j] += (it->first / 2) * it->second;
//								auto nit = decltype(it){tree[i][j].erase((++it).base())};
//								it = nit;
//							}
//							break;
//						}
//					}
//				}
//			}
//		}
//
//		// 번식, 겨
//		for (int i = 1; i <= N; i++) {
//			for (int j = 1; j <= N; j++) {
//				if (reproduce[i][j] != 0) {
//					//tree[i][j].push_back({ 1, reproduce[i][j] });
//				//}
//					if (!tree[i][j].empty() && tree[i][j].back().first == 1)
//						tree[i][j].back().second += reproduce[i][j];
//					else
//						tree[i][j].push_back({ 1, reproduce[i][j] });
//				}
//				map[i][j] += A[i][j];
//			}
//		}
//	}
//
//	int ret = 0;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			if (!tree[i][j].empty()) {
//				for (auto it = tree[i][j].begin(); it != tree[i][j].end(); it++) {
//					ret += it->second;
//				}
//			}
//		}
//	}
//
//	cout << ret << "\n";
//
//}

/*
10 1 1000

100 100 100 100 100 100 100 100 100 100

100 100 100 100 100 100 100 100 100 100

100 100 100 100 100 100 100 100 100 100

100 100 100 100 100 100 100 100 100 100

100 100 100 100 100 100 100 100 100 100

100 100 100 100 100 100 100 100 100 100

100 100 100 100 100 100 100 100 100 100

100 100 100 100 100 100 100 100 100 100

100 100 100 100 100 100 100 100 100 100

100 100 100 100 100 100 100 100 100 100

1 1 1


5 2 7
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 1 3
3 2 3


*/


/*
#include <iostream>
#include <queue>

typedef long long ll;

using namespace std;

// 12시부터 반시계방향
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,-1,-1,-1,0,1,1,1 };

struct MyTree
{
	int y;
	int x;
	int age;

	bool operator<(const MyTree& mt) const {
		return age > mt.age;
	}
};

struct compare
{
	bool operator()(const int& a, const int& b) const {
		return a > b;
	}
};

void simul(int K, priority_queue<int, vector<int>, compare>*** pq, int** A, int** visited, int N)
{
	while (K--)
	{
		//cout << "New Year!" << "\n";
		//cout << pq[0].size()<<" "<<pq[1].size() << "\n";
		queue<MyTree> deadT;
		queue<MyTree> fiveT;
		int ind = K % 2;

		//for (int i = 0; i < N + 2; i++)
		//{
		//	for (int j = 0; j < N + 2; j++)
		//	{
		//		cout << visited[i][j] << " ";
		//	}cout << "\n";
		//}
		//for (int i = 1; i <= N; i++)
		//{
		//	for (int j = 1; j <= N; j++)
		//	{
		//		cout<< pq[i][j][ind].size() << " ";
		//	}cout << "\n";
		//}

		// 봄
		MyTree st;
		//cout <<"qha "<< pq[ind].size() << "\n";

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				while (true)
				{
					if (pq[i][j][ind].empty())
						break;
					st = MyTree({ i,j,pq[i][j][ind].top() });
					pq[i][j][ind].pop();
					//cout << i << " " << j << " " << visited[i][j] << "\n";
					//cout << st.y << " " << st.x << " " << visited[st.y][st.x] << "\n";
					if (visited[st.y][st.x] < st.age)
					{
						//cout << "dead " << st.y << " " << st.x << " " << st.age << "\n";
						deadT.push(MyTree({ st.y,st.x,st.age }));
					}
					else
					{
						visited[st.y][st.x] -= st.age;
						if ((st.age + 1) % 5 == 0)
						{
							fiveT.push(MyTree({ st.y,st.x,st.age + 1 }));
						}
						//cout << !ind << " grow " << st.y << " " << st.x << " " << st.age << "\n";
						pq[i][j][!ind].push(st.age + 1);
					}
				}

			}
		}


		// 여름
		while (true)
		{
			if (deadT.empty())
				break;
			st = deadT.front();
			deadT.pop();
			visited[st.y][st.x] += st.age / 2;
		}

		// 가을
		//cout << "F " << fiveT.size() << "\n";
		while (true)
		{
			if (fiveT.empty())
				break;
			st = fiveT.front();
			fiveT.pop();
			for (int i = 0; i < 8; i++)
			{
				int nY = st.y + dy[i];
				int nX = st.x + dx[i];
				if (1 <= nY && nY <= N && 1 <= nX && nX <= N)
				{
					//cout << "push! " <<!ind<< "\n";
					pq[nY][nX][!ind].push(1);
				}
			}
		}

		// 겨울
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				visited[i][j] += A[i][j];
			}
		}

	}
}

int main()
{
	int N, M, K;
	cin >> N >> M >> K;

	int** A = new int* [(ll)N + 2];
	fill(A, A + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		A[i] = new int[(ll)N + 2];
		fill(A[i], A[i] + N + 2, 0);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];
		}
	}

	priority_queue<int, vector<int>, compare>*** pq = new priority_queue<int, vector<int>, compare>** [(ll)N + 2];
	for (int i = 0; i < N + 2; i++)
	{
		pq[i] = new priority_queue<int, vector<int>, compare>* [(ll)N + 2];
		for (int j = 0; j < N + 2; j++)
		{
			pq[i][j] = new priority_queue<int, vector<int>, compare>[2];
		}
	}

	for (int i = 0; i < M; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		pq[x][y][!(K % 2)].push(z);	// x,y 위치 바꿈
	}

	int** visited = new int* [(ll)N + 2];
	fill(visited, visited + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		visited[i] = new int[(ll)N + 2];
		fill(visited[i], visited[i] + N + 2, 0);
	}
	for (int i = 1; i <= N; i++)
	{
		fill(visited[i] + 1, visited[i] + N + 1, 5);
	}

	simul(K, pq, A, visited, N);

	//for (int i = 0; i < N + 2; i++)
	//{
	//	for (int j = 0; j < N + 2; j++)
	//	{
	//		cout << visited[i][j] << " ";
	//	}cout << "\n";
	//}

	//cout << pq[0].size() << " ";
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cnt += (int)pq[i][j][1].size();
			//cout << pq[i][j][0].size() << " " << pq[i][j][1].size() << "\n";
		}
	}
	//for (int i = 1; i <= N; i++)
	//{
	//	for (int j = 1; j <= N; j++)
	//	{
	//		cout << pq[i][j][1].size() << " ";
	//	}cout << "\n";
	//}

	cout << cnt << "\n";

	return 0;
}


*/



/*

5 2 7
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 1 3
3 2 3



*/

/*


#include <iostream>
#include <queue>

typedef long long ll;

using namespace std;

// 12시부터 반시계방향
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,-1,-1,-1,0,1,1,1 };

struct MyTree
{
	int y;
	int x;
	int age;

	bool operator<(const MyTree& mt) const {
		return age > mt.age;
	}
};

void simul(int K, priority_queue<MyTree>* pq, int** A, int** visited, int N)
{
	while (K--)
	{
		//cout << pq[0].size()<<" "<<pq[1].size() << "\n";
		queue<MyTree> deadT;
		queue<MyTree> fiveT;
		int ind = K % 2;
		// 봄
		MyTree st;
		//cout <<"qha "<< pq[ind].size() << "\n";
		while (true)
		{
			if (pq[ind].empty())
				break;
			st = pq[ind].top();
			pq[ind].pop();
			if (visited[st.y][st.x] < st.age)
			{
				//cout << "dead " << "\n";
				deadT.push(MyTree({ st.y,st.x,st.age }));
			}
			else
			{
				visited[st.y][st.x] -= st.age;
				if ((st.age + 1) % 5 == 0)
				{
					fiveT.push(MyTree({ st.y,st.x,st.age + 1 }));
				}
				pq[!ind].push(MyTree({ st.y,st.x,st.age + 1 }));
			}
		}

		// 여름
		while (true)
		{
			if (deadT.empty())
				break;
			st = deadT.front();
			deadT.pop();
			visited[st.y][st.x] += st.age / 2;
		}

		// 가을
		//cout << "F " << fiveT.size() << "\n";
		while (true)
		{
			if (fiveT.empty())
				break;
			st = fiveT.front();
			fiveT.pop();
			for (int i = 0; i < 8; i++)
			{
				int nY = st.y + dy[i];
				int nX = st.x + dx[i];
				if (1 <= nY && nY <= N && 1 <= nX && nX <= N)
				{
					//cout << "push!" << "\n";
					pq[!ind].push(MyTree({ nY,nX,1 }));
				}
			}
		}

		// 겨울
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				visited[i][j] += A[i][j];
			}
		}

	}
}

int main()
{
	int N, M, K;
	cin >> N >> M >> K;

	int** A = new int* [(ll)N + 2];
	fill(A, A + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		A[i] = new int[(ll)N + 2];
		fill(A[i], A[i] + N + 2, 0);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];
		}
	}

	priority_queue<MyTree> pq[2];

	for (int i = 0; i < M; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		pq[!(K % 2)].push(MyTree({ y,x,z }));
	}

	int** visited = new int* [(ll)N + 2];
	fill(visited, visited + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		visited[i] = new int[(ll)N + 2];
		fill(visited[i], visited[i] + N + 2, 0);
	}
	for (int i = 1; i <= N; i++)
	{
		fill(visited[i] + 1, visited[i] + N + 1, 5);
	}

	simul(K, pq, A, visited, N);

	//for (int i = 0; i < N+2; i++)
	//{
	//	for (int j = 0; j < N+2; j++)
	//	{
	//		cout << visited[i][j] << " ";
	//	}cout << "\n";
	//}

	//cout << pq[0].size() << " ";
	cout << pq[1].size() << "\n";
	return 0;
}

*/