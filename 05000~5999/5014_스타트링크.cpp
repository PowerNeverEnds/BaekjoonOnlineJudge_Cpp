#include <iostream>
#include <queue>

typedef long long ll;

using namespace std;

int main()
{
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;
	int* arr = new int[(ll)F + 1];
	fill(arr, arr + F + 1, -1);
	queue<int> q;
	arr[S] = 0;
	if (S + U <= F)
	{
		q.push(S + U);
		arr[S + U] = 1;
	}
	if (1 <= S - D)
	{
		q.push(S - D);
		arr[S - D] = 1;
	}
	while (true)
	{
		if (q.empty())
			break;
		S = q.front();
		q.pop();
		if (S == G)
			break;
		int nU = S + U;
		int nD = S - D;
		if (nU <= F && arr[nU] == -1)
		{
			q.push(S + U);
			arr[nU] = arr[S]+1;
		}
		if (1 <= nD && arr[nD] == -1)
		{
			q.push(S - D);
			arr[nD] = arr[S]+1;
		}
	}

	if (arr[G] == -1)
		cout << "use the stairs" << "\n";
	else
		cout << arr[G] << "\n";


	return 0;
}