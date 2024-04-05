#include <iostream>
#include <vector>
using namespace std;

#pragma region 최초 풀이

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int n, l, r, a[54][54], visited[54][54], ret;

int dfs(int y, int x, vector<pair<int, int>>& v)
{
	visited[y][x] = 1;
	v.push_back({ y,x });
	int sum = a[y][x];
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (visited[ny][nx] == 1) continue;
		int gap = abs(a[y][x] - a[ny][nx]);
		if (gap >= l && gap <= r) sum += dfs(ny, nx, v);
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	while (true)
	{
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visited[i][j] == 0)
				{
					vector<pair<int, int>> v;
					int sum = dfs(i, j, v);
					int cnt = v.size();
					if (cnt > 1)
					{
						sum /= cnt;
						for (pair<int, int> p : v)
						{
							a[p.first][p.second] = sum;
						}
						flag = true;
					}
				}
			}
		}
		if (flag == false) break;
		ret++;
		fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
	}
	cout << ret << "\n";
	return 0;
}

#pragma endregion