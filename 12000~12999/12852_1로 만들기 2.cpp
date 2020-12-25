/**
 BOJ 12852
 - 1로 만들기 2
 - 오후 8:06 2020-11-28
 */

/*
정답 확인용 코드
https://chosh95.tistory.com/209
*/

//#include <iostream>
//#include <queue>
//using namespace std;
//pair<int, int> p[1000001];
//int N;
//
//void dynamic() {
//	p[1] = { 0,0 };
//	for (int i = 2; i <= N; i++) {
//		p[i] = { p[i - 1].first + 1,i - 1 };
//		if (i % 2 == 0) {
//			if (p[i].first > p[i / 2].first + 1)
//				p[i] = { p[i / 2].first + 1, i / 2 };
//		}
//		if (i % 3 == 0) {
//			if (p[i].first > p[i / 3].first + 1)
//				p[i] = { p[i / 3].first + 1, i / 3 };
//		}
//	}
//}
//
//int main()
//{
//	cin >> N;
//	dynamic();
//	cout << p[N].first << "\n";
//
//	int i = N;
//	cout << N << " ";
//	while (p[i].second != 0) {
//		cout << p[i].second << " ";
//		i = p[i].second;
//	}
//}

#include <iostream>

typedef long long ll;

#define INF ((int)1e7+7)

using namespace std;

void init(int& N, int*& arr, int*& prev)
{
	cin >> N;
	arr = new int[(ll)N + 1];
	fill(arr, arr + N + 1, INF);
	prev = new int[(ll)N + 1];
	fill(prev, prev + N + 1, 0);

}

void dfs(int N, int*& arr, int*& prev, int& min)
{
	if (N == 1)
	{
		min = 0;
		return;
	}
	bool bOper[3] = { N % 3 == 0,N % 2 == 0,N - 1 > 0 };
	int oper[3] = { N / 3,N / 2,N - 1 };

	for (int i = 0; i < 3; i++)
	{
		//cout <<i<<" "<<bOper[i]<<" "<< oper[i] << "\n";
		if (bOper[i] == true && 0 < oper[i])
		{
			//cout << arr[N] << " " << arr[oper[i]] << "\n";
			if (arr[N] + 1 > arr[oper[i]])
				//return;							//return -> continue
				continue;
			arr[oper[i]] = arr[N] + 1;
			prev[oper[i]] = N;
			//cout << arr[oper[i]]<<" "<<oper[i] << "\n";
			if (min < arr[oper[i]])
				return;
			if (oper[i] == 1)
			{
				min = arr[oper[i]] < min ? arr[oper[i]] : min;
				//cout <<"min "<< min << "\n";
				return;
			}
			dfs(oper[i], arr, prev, min);
		}
	}
}

int* solve(int N, int*& arr, int*& prev)
{
	int min = INF;
	arr[N] = 0;
	dfs(N, arr, prev, min);

	int size;
	size = min;
	int* re = new int[(ll)size + 2];
	int p = 1;
	re[0] = size;


	//cout <<"size "<< size << "\n";
	for (int i = size + 1; i > 0; i--)
	{
		re[i] = p;
		p = prev[re[i]];
	}
	//for (int i = 0; i <= N; i++)
	//	cout <<i<<" "<< arr[i] << " " << prev[i] << "\n";
	//cout << "\n";

	return re;
}

void out(int* re)
{
	int size = re[0];
	cout << size << "\n";
	for (int i = 1; i <= size + 1-1; i++)
		cout << re[i] << " ";
	cout << "1";
	cout << "\n";
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	int* arr;	// 횟수
	int* prev;
	//for (int i = 1; i < 1000; i++)
	//{
		//N = i;
		init(N, arr, prev);

		int* re = solve(N, arr, prev);

		out(re);
	//}

	return 0;
}

/*
572
correct: 
10
572 571 570 190 189 63 21 7 6 2 1
wrong: 
11
572 286 285 95 94 93 31 30 10 9 3 1

734
correct: 9
wrong: 10

740
correct: 9
wrong: 10

842
correct: 11
wrong: 12
*/

/*
정답 확인용 코드
파이썬 dAns 함수
https://claude-u.tistory.com/349
*/
/*
def dAns(N):
##    N = int(input())

	result = [[0, []] for _ in range(N + 1)] #[최솟값, 경로 리스트]
	result[1][0] = 0 #최솟값
	result[1][1] = [1] #경로를 담을 리스트

	for i in range(2, N + 1):

		#f(x-1) + 1
		result[i][0] = result[i-1][0] + 1
		result[i][1] = result[i-1][1] + [i]

		#f(x//3) + 1
		if i % 3 == 0 and result[i//3][0] + 1 < result[i][0]:
			result[i][0] = result[i//3][0] + 1
			result[i][1] = result[i//3][1] + [i]

			#f(x//2) + 1
		if i % 2 == 0 and result[i//2][0] + 1 < result[i][0]:
			result[i][0] = result[i//2][0] + 1
			result[i][1] = result[i//2][1] + [i]

##    print(result[N][0])
##    for i in result[N][1][::-1]: #뒤집은 뒤 출력
##        print(i, end=' ')
	return result[N][0]


while(True):
	N=int(input())
	l=[]
	l=map(int,input().split())
	l=list(l)
	p=l[0]
	b = True
	for i in range(0,len(l)-1):
	##    print(l[i]//l[i+1], l[i]%3, l[i]%2)
		if l[i]//l[i+1]==3 and l[i]%3==0:
			pass;
		elif l[i]//l[i+1]==2 and l[i]%2==0:
			pass;
		elif l[i]-l[i+1]==1:
			pass
		else:
			print(i)
			b=False

	ans=dAns(l[0])
	print(ans==N,b,l[0], ans, N)


*/