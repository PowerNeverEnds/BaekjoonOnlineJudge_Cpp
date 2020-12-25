#include <iostream>
#include <queue>

#define MAX ((int)1e4)

using namespace std;

void bfs(int A, bool* pb, int* visited, int B)
{
	queue<int> q;
	visited[A] = 1;
	q.push(A);
	while (true)
	{
		if (q.empty())
			break;
		A = q.front();
		q.pop();
		for (int i = 1; i < 10000; i *= 10)
		{
			for (int j = 0; j <= 9; j++)
			{
				int nA = A + ((-A / i % 10 + j) % 10) * i;
				//cout << A << " " << ((-A / i % 10 + j % 10) % 10) * i<<"\n";
				//cout << nA << "\n";
				if (nA < 1000)
					continue;
				if (pb[nA] == true && visited[nA] == 0)
				{
					visited[nA] = visited[A] + 1;
					q.push(nA);
					if (nA == B)
						return;
				}
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	bool* pb = new bool[MAX];
	fill(pb, pb + MAX, true);
	pb[0] = pb[1] = false;
	for (int i = 2; i < MAX; i++)
	{
		if (pb[i] == false)
			continue;
		pb[i] = true;
		for (int j = i + i; j < MAX; j += i)
		{
			pb[j] = false;
		}
	}


	int T;
	cin >> T;
	while (T--)
	{
		int A, B;
		cin >> A >> B;
		int* visited = new int[MAX];
		fill(visited, visited + MAX, 0);
		bfs(A, pb, visited, B);

		if (visited[B] - 1 == -1)
			cout << "Impossible" << "\n";
		else
			cout << visited[B] - 1 << "\n";
	}



	return 0;
}