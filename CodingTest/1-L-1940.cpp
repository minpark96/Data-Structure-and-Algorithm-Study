#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
	[�ذ���]
	�����ϰ� ���� �� ���� ���� ���� �Ǵ� ��츦 ã�´�.
	������ �ϸ� ������ �� �� ���� �� �ִٰ� �����Ͽ���.
*/

#pragma region ���� Ǯ��

//int nums[15001];
//int main()
//{
//	int n, m;
//	int ret = 0;
//
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> nums[i];
//	}
//
//	sort(nums, nums + n);
//	nums[n] = INT32_MAX;
//
//	for (int j = 0; nums[j] < m; j++)
//	{
//		for (int k = j + 1; k < n; k++)
//		{
//			if (nums[j] + nums[k] == m) ret++;
//			else if (nums[j] + nums[k] > m) break;
//		}
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

#pragma endregion

#pragma region ����

int nums[15001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	int ret = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	if (m > 200000)
		cout << 0 << "\n";
	else
	{
		sort(nums, nums + n);
		nums[n] = INT32_MAX;
		for (int j = 0; nums[j] < m; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (nums[j] + nums[k] == m) ret++;
				else if (nums[j] + nums[k] > m) break;
			}
		}

		cout << ret << "\n";
	}

	return 0;
}

#pragma endregion