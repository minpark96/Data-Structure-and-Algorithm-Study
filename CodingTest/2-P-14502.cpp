#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int a[10][10], visited[10][10];
vector<pair<int, int>> vEmpty, vVirus;
int nVirus, ret, nWall;
int n, m;

void dfs(int y, int x)
{
	visited[y][x] = 1;
	nVirus++;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (a[ny][nx] == 1 || !visited[ny][nx]) continue;
		dfs(ny, nx);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 0)
				vEmpty.push_back({ i,j });
			else if (a[i][j] == 2)
				vVirus.push_back({ i,j });
			else
				nWall++;
		}
	}
	nWall += 3;
	for (int i = 0; i < vEmpty.size() - 2; i++)
	{
		for (int j = i; j < vEmpty.size() - 1; j++)
		{
			for (int k = j; k < vEmpty.size(); k++)
			{
				memset(visited, 0, sizeof(visited));
				nVirus = 0;
				a[vEmpty[i].first][vEmpty[i].second] = 1;
				a[vEmpty[j].first][vEmpty[j].second] = 1;
				a[vEmpty[k].first][vEmpty[k].second] = 1;
				for (int l = 0; l < vVirus.size(); l++)
				{
					if (visited[vVirus[l].first][vVirus[l].second] == 0)
						dfs(vVirus[l].first, vVirus[l].second);
				}
				ret = max(ret, n * m - (nWall + nVirus));
				a[vEmpty[i].first][vEmpty[i].second] = 0;
				a[vEmpty[j].first][vEmpty[j].second] = 0;
				a[vEmpty[k].first][vEmpty[k].second] = 0;
			}
		}
	}

	cout << ret << "\n";

	return 0;
}