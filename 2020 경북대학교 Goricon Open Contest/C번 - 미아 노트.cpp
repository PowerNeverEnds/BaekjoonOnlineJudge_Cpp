#include <iostream>
#include <string>

using namespace std;

char arr[1001][1001];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, H, W;
	cin >> N >> H >> W;
	for (int i = 0; i < H; i++)
	{
		string str;
		cin.ignore();
		cin >> str;
		//cout << str << "\n";
		for (int j = 0; j < W*N; j++)
		{
			arr[i][j] = str[j];
		}
	}
	//for (int i = 0; i < H; i++)
	//{
	//	for (int j = 0; j < W*N; j++)
	//	{
	//		cout << arr[i][j];
	//	}cout << "\n";
	//}
	char chStr[100];
	fill(chStr, chStr + 100, '?');
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W*N; j++)
		{
			if (arr[i][j] != '?')
			{
				//cout << i << " " << j << " " << arr[i][j] << "\n";
				chStr[j / W]=arr[i][j];
			}
		}
	}
	for (int i = 0; i < N; i++)
		cout << chStr[i];
	cout << "\n";

	return 0;
}