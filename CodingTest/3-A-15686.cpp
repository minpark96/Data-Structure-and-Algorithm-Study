#include <iostream>
#include <vector>
using namespace std;

/*
	�����ϰ� Ǯ�� �ȴ�.
	bfs���� �ʿ���µ� �Ÿ��� bfs�� ���Ϸ��� �ߴ�. ������ ���ϴ� ����� ���ϴ°� �������.
*/

#pragma region ���� Ǯ��

int n, m, a[54][54];
int min_ret = 2147483647;
vector<pair<int, int>> h, c;
vector<int> v;

void comb(int curr)
{
	if (v.size() == m)
	{
		int sum = 0;
		for (pair<int, int> p : h)
		{
			int temp = 2147483647;
			for (int z : v)
			{
				temp = min(temp, abs(p.first - c[z].first) + abs(p.second - c[z].second));
			}
			sum += temp;
		}
		min_ret = min(min_ret, sum);
		return;
	}
	for (int i = curr; i < c.size(); i++)
	{
		v.push_back(i);
		comb(i + 1);
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
			if (a[i][j] == 1) h.push_back({ i, j });
			else if (a[i][j] == 2) c.push_back({ i, j });
		}
	}
	comb(0);
	cout << min_ret << "\n";
	return 0;
}

#pragma endregion