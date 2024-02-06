#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#pragma region 최초 풀이

int nums[15001];
int main()
{
	int n, m;
	int ret = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

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

	return 0;
}

#pragma endregion