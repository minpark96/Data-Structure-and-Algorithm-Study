#include <iostream>

using namespace std;

/*
	��ũ�� ũ�Ⱑ �������ְ� �ٱ��ϰ� �̵��ϸ� ����� �ϳ��� �������� ���̰� ������ �޴´�.
	������ �����ϱ� �������.
*/

#pragma region ���� Ǯ��

//int n, m, j;
//int s[15], bl, br, ret, pos;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	cin >> n >> m;
//	cin >> j;
//
//	bl = 1;
//	br = m;
//	for (int i = 0; i < j; i++)
//	{
//		cin >> pos;
//		for (int j = 1; j < 15; j++)
//		{
//			if (j >= bl && j <= br)
//				s[j] = 1;
//			else
//				s[j] = 0;
//		}
//
//		if (s[pos] == 1) continue;
//		else
//		{
//			if (pos < bl)
//			{
//				ret += (bl - pos);
//				br -= (bl - pos);
//				bl = pos;
//			}
//			else
//			{
//				ret += (pos - br);
//				bl += (pos - br);
//				br = pos;
//			}
//		}
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

#pragma endregion

#pragma region ����

int n, m, j;
int bl, br, ret, pos;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> j;
	bl = 1;
	for (int i = 0; i < j; i++)
	{
		cin >> pos;
		br = bl + m - 1;
		if (pos >= bl && pos <= br) continue;
		else
		{
			if (pos < bl)
			{
				ret += (bl - pos);
				bl = pos;
			}
			else
			{
				ret += (pos - br);
				bl += (pos - br);
			}
		}
	}
	cout << ret << "\n";
	return 0;
}

#pragma endregion