#include <iostream>
#include <vector>
using namespace std;

/*
	처음에 visited를 사용안했다가 타임아웃이 떠서
	visited를 쓰면서 dp개념도 같이 사용하려고 했는데
	그렇게 하니 1-2 2-1 과 같은 쌍으로 연결된 관계에서 문제가 있었고
	답은 dp를 사용하지 않는 것이다. visited는 딱 그 정점에서 무한 루프를 도는것만 방지하는 것이 목적이다.
	visited를 쓰지만 매번 초기화하면서 모든 정점에서 스타트하는 것을 체크해야 한다.
*/

#pragma region 최초 풀이 - 정답 참조

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