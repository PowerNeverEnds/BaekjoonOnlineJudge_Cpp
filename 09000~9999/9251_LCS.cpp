/*
ACAYKP
CAPCAK

4
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str1, str2;

	cin >> str1 >> str2;

//	int** c = new int* [str1.length() + 1];		// C6001 초기화 되지 않은 메모리 사용
	int** c = new int* [str1.length() + 1]();	// C6011 NULL 포인터 c[i-1]를 역참조 하고 있습니다.
	for (int i = 0; i < str1.length() + 1; i++)
	{
		c[i] = new int[str2.length() + 1]();
		//		memset(c[i], 0, sizeof(int) * (str2.length() + 1));
		//for (int j = 0; j < str2.length() + 1; j++)
		//{
		//	c[i][j] = 0;
		//}
	}
	for (int i = 0; i < str1.length() + 1; i++)
	{
		for (int j = 0; j < str2.length() + 1; j++)
		{
			c[i][j] = 0;
		}
	}
	// int -> unsigned int 이유) c26451 산술 오버플로: 4바이트 값에 '-' 연산자를 사용한 다음 결과를 8바이트 값에
	for (unsigned int i = 1; i < str1.length() + 1; i++)
	{
		for (unsigned int j = 1; j < str2.length() + 1; j++)
		{
			if (str1[i-1] == str2[j-1])
			{
				if(c[i-1] )
					c[i][j] = c[i - 1][j - 1] + 1;
			}
			else
			{
				if(c[i-1])
					c[i][j] = c[i - 1][j] > c[i][j - 1] ? c[i - 1][j] : c[i][j - 1];
			}
		}
	}
	if(c[str1.length()])
		cout << c[str1.length()][str2.length()]<<"\n";
	//for (int i = 0; i < str1.length() + 1; i++)
	//{
	//	for (int j = 0; j < str2.length() + 1; j++)
	//	{
	//		if(c[i])
	//			cout << c[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	return 0;
}