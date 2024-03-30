#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int n, m, a[54][54], visited[54][54];
vector<pair<int, int>> h, c;

int bfs(int y, int x, int ty, int tx)
{
	int ret = -1;
	queue<pair<int, int>> que;
	que.push({ y, x });

	while (que.size() != 0)
	{
		y = que.front().first;
		x = que.front().second;
		que.pop();
		if (visited[y][x] == 1) continue;
		visited[y][x] = 1;
		ret++;
		if (y == ty && x == tx) break;
		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] == 1) continue;
			que.push({ ny, nx });
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
				h.push_back({ i, j });
			else if (a[i][j] == 2)
				c.push_back({ i, j });
		}
	}



	return 0;
}
