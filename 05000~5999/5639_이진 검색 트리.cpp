/**
 *    BOJ 5639
 *    - 이진 검색 트리
 *    author:  phcdream
 *    created: 오후 9:41 2020-12-09
**/

#include <iostream>

using namespace std;

void defPostorder(int l, int r, int*& arr, int*& postorder, int& ind)
{
	if (l > r)
		return;
	int i;
	for (i = l + 1; i <= r; i++)
	{
		if (arr[l] < arr[i])
		{
			break;
		}
	}
	int size = i - l;
	//cout << l << " " << r << "  " << size << " " << i << "\n";
	defPostorder(l + 1, i - 1, arr, postorder, ind);
	defPostorder(i - 1 + 1, r, arr, postorder, ind);
	postorder[ind++] = arr[l];
}

int main()
{
	int* arr = new int[10001];
	fill(arr, arr + 10001, 0);
	int n;
	int i;
	for (i = 1;; i++)
	{
		if (!(cin >> n))
			break;
		arr[i] = n;
	}
	arr[0] = i - 1;
	int* postorder = new int[10001];
	fill(postorder, postorder + 10001, 0);

	int ind = 1;
	postorder[0] = arr[0];
	defPostorder(1, arr[0], arr, postorder, ind);
	
	for (int i = 1; i <= postorder[0]; i++)
	{
		cout << postorder[i] << "\n";
	}

	return 0;
}