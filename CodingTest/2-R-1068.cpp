#include <iostream>
#include <set>
#include <vector>
using namespace std;

/*
	입력이 뒤죽박죽일 수 있는데 예제만 테스트하다가 실패
	root 인덱스가 항상 0인게 아니다...
*/

#pragma region 최초 풀이 - 오답(이유 모르겠음)

//int n, t, ret, node[54];
//set<int> s1, s2;
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> node[i];
//	}
//	cin >> t;
//	s1.insert(t);
//	for (int i = 1; i < n; i++)
//	{
//		if (s1.count(node[i]) == 1)
//			s1.insert(i);
//	}
//	for (int i = n - 1; i > -1; i--)
//	{
//		if (s1.count(i) == 1) continue;
//		if (s2.count(i) == 0) ret++;
//		s2.insert(node[i]);
//	}
//	cout << ret << "\n";
//	return 0;
//}

#pragma endregion

#pragma region 최초 풀이 - 정답 참조

int n, t, root;
vector<vector<int>> v(50);

int dfs(int idx)
{
	int ret = 0;
	int child = 0;
	for (int a : v[idx])
	{
		if (a == t) continue;
		ret += dfs(a);
		child++;
	}
	if (child == 0) return 1;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp == -1) root = i;
		else v[temp].push_back(i);
	}
	cin >> t;
	if (t == root)
	{
		cout << 0 << "\n";
		return 0;
	}
	cout << dfs(root) << "\n";
	return 0;
}

#pragma endregion