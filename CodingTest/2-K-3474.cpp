#include <iostream>
#include <map>
using namespace std;

#pragma region 최초 풀이 - 오답, 시간 초과

int t;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	map <int, int, greater<int>> mTen;
	map <int, int, greater<int>> mFive;
	map <int, int, greater<int>> mTwo;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, maxN, ten = 0, five = 0, two = 0;
		cin >> n;

		auto iter = mTen.lower_bound(n);
		if (iter != mTen.end())
			maxN = iter->first;
		else
			maxN = 1;
		for (int j = n; j > maxN; j--)
		{
			int k = j;
			while (true)
			{
				if (k % 10 == 0)
				{
					k /= 10;
					ten++;
				}
				else if (k % 5 == 0)
				{
					k /= 5;
					five++;
				}
				else if (k % 2 == 0)
				{
					k /= 2;
					two++;
				}
				else
				{
					if (five && two)
					{
						int temp = min(five, two);
						ten += temp;
						five -= temp;
						two -= temp;
					}
					break;
				}
			}
		}

		ten += mTen[maxN];
		five += mFive[maxN];
		two += mTwo[maxN];
		if (five && two)
		{
			int temp = min(five, two);
			ten += temp;
			five -= temp;
			two -= temp;
		}

		cout << ten << "\n";
		mTen[n] = ten;
		mFive[n] = five;
		mTwo[n] = two;
	}
	return 0;
}

#pragma endregion