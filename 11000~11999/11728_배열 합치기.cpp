#include <iostream>
#include <vector>

using namespace std;

void vecPB(int size, vector<int>& vec)
{
	for (int i = 0; i < size; i++)
	{
		int e;
		cin >> e;
		vec.push_back(e);
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int aSize, bSize;
	cin >> aSize >> bSize;
	vector<int> aVec;
	vector<int> bVec;
	vecPB(aSize, aVec);
	vecPB(bSize, bVec);
	int ap;
	int bp;
	ap = bp = 0;
	vector<int> out;
	while (true)
	{
		if (!(ap < aSize) && !(bp < bSize))
			break;
		else if ((ap < aSize) != (bp < bSize))
		{
			if (ap < aSize)
			{
				out.push_back(aVec[ap++]);
			}
			else if (bp < bSize)
			{
				out.push_back(bVec[bp++]);
			}
		}
		else if (aVec[ap] < bVec[bp])
		{
			out.push_back(aVec[ap++]);
		}
		else
			out.push_back(bVec[bp++]);
	}

	for (auto e : out)
		cout << e << " ";

	return 0;
}