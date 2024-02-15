#include <iostream>
#include <vector>

using namespace std;

/*
	[해결방안]
	범위가 제한된 누적합에 대한 문제
	슬라이딩 윈도우같은 개념이다.
*/

#pragma region 최초 풀이

//int main()
//{
//	int n, k;
//	vector<int> nums;
//	int sum = 0, ret = INT32_MIN;
//	cin >> n >> k;
//	for (int i = 0; i < n; i++)
//	{
//		int temp;
//		cin >> temp;
//		nums.push_back(temp);
//		sum += temp;
//		if (i + 1 >= k)
//		{
//			ret = max(ret, sum);
//			sum -= nums[i - k + 1];
//		}
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

#pragma endregion

#pragma region 개선

int nums[100000];
int main()
{
	int n, k;
	int sum = 0, ret = INT32_MIN;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
		sum += nums[i];
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