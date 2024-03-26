#include <iostream>
#include <vector>
using namespace std;

// 1. (0, 0)에서 dfs 때려서 내부 구멍 조사 -> 외부 3, 치즈 1, 최외곽 2, 내부 구멍 0
// 2. 한바퀴 돌면서 최외곽인 칸 조사 및 치즈 개수 조사
// 3. 최외곽인 칸 외부로 변경, 1부터 반복

#pragma region 최초 풀이

int dy[] = { -1, 0 ,1,0 };
int dx[] = { 0, 1, 0, -1 };
int a[104][104], visited[104][104];
int n, m, t, ret;
vector<pair<int, int>> next;

void dfs(int y, int x)
{
	a[y][x] = 3;
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx > m) continue;
		if (a[ny][nx] == 1 || visited[ny][nx] == 1) continue;
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
		}
	}
	
	int temp = 0;
	do
	{ 
		t++;
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		dfs(0, 0);
		ret = 0;
		for (int i = 1; i < n - 1; i++)
		{
			for (int j = 1; j < m - 1; j++)
			{
				if (a[i][j] == 1)
				{
					ret++;
					for (int k = 0; k < 4; k++)
					{
						int ny = i + dy[k];
						int nx = j + dx[k];
						if (a[ny][nx] == 3)
						{
							a[i][j] = 2;
							break;
						}
					}
				}
			}
		}

		temp = 0;
		for (int i = 1; i < n - 1; i++)
		{
			for (int j = 1; j < m - 1; j++)
			{
				if (a[i][j] == 2)
				{
					temp++;
					a[i][j] = 3;
				}
			}
		}
	} while (temp != ret);

	cout << t << "\n" << ret << "\n";

	return 0;
}

#pragma endregion