#include <iostream>
#include <vector>
using namespace std;

int dy[] = { -1, 0 ,1,0 };
int dx[] = { 0, 1, 0, -1 };
int a[104][104], visited[104][104];
int n, m, t, ret;
vector<pair<int, int>> next;

// 1. (0, 0)에서 dfs 때려서 내부 구멍 조사 -> 외부 0, 치즈1, 최외곽2, 내부 구멍3
// 2. 한바퀴 돌면서 최외곽인 칸 조사 및 치즈 개수 조사
// 3. 최외곽인 칸 외부로 변경, 1부터 반복

void dfs(int y, int x)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];


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

	while (true)
	{
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		dfs(0, 0);
	}

	return 0;
}