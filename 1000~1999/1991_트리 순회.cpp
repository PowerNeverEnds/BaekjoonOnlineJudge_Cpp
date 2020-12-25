#include <iostream>
#include <vector>
#include <cctype>

typedef long long ll;

using namespace std;

struct MyStruct
{
	int l;
	int r;
};

void preorderTraversal(char n,vector<MyStruct>& tree)
{
	if (!isalpha(n))
		return;
	cout << n;
	preorderTraversal(tree[n].l, tree);
	preorderTraversal(tree[n].r, tree);
}

void inorderTraversal(char n, vector<MyStruct>& tree)
{
	if (!isalpha(n))
		return;
	inorderTraversal(tree[n].l, tree);
	cout << n;
	inorderTraversal(tree[n].r, tree);
}

void postorderTraversal(char n, vector<MyStruct>& tree)
{
	if (!isalpha(n))
		return;
	postorderTraversal(tree[n].l, tree);
	postorderTraversal(tree[n].r, tree);
	cout << n;
}
int main()
{
	int N;
	cin >> N;
	vector<MyStruct> tree('A' + (ll)N + 1);
	for (int i = 0; i < N; i++)
	{
		char n, l, r;
		cin >> n >> l >> r;
		tree[n]= MyStruct({ l,r });
	}

	preorderTraversal('A',tree);
	cout << "\n";

	inorderTraversal('A', tree);
	cout << "\n";

	postorderTraversal('A', tree);
	cout << "\n";


	return 0;
}