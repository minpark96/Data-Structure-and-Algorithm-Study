#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#pragma region 최초 풀이

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int n, m, a[54][54];
int min_ret = 2147483647;
vector<pair<int, int>> h, c;
vector<int> v;
//
//int bfs(int y, int x)
//{
//	queue<pair<int, int>> que;
//	que.push({ y, x });
//
//	while (que.size() != 0)
//	{
//		y = que.front().first;
//		x = que.front().second;
//		que.pop();
//		if (a[y][x] == 2) break;
//		for (int i = 0; i < 4; i++)
//		{
//
//			int ny = dy[i] + y;
//			int nx = dx[i] + x;
//			if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] == 1) continue;
//			que.push({ ny, nx });
//			visited[ny][nx] = visited[y][x] + 1;
//		}
//	}
//
//	return visited[y][x];
//}

void comb(int curr, int size, int dest)
{
	if (v.size() == dest)
	{
		/*for (int i = 0; i < c.size(); i++)
		{
			a[c[i].first][c[i].second] = 0;
		}
		for (int j = 0; j < v.size(); j++)
		{
			a[c[v[j]].first][c[v[j]].second] = 2;
		}*/
		int sum = 0;
		for (pair<int, int> p : h)
		{
			int temp = 2147483647;
			for (int z = 0; z < v.size(); z++)
			{
				temp = min(temp, abs(p.first - c[v[z]].first) + abs(p.second - c[v[z]].second));
			}
			sum += temp;
			//temp += bfs(p.first, p.second);
			
			//fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
		}
		min_ret = min(min_ret, sum);
		/*for (int i = 0; i < c.size(); i++)
		{
			a[c[i].first][c[i].second] = 2;
		}*/
	}
	for (int j = curr; j < c.size(); j++)
	{
		v.push_back(j);
		comb(j + 1, v.size(), dest);
		v.pop_back();
	}
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

	for (int i = m; i > 0; i--)
	{
		comb(0, 0, i);
	}

	cout << min_ret << "\n";

	return 0;
}

#pragma endregion