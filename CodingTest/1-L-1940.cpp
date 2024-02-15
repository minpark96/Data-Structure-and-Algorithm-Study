#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
	[해결방안]
	정렬하고 나서 두 개의 합이 답이 되는 경우를 찾는다.
	정렬을 하면 조건을 좀 더 좁힐 수 있다고 생각하였다.
*/

#pragma region 최초 풀이

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

#pragma region 개선

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