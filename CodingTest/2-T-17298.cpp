#include <iostream>
#include <stack>
using namespace std;

/*
	짝짓기 문제로 볼 수 있다. 다만 1:1 짝짓기가 아닌 1:다 짝짓기이므로 고려해야한다.
*/

#pragma region 최초풀이 - 힌트 참조

//int n, ret[1000004];
//stack<int> stk1, stk2;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//	fill(&ret[0], &ret[0] + 1000004, -1);
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int t;
//		cin >> t;
//		stk1.push(t);
//	}
//
//	for (int i = n - 1; i >= 0; i--)
//	{
//		while (!stk2.empty())
//		{
//			if (stk2.top() > stk1.top())
//			{
//				ret[i] = stk2.top();
//				break;
//			}
//			else stk2.pop();
//		}
//		stk2.push(stk1.top());
//		stk1.pop();
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << ret[i] << " ";
//	}
//	cout << "\n";
//
//	return 0;
//}

#pragma endregion

#pragma region 개선 - 스택 1개로

int n, a[1000004], ret[1000004];
int main()
{
	stack<int> stk;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(&ret[0], &ret[0] + 1000004, -1);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

		while (!stk.empty() && a[stk.top()] < a[i])
		{
			ret[stk.top()] = a[i];
			stk.pop();
		}
		stk.push(i);
	}

	for (int i = 0; i < n; i++)
	{
		cout << ret[i] << " ";
	}
	cout << "\n";

	return 0;
}

#pragma endregion