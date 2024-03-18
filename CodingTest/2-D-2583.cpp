#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	기존 문제들과 비슷한 연결된 컴포넌트 문제인데 넓이를 구해가는 방식을
	void형 dfs를 사용할 건지 int형을 사용할 건지의 차이가 있다.
*/

#pragma region 최초 풀이

//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//int m, n, k, temp;
//int ly, lx, ry, rx;
//int paper[102][102];
//int visited[102][102];
//vector<int> rets;
//
//void dfs(int y, int x)
//{
//	visited[y][x] = true;
//	temp++;
//	for (int i = 0; i < 4; i++)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
//		if (paper[ny][nx] == 0 && visited[ny][nx] == 0) dfs(ny, nx);
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	cin >> m >> n >> k;
//	for (int i = 0; i < k; i++)
//	{
//		cin >> ly >> lx >> ry >> rx;
//		for (int j = ly; j < ry; j++)
//		{
//			for (int k = lx; k < rx; k++)
//			{
//				paper[j][k]++;
//			}
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (paper[i][j] == 0 && visited[i][j] == 0)
//			{
//				temp = 0;
//				dfs(i, j);
//				rets.push_back(temp);
//			}
//		}
//	}
//
//	sort(rets.begin(), rets.end());
//	cout << rets.size() << "\n";
//	for (int i : rets)
//	{
//		cout << i << "\n";
//	}
//
//	return 0;
//}

#pragma endregion

#pragma region 개선 - int 반환형 dfs

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int m, n, k;
int ly, lx, ry, rx;
int paper[102][102];
int visited[102][102];
vector<int> rets;

int dfs(int y, int x)
{
	visited[y][x] = true;
	int ret = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (paper[ny][nx] == 0 && visited[ny][nx] == 0) 
			ret += dfs(ny, nx);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> ly >> lx >> ry >> rx;
		for (int j = ly; j < ry; j++)
		{
			for (int k = lx; k < rx; k++)
			{
				paper[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (paper[i][j] == 0 && visited[i][j] == 0)
			{
				rets.push_back(dfs(i, j));
			}
		}
	}

	sort(rets.begin(), rets.end());
	cout << rets.size() << "\n";
	for (int i : rets) cout << i << "\n";

	return 0;
}

#pragma endregion