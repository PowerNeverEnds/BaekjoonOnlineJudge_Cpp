/**
 *    BOJ 9252
 *    - LCS 2
 *    author:  phcdream
 *    created: 오후 8:28 2020-12-14
**/
/*
https://musket-ade.tistory.com/entry/C-%EB%B0%B0%EC%97%B4-%ED%81%B4%EB%9E%98%EC%8A%A4%EC%99%80-%EC%9D%B8%EB%8D%B1%EC%8A%A4-%EC%97%B0%EC%82%B0%EC%9E%90-%EC%98%A4%EB%B2%84%EB%A1%9C%EB%94%A9
https://hwan-shell.tistory.com/43
https://pacs.tistory.com/entry/C-%EB%8C%80%EC%9E%85-%EC%97%B0%EC%82%B0%EC%9E%90-%EC%98%A4%EB%B2%84%EB%A1%9C%EB%94%A9
https://eon7500.tistory.com/10
*/
#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

template <typename T>
class MyClass
{
public:
	T* arr;
	int size=0;
	MyClass() { arr=new T[size]; }	
	MyClass(int n):size(n) {
		arr = new T[n];
	}
	MyClass(int n, T e):size(n) {
		arr = new T[n];
		T t = e;
		fill(arr, arr + n, t);
	}
	~MyClass() {
		delete[] arr;
	}
	T& operator[](int idx)
	{
		return arr[idx];
	}
	MyClass& operator=(const MyClass& ms) {
		delete[] arr;
		size = ms.size;
		arr = new T[size];
		for (int i = 0; i < size; i++)
			arr[i] = ms.arr[i];
		return *this;
	}
	MyClass(const MyClass& ref) {
		size = ref.size;
		arr = new T[size];
		for (int i = 0; i < size; i++)
			arr[i] = ref.arr[i];
	}

	//MyClass(const MyClass& ref) {}
	//MyClass& operator=(const MyClass& arr) {}

private:

};

int myMax(int a, int b)
{
	return a >= b ? a : b;
}

void in(string& str1, string& str2)
{
	cin >> str1;
	cin >> str2;

}

int* solve(string str1, string str2)
{
	str1.insert(0, " ");
	str2.insert(0, " ");
	MyClass<MyClass<int>> arr((int)str1.length()+1,MyClass<int>((int)str2.length()+1,0));
	for (int i = 1; i <= str1.length()-1; i++)
		for (int j = 1; j <= str2.length()-1; j++)
			if (str1[i] == str2[j])
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else
				arr[i][j] = myMax(arr[i - 1][j], arr[i][j - 1]);

	int* chArr = new int[(ll)arr[(int)str1.length() - 1][(int)str2.length() - 1]+1];
	int p1, p2;
	p1 = (int)str1.length() - 1;
	p2 = (int)str2.length() - 1;
	int prev = arr[p1][p2];
	int i = prev;
	chArr[0] = arr[p1][p2];
	while (true)
	{
		if (arr[p1][p2]==0)
			break;
		while (arr[--p1][p2] == prev);
		p1++;
		while (arr[p1][--p2] == prev);
		p1--;
		prev = arr[p1][p2];
		chArr[i--] = str1[(ll)p1 + 1];

	}

	return chArr;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str1, str2;
	in(str1, str2);

	int* re = solve(str1, str2);
	cout << re[0] << "\n";
	for (int i = 1; i <= re[0]; i++)
		cout << (char)re[i];
	cout << "\n";

	return 0;
}
/*

AB
CD

*/

/*
#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

template <typename T>
class MyClass
{
public:
	T* arr;
	int size = 0;
	MyClass() { arr = new T[size]; }
	MyClass(int n) :size(n) {
		arr = new T[n];
	}
	MyClass(int n, T e) :size(n) {
		//cout << "? MyClass" << size << "\n";
		arr = new T[n];
		T t = e;
		fill(arr, arr + n, t);
		//cout << "! MyClass" << size << "\n";
	}
	~MyClass() {
		//cout << "? " << size << "\n";
		//delete[] arr[0];
		//for (int i = 0; i < size; i++)
		//{
		//		delete[] arr[i];
		//}
		delete[] arr;
		//cout << "! " << size << "\n";
	}
	T& operator[](int idx)
	{
		return arr[idx];
	}
	MyClass& operator=(const MyClass& ms) {
		//cout <<"? = "<< size << "\n";
		delete[] arr;
		size = ms.size;
		arr = new T[size];
		//MyClass* tMs = new MyClass;
		for (int i = 0; i < size; i++)
		{
			//tMs->arr[i] = ms.arr[i];
			arr[i] = ms.arr[i];
		}
		//tMs->size = ms.size;
		//cout <<"! = "<< size << "\n";
		//return *tMs;
		return *this;
	}
	MyClass(const MyClass& ref) {
		//cout << ref.size << "\n";
		//cout <<"? ref "<< size << "\n";
//		delete[] arr;						// 삭제
		size = ref.size;
		arr = new T[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = ref.arr[i];
		}
		//cout <<"! ref "<< size << "\n";
	}

	//MyClass(const MyClass& ref) {}
	//MyClass& operator=(const MyClass& arr) {}

private:

};

int myMax(int a, int b)
{
	return a >= b ? a : b;
}

void in(string& str1, string& str2)
{
	cin >> str1;
	cin >> str2;

}

int* solve(string str1, string str2)
{
	str1.insert(0, " ");
	str2.insert(0, " ");
	//MyClass<int> arr(str2.length(), 0);
	//MyClass<MyClass<int>> arr(str2.length()+1, MyClass<int>(str1.length()+1,0));
	//MyClass<MyClass<int>> arr;
	//MyClass<MyClass<int>> arr(str2.length()+1);
	//MyClass<MyClass<int>> arr((int)str2.length()+1,MyClass<int>((int)str1.length()+1));
	MyClass<MyClass<int>> arr((int)str1.length() + 1, MyClass<int>((int)str2.length() + 1, 0));
	//cout << arr.size << "\n";
	//for (int i = 0; i < arr.size; i++)
	//{
	//	cout << arr[i].size << "\n";
	//	for (int j = 0; j < arr[0].size; j++)
	//	{
	//		arr[i][j] = i * j;
	//		cout <<"["<< arr[i][j]<<"]" << " ";
	//	}cout << "\n";
	//}cout << "\n";
	for (int i = 1; i <= str1.length() - 1; i++)
	{
		for (int j = 1; j <= str2.length() - 1; j++)
		{
			if (str1[i] == str2[j])
			{
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else
			{
				arr[i][j] = myMax(arr[i - 1][j], arr[i][j - 1]);
			}
			//cout << arr[i][j] << " ";
		}
		//cout << "\n";
	}
	//cout << "\n";

	int* chArr = new int[(ll)arr[(int)str1.length() - 1][(int)str2.length() - 1] + 1];
	int p1, p2;
	p1 = (int)str1.length() - 1;
	p2 = (int)str2.length() - 1;
	int prev = arr[p1][p2];
	int i = prev;
	chArr[0] = arr[p1][p2];
	while (true)
	{
		//cout << p1 << " " << p2 << "\n";
		if (arr[p1][p2] == 0)
			break;
		while (arr[--p1][p2] == prev);
		p1++;
		while (arr[p1][--p2] == prev);
		p1--;
		prev = arr[p1][p2];
		chArr[i--] = str1[(ll)p1 + 1];
		//cout << str1[(ll)p1+1]<<" ";

	}
	//for (int i = 1; i <= chArr[0]; i++)
	//{
	//	cout << (char)(chArr[i]);
	//}
	//cout << str1 << " " << str2 << "\n";


	return chArr;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str1, str2;
	in(str1, str2);

	int* re = solve(str1, str2);
	//cout << str1 << " " << str2 << "\n";
	cout << re[0] << "\n";
	for (int i = 1; i <= re[0]; i++)
	{
		cout << (char)re[i];
	}cout << "\n";

	return 0;
}
*/