#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int* A = new int[N];
	int* B = new int[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];
	
	sort(A, A + N, [](auto a, auto b) {
		return a < b;
		});
	sort(B, B + N, [](auto a, auto b) {
		return a > b;
		});
	
	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += A[i] * B[i];
	
	cout << sum << "\n";

	return 0;
}