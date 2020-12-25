/**
 *    BOJ 1509
 *    - 팰린드롬 분할
 *    author:  phcdream
 *    created: 오후 10:06 2020-12-18
**/

#include <iostream>
#include <string>
#include <queue>
#include <vector>

typedef long long ll;

#define ALL false
#define dfor if(true && ALL) for
#define dout if(true && ALL) cout

#define SINGLE 1
#define DOUBLE 2

using namespace std;

void setMem(int s, vector<int>**& mem, string& str, int len, int type)
{
	int typeInd=0;
	switch (type)
	{
	case SINGLE:
		typeInd = 0;
		break;
	case DOUBLE:
		typeInd = 1;
		break;
	default:
		break;
	}

	for (int i = 0; i < len; i++)
	{
		int l = s - i;
		int r = s + i + typeInd;
		if (l < 0 || len <= r)
			break;
		if (str[l] != str[r])
			break;
		//if (mem[type][l] < i * 2 + typeInd)
			//mem[type][l] = i * 2 + typeInd;
		mem[type][l].push_back(i * 2 + typeInd);
	}
}

void print(int& len, int*& visited)
{
	dfor(int i = 0; i <= len; i++)
	{
		dout << visited[i] << " ";
	}
	dout << "\n";
}

int bfs(vector<int>**& mem, int len)
{
	int* visited = new int[(ll)len + 1];
	fill(visited, visited + len + 1, 0);

	int st = 0;
	queue<int> q;
	visited[st] = 1;
	q.push(st);
	while (true)
	{
		print(len, visited);
		if (q.empty())
			break;
		st = q.front();
		q.pop();
		for (int i = 1; i <= 2; i++)
		{
			for (auto e : mem[i][st])
			{
				//			int e = mem[i][st];
				if (visited[st + e + 1] == 0)
				{
					visited[st + e + 1] = visited[st] + 1;
					q.push(st + e + 1);
					if (st + e + 1 == len)
						return visited[st + e + 1];
				}
			}
		}
		if (visited[st + 1] == 0)
		{
			visited[st + 1] = visited[st] + 1;
			q.push(st + 1);
			if (st + 1 == len)
				return visited[st + 1];
		}
	}

	return -1;
}

int solve(string& str)
{
	int len = (int)str.length();
	vector<int>** mem = new vector<int> * [3];
	fill(mem, mem + 3, nullptr);
	for (int i = 0; i < 3; i++)
	{
		mem[i] = new vector<int>[(ll)len + 1];
		//fill(mem[i], mem[i] + len + 1, 0);
	}

	for (int i = 0; i < len; i++)
	{
		setMem(i, mem, str, len,SINGLE);
		setMem(i, mem, str, len, DOUBLE);
	}

	dfor (int k = 1; k <= 2; k++)
	{
		dfor(int i = 0; i < len; i++)
		{
			dout << mem[k][i].size() << " ";
		}
		dout << "\n";
	}
	dout << "\n";

	int re = bfs(mem, len);
	return re - 1;
}

int main()
{
	string str;
	cin >> str;
	dfor(auto e: str)
		dout << e << " ";
	dout << "\n";

	int re = solve(str);
	cout << re << "\n";
	dfor(int i = 0; i < str.length(); i++)
	{
		if (i < 10)
		{
			dout << str[i] << " ";
		}
		else
		{
			dout << str[i] << " ";
		}
	}
	dout << "\n";
	return 0;
}
/*

BBCDDECAECBDABADDCEBACCCBDCAABDBADD

CBDABADDCEBACCCBDCAABDBADD

BB C DD E C A E C B DABAD D C E B A CCC B D C A ABDBA DD
1  2 3  4 5 6 7 8 9 10    111213141516  1718192021    22

BCAC
BCACB
BCACBB
BCACBC
BBCACBC
BBCACBB

A
AA
AAA
AAAA
AB
ABA
ABAB
ABABA
ABAAB
ABCCAB
AACCBB
AAACCABA
AAACCACA
AAACCACAC
AAACCACACAAACCACAC
AAA CC ACA CAAAC CACAC
*/