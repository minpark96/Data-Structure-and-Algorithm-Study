#include <iostream>
#include <set>
#include <string.h>

using namespace std;

/*
	연결된 컴포넌트 문제이나 잠긴 높이에 따라 반복 수행한다.
	잠긴 높이를 모두 확인하는 것보다 특정값만 확인하는게 빠르다 생각하여 set을 사용하였는데 사용법이 쉽지 않았다.
	미리 잠긴 높이를 감하여 0, 1로 만든 배열을 사용하는 방법,
	dfs 함수 내에서 depth를 매개변수로 받아서 체크하는 방법 두가지가 있는데
	의외로 dfs 내에서 하는 방법이 메모리를 더 사용하였다.
*/

#pragma region 최초 풀이

//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//int n, maxR;
//set<int> m;
//int visited[102][102];
//int height[102][102];
//int a[102][102];
//
//void dfs(int y, int x)
//{
//	visited[y][x] = true;
//	
//	for (int i = 0; i < 4; i++)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
//		if (a[ny][nx] == 0 || visited[ny][nx]) continue;
//		dfs(ny, nx);
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//	cin >> n;
//	
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> height[i][j];
//			m.insert(height[i][j]);
//		}
//	}
//	maxR = 1;
//	set<int>::iterator iter;
//	for (iter = m.begin(); iter != m.end(); iter++)
//	{
//		memset(visited, 0, sizeof(visited));
//		int r = 0;
//		
//		for (int j = 0; j < n; j++)
//		{
//			for (int k = 0; k < n; k++)
//			{
//				if (height[j][k] - *iter > 0)
//					a[j][k] = 1;
//				else
//					a[j][k] = 0;
//			}
//		}
//
//		for (int j = 0; j < n; j++)
//		{
//			for (int k = 0; k < n; k++)
//			{
//				if (a[j][k] == 1 && !visited[j][k])
//				{
//					dfs(j, k);
//					r++;
//				}
//			}
//		}
//
//		maxR = max(r, maxR);
//	}
//
//	cout << maxR;
//
//	return 0;
//}

#pragma endregion

#pragma region 개선

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int n, maxR;
set<int> s;
int visited[102][102];
int height[102][102];

void dfs(int y, int x, int depth)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (height[ny][nx] > depth && !visited[ny][nx])
			dfs(ny, nx, depth);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> height[i][j];
			s.insert(height[i][j]);
		}
	}
	maxR = 1;
	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++)
	{
		memset(visited, 0, sizeof(visited));
		int r = 0;

		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (height[j][k] > *iter && !visited[j][k])
				{
					dfs(j, k, *iter);
					r++;
				}
			}
		}

		maxR = max(r, maxR);
	}

	cout << maxR;

	return 0;
}

#pragma endregion