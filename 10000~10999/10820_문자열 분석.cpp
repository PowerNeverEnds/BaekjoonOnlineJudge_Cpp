#include <iostream>
#include <string>

using namespace std;

int main()
{
	while (true)
	{
		string str;
		//cin.ignore();
		getline(cin, str);
		if (cin.eof())
			break;
		int low, up, num, sp;
		low = up = num = sp = 0;
		for (auto e : str)
		{
			if (islower(e))
				low++;
			if (isupper(e))
				up++;
			if (isdigit(e))
				num++;
			if (isspace(e))
				sp++;
		}

		cout << low << " " << up << " " << num << " " << sp << "\n";
	}

	return 0;
}