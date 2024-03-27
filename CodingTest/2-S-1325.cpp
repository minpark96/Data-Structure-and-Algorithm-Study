#include <iostream>
#include <vector>
using namespace std;

/*
	ó���� visited�� �����ߴٰ� Ÿ�Ӿƿ��� ����
	visited�� ���鼭 dp���䵵 ���� ����Ϸ��� �ߴµ�
	�׷��� �ϴ� 1-2 2-1 �� ���� ������ ����� ���迡�� ������ �־���
	���� dp�� ������� �ʴ� ���̴�. visited�� �� �� �������� ���� ������ ���°͸� �����ϴ� ���� �����̴�.
	visited�� ������ �Ź� �ʱ�ȭ�ϸ鼭 ��� �������� ��ŸƮ�ϴ� ���� üũ�ؾ� �Ѵ�.
*/

#pragma region ���� Ǯ�� - ���� ����

int n, m, maxV;
vector<int> v[10004];
int com[10004], visited[10004];

int dfs(int here)
{
	visited[here] = 1;
	int ret = 1;
	for (int there : v[here])
	{
		if (visited[there]) continue;
		ret += dfs(there);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}

	for (int i = 1; i < n + 1; i++)
	{
		fill(&visited[0], &visited[0] + 10004, 0);
		com[i] = dfs(i);
		maxV = max(maxV, com[i]);
	}

	for (int i = 1; i < n + 1; i++)
	{
		if (com[i] == maxV)
			cout << i << ' ';
	}
	cout << "\n";

	return 0;
}

#pragma endregion