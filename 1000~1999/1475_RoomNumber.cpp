#include <iostream>
#include <string>
using namespace std;

void find(string str, int* number);
int convert(char ch);

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	getline(cin, str);

	int number[10] = {0,};
	find(str,number);
	int max = -1;
	for (int i = 0; i < 10; i++)
	{
		if (i == 6 || i == 9)
			continue;
		if (max < number[i])
			max = number[i];
	}
	if (max < (number[6] + number[9]+1) / 2)	// 1 Àº ¿Ã¸²
		max = (number[6] + number[9]+1) / 2;

	cout << max << "\n";
	return 0;
}

void find(string str, int* number)
{
	for (int i = 0; i < str.length(); i++)
	{
		number[convert(str[i])]++;
	}
}

int convert(char ch)
{
	return (int)(ch - '0');
}