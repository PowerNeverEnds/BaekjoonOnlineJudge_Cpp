#include <iostream>
#include <stack>

typedef long long ll;

using namespace std;

void dfs(int st, int* arr, int* visited)
{
	int t = st;
	stack<int> s;
	visited[st] = 1;
	s.push(st);
	while (true)
	{
		//for (int i = 1; i <= 7; i++)
		//{
		//	cout << visited[i] << " ";
		//}cout << "\n";
		if (s.empty())
			break;
		st = s.top();
		s.pop();
		int e = arr[st];
		if (visited[e] == -1)	// �̹� �湮������ ����Ŭ�� �̷��� ������
			break;
		else if (visited[e] == 0)
		{
			//			s.push(st);	//�ʿ����
			visited[e] = 1;
			s.push(e);
		}
		else if (visited[e] == 1)	// �湮�ߴ°��� �� �湮�Ұ��(����Ŭ�� �Ǵ°��)
		{
			visited[e] = 2;	// 2�� ����Ŭ�� �Ǵ� ����
			s.push(e);
		}
	}
	st = t;
	if (visited[st] != 2)	// ���������� ����Ŭ�� �ȵɰ��
	{
		visited[st] = -1;
		s.push(st);
		while (true)	// �����������κ���
		{
			if (s.empty())
				break;
			st = s.top();
			s.pop();
			int e;
			e = arr[st];
			if (visited[e] == 1)	// ����Ŭ�� ���� �ʴ� ��������
			{
				visited[e] = -1;
				s.push(e);
			}
			else
				break;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int* arr = new int[(ll)n + 1];
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}
		int* visited = new int[(ll)n + 1];
		fill(visited, visited + n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			if (visited[i] == 0)
			{
				dfs(i, arr, visited);
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (visited[i] != 2)
				cnt++;
		}
		cout << cnt << "\n";



		delete[] arr;
		delete[] visited;
	}

	return 0;
}