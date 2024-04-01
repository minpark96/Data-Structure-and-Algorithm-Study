#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*
	거리를 측정하기 위해서 visited[y][x]를 거리 측정으로 사용하다가 출발 지점으로 돌아가버리는 경우를 배제하지 않았다.
*/

#pragma region 최초 풀이

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int n, m, a[54][54], visited[54][54];
int result;

int bfs(int y, int x)
{
	queue<pair<int, int>> que;
	que.push({ y, x });
	visited[y][x] = 1;
	while (que.size())
	{
		y = que.front().first;
		x = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 0 || visited[ny][nx] > 0) continue;
			que.push({ ny, nx });
			visited[ny][nx] = visited[y][x] + 1;
		}
	}
	return visited[y][x] - 1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] == 'W') a[i][j] = 0;
			else if (s[j] == 'L') a[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 1)
			{
				fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
				result = max(result, bfs(i, j));
			}
		}
	}
	cout << result << "\n";
	return 0;
}

#pragma endregion