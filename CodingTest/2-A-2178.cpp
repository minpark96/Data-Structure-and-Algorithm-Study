#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

#pragma region 최초 풀이

/*
	미로 입력이 붙어서 들어오므로 문자열로 받아서 처리
	최단 거리를 구하므로 dfs가 아니라 bfs로 처리
*/

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int n, m, cnt;
string ipt;
queue<pair<int, int>> que;
int maze[104][104];
int visited[104][104];

void bfs(int y, int x)
{
	visited[y][x] = 1;
	que.push({ y, x });
	while (!que.empty())
	{
		y = que.front().first;
		x = que.front().second;
		// tie(y, x) = q.front(); => 한번에 받기
		//cout << y << " : " << x << " : " << visited[y][x] << "\n";
		que.pop();
		//if (y == n && x == m) break; => 어차피 끝이니깐 매번 체크하는게 더 손해
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

			if (maze[ny][nx] && !visited[ny][nx])
			{
				que.push({ ny, nx });
				visited[ny][nx] = visited[y][x] + 1;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> ipt;
		for (int j = 0; j < m; j++)
		{
			maze[i][j] = ipt[j] - '0';
			// scanf("%1d", &maze[i][j]); => 정수 한 자리씩 받기
		}
	}

	/*cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << maze[i][j]; // 출력용
		}
		cout << "\n";
	}*/

	bfs(0, 0);
	cout << visited[n - 1][m - 1];
	return 0;
}

#pragma endregion


