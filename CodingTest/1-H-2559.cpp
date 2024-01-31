#include <iostream>
#include <vector>

using namespace std;

#pragma region 최초 풀이

int main()
{
	int n, k;
	vector<int> nums;
	int sum = 0, ret = INT32_MIN;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
		sum += temp;
		if (i + 1 >= k)
		{
			ret = max(ret, sum);
			sum -= nums[i - k + 1];
		}
	}

	cout << ret << "\n";

	return 0;
}

#pragma endregion