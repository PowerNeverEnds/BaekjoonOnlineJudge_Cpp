/**
 *    BOJ 2263
 *    - 트리의 순회
 *    author:  phcdream
 *    created: 오후 7:41 2020-12-09
**/

#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

void defPreorder(int inL, int inR, int poL, int poR, vector<int>& inorder, vector<int>& postorder,vector<int>& preorder, vector<int>& indInorder)
{
	if (inL > inR	|| poL>poR)		// 추가
		return;
	if (inL == inR)		// 추가
	{
		//cout << inorder[inL] << "\n";
		preorder.push_back(inorder[inL]);
		return;
	}
	int i;
	//for (i = inL; i <= inR; i++)
	//{
	//	if (inorder[i] == postorder[poR])
	//		break;
	//}
	i = indInorder[postorder[poR]];
	//cout << inorder[i] << "\n";
	preorder.push_back(inorder[i]);
	int size = ((i - 1 - inL));
	defPreorder(inL, i - 1, poL, poL + size, inorder, postorder, preorder, indInorder);
	defPreorder(i + 1, inR, poL + size + 1, poR - 1, inorder, postorder, preorder,indInorder);
}

int main()
{
	int n;
	cin >> n;
	vector<int> inorder;
	vector<int> postorder;
	for (int i = 0; i < n; i++)
	{
		int e;
		cin >> e;
		inorder.push_back(e);
	}
	for (int i = 0; i < n; i++)
	{
		int e;
		cin >> e;
		postorder.push_back(e);
	}
	vector<int> indInorder(100001);
	for (int i = 0; i < n; i++)
	{
		indInorder[inorder[i]] = i;
	}

	vector<int> preorder;
	defPreorder(0,inorder.size()-1,0,postorder.size()-1,inorder, postorder,preorder,indInorder);
	for (auto e : preorder)
		cout << e << " ";
	cout << "\n";

	return 0;
}