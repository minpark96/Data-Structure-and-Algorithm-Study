#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

#pragma region ���� Ǯ��

/*
	�̷� �Է��� �پ �����Ƿ� ���ڿ��� �޾Ƽ� ó��
	�ִ� �Ÿ��� ���ϹǷ� dfs�� �ƴ϶� bfs�� ó��
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
		// tie(y, x) = q.front(); => �ѹ��� �ޱ�
		//cout << y << " : " << x << " : " << visited[y][x] << "\n";
		que.pop();
		//if (y == n && x == m) break; => ������ ���̴ϱ� �Ź� üũ�ϴ°� �� ����
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
			// scanf("%1d", &maze[i][j]); => ���� �� �ڸ��� �ޱ�
		}
	}

	/*cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << maze[i][j]; // ��¿�
		}
		cout << "\n";
	}*/

	bfs(0, 0);
	cout << visited[n - 1][m - 1];
	return 0;
}

#pragma endregion


