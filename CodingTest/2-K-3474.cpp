#include <iostream>
#include <map>
using namespace std;

/*
	- 규칙 찾기 문제 -
	오른쪽 0의 개수는 약수 중 10의 제곱의 최대 값을 찾는거라서
	주어진 수를 소인수 분해해서 나오는 2의 지수의 값과 5의 지수의 값 중 작은 값이 10의 제곱의 지수이다.
	근데 2의 지수의 총합은 결국 주어진 수를 2의 제곱수(2, 4, 8 ...)로 각각 나눴을 때 나오는 몫의 총합, 
	5의 지수의 총합은 5의 제곱수(5, 25, 125 ...)로 각각 나눴을 때 나오는 몫을 모두 더한 값이라는 규칙을 발견하지 못하였다.
*/

#pragma region 최초 풀이 - 오답, 시간 초과

//int t;
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	map <int, int, greater<int>> mTen;
//	map <int, int, greater<int>> mFive;
//	map <int, int, greater<int>> mTwo;
//	cin >> t;
//	for (int i = 0; i < t; i++)
//	{
//		int n, maxN, ten = 0, five = 0, two = 0;
//		cin >> n;
//
//		auto iter = mTen.lower_bound(n);
//		if (iter != mTen.end())
//			maxN = iter->first;
//		else
//			maxN = 1;
//		for (int j = n; j > maxN; j--)
//		{
//			int k = j;
//			while (true)
//			{
//				if (k % 10 == 0)
//				{
//					k /= 10;
//					ten++;
//				}
//				else if (k % 5 == 0)
//				{
//					k /= 5;
//					five++;
//				}
//				else if (k % 2 == 0)
//				{
//					k /= 2;
//					two++;
//				}
//				else
//				{
//					if (five && two)
//					{
//						int temp = min(five, two);
//						ten += temp;
//						five -= temp;
//						two -= temp;
//					}
//					break;
//				}
//			}
//		}
//
//		ten += mTen[maxN];
//		five += mFive[maxN];
//		two += mTwo[maxN];
//		if (five && two)
//		{
//			int temp = min(five, two);
//			ten += temp;
//			five -= temp;
//			two -= temp;
//		}
//
//		cout << ten << "\n";
//		mTen[n] = ten;
//		mFive[n] = five;
//		mTwo[n] = two;
//	}
//	return 0;
//}

#pragma endregion

#pragma region 최초 풀이 - 정답 참조

int t;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, five = 0, two = 0;
		cin >> n;

		for (int i = 2; i <= n; i *= 2)
		{
			two += n / i;
		}
		for (int i = 5; i <= n; i *= 5)
		{
			five += n / i;
		}

		cout << min(five, two) << "\n";
	}
	return 0;
}

#pragma endregion