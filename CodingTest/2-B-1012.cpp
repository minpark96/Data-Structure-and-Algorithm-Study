#include <iostream>
#include <string.h>

using namespace std;

#pragma region 최초 풀이

/*
	주어진 맵에서 섬 개수 찾기와 같은 개념 - dfs로 한다
*/

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int t, n, m, k, ret;
int map[52][52];
bool visited[52][52];

void dfs(int y, int x)
{
	visited[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (map[ny][nx] == 0 || visited[ny][nx]) continue;
		dfs(ny, nx);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	for (int i = t; i > 0; i--)
	{
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		//fill(&map[0][0], &map[0][0] + 51 * 51, 0);
		//fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		ret = 0;

		cin >> m >> n >> k;
		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				if (map[y][x] && !visited[y][x])
				{
					dfs(y, x);
					ret++;
				}
			}
		}

		cout << ret << "\n";
	}

	return 0;
}

#pragma endregion