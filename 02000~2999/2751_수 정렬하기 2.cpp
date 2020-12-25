#include <iostream>

typedef long long ll;

#define dout if(false) cout

using namespace std;

void out(int&, int*&);

void in(int& N, int*& arr)
{
	cin >> N;
	arr = new int[(ll)N + 1];
	fill(arr, arr + N + 1, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
}


void myMerge(int*& arr, int l, int mid, int r, int*& tArr)
{
	int i = l;
	int j = mid+1;
	int p = l;
	//fill(tArr + l, tArr + r, 0);
	while (true)
	{
		if (i <= mid && j <= r)
		{
		}
		else
			break;
		if (i<=mid && arr[i] <= arr[j])
		{
			tArr[p] = arr[i];
			i++;
		}
		else if (j <= r && arr[i] > arr[j])
		{
			tArr[p] = arr[j];
			j++;
		}
		p++;
	}

	while (true)
	{
		if (i <= mid)
		{
		}
		else
			break;
		tArr[p] = arr[i];
		p++; i++;
	}

	while (true)
	{
		if (j <= r)
		{
		}
		else
			break;
		tArr[p] = arr[j];
		p++; j++;
	}


	//	copy
	for (int i = l; i <= r; i++)
		arr[i] = tArr[i];
}

void myMergeSort(int*& arr, int l, int r,int*& tArr)
{
	dout << l << " " << r << "\n";
	if (l >= r)
		return;
	//	divide
	int mid = (l + r) / 2;
	//	conquer
	myMergeSort(arr, l, mid,tArr);
	myMergeSort(arr, mid + 1, r,tArr);
	//	combine
	dout << l << " " << mid << " " << r << "\n";
	myMerge(arr, l, mid, r,tArr);

	//int a = 5;
	//out(a, arr);
}

void solve1(int& N, int*& arr)
{
	int* tArr = new int[(ll)N+1];
	myMergeSort(arr, 0, N - 1,tArr);
}

void out(int& N, int*& arr)
{
	for (int i = 0; i < N; i++)
		cout << arr[i] << "\n";
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	int* arr;
	in(N, arr);

	solve1(N, arr);
	out(N, arr);

	return 0;
}