#include <iostream>
#include <stack>
using namespace std;

#pragma region 최초풀이 - 힌트 참조

int n, ret[1000004];
stack<int> stk1, stk2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		stk1.push(t);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		while (true)
		{
			if (stk2.empty())
			{
				ret[i] = -1;
				stk2.push(stk1.top());
				stk1.pop();
				break;
			}
			else
			{
				if (stk2.top() > stk1.top())
				{
					ret[i] = stk2.top();
					stk2.push(stk1.top());
					stk1.pop();
					break;
				}
				else
				{
					stk2.pop();
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << ret[i] << " ";
	}
	cout << "\n";

	return 0;
}

#pragma endregion