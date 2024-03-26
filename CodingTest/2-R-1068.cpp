#include <iostream>
#include <set>
using namespace std;

#pragma region 최초 풀이 - 오답(이유 모르겠음)

int n, t, ret, node[54];
set<int> s1, s2;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> node[i];
	}
	cin >> t;
	s1.insert(t);
	for (int i = 1; i < n; i++)
	{
		if (s1.count(node[i]) == 1)
			s1.insert(i);
	}
	for (int i = n - 1; i > -1; i--)
	{
		if (s1.count(i) == 1) continue;
		if (s2.count(i) == 0) ret++;
		s2.insert(node[i]);
	}
	cout << ret << "\n";
	return 0;
}

#pragma endregion