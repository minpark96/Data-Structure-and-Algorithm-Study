#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

/*
	dfs�� bfs�� ���� ������ �ƴϰ�
	Divide & Conquer�� ���� �����̴�.
	�ɰ��� �ذ��ϴ� ���� ����Լ��� ���� �����Ѵ�.
	
	ó���� ���δ� �ɰ��� �ذ��Ϸ� ������, �ɰ��� ���� ������ �����ϴ��� üũ�� �ʿ䰡 �־���.
*/

#pragma region ���� Ǯ�� - ���� ����

//int n, a[66][66];
//string ret;
//
//bool dfs(int ly, int lx, int ry, int rx)
//{
//	int temp = a[ly][lx];
//	for (int i = ly; i < ry; i++)
//	{
//		for (int j = lx; j < rx; j++)
//		{
//			if (temp != a[i][j])
//				return false;
//		}
//	}
//
//	return true;
//}
//
//string qt(int ly, int lx, int ry, int rx)
//{
//	if (ry - ly < 2)
//		return to_string(a[ly][lx]);
//
//	if (dfs(ly, lx, ry, rx))
//	{
//		return to_string(a[ly][lx]);
//	}
//	else
//	{
//		string ret1 = qt(ly, lx, (ly + ry) / 2, (lx + rx) / 2);
//		string ret2 = qt(ly, (lx + rx) / 2, (ly + ry) / 2, rx);
//		string ret3 = qt((ly + ry) / 2, lx, ry, (lx + rx) / 2);
//		string ret4 = qt((ly + ry) / 2, (lx + rx) / 2, ry, rx);
//		return '(' + ret1 + ret2 + ret3 + ret4 + ')';
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			scanf("%1d", &a[i][j]);
//		}
//	}
//
//	ret = qt(0, 0, n, n);
//	cout << ret << "\n";
//
//	return 0;
//}

#pragma endregion

#pragma region ����

int n, a[66][66];

string qt(int y, int x, int size)
{
	if (size == 1)
		return to_string(a[y][x]);
	
	string ret = "";
	char temp = a[y][x];
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (temp != a[i][j])
			{
				ret += '(';
				ret += qt(y, x, size / 2);
				ret += qt(y, x + size / 2, size / 2);
				ret += qt(y + size / 2, x, size / 2);
				ret += qt(y + size / 2, x + size / 2, size / 2);
				ret += ')';
				return ret;
			}
		}
	}

	return to_string(a[y][x]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}
	
	cout << qt(0, 0, n) << "\n";

	return 0;
}

#pragma endregion