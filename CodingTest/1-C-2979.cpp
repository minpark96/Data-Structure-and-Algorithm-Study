#include <iostream>

using namespace std;

#pragma region 최초 풀이
//int main()
//{
//	int charge[3];
//	int enter[3];
//	int exit[3];
//	int parked[100] = { 0, };
//	int sum = 0;
//
//	for (int i = 0; i < 3; i++)
//	{
//		cin >> charge[i];
//	}
//
//	for (int i = 0; i < 3; i++)
//	{
//		cin >> enter[i];
//		cin >> exit[i];
//	}
//
//	for (int i = 0; i < 100; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			if (enter[j] - 1 < i && exit[j] > i)
//			{
//				parked[i]++;
//			}
//		}
//
//		switch (parked[i])
//		{
//		case 1:
//			sum += charge[0] * 1;
//			break;
//		case 2:
//			sum += charge[1] * 2;
//			break;
//		case 3:
//			sum += charge[2] * 3;
//			break;
//		}
//	}
//
//	cout << sum;
//
//	return 0;
//}
#pragma endregion

#pragma region 개선 1
int main()
{
	int charge[3];
	int enter[3];
	int exit[3];
	int cnt[101] = { 0, };
	int sum = 0;

	for (int i = 0; i < 3; i++)
	{
		cin >> charge[i];
	}

	for (int i = 0; i < 3; i++)
	{
		cin >> enter[i] >> exit[i];
		for (int j = enter[i]; j < exit[i]; j++) cnt[j]++;
	}

	for (int i = 1; i < 101; i++)
	{
		if (cnt[i] == 1)
			sum += charge[0] * 1;
		else if (cnt[i] == 2)
			sum += charge[1] * 2;
		else if (cnt[i] == 3)
			sum += charge[2] * 3;
	}

	cout << sum;

	return 0;
}
#pragma endregion
