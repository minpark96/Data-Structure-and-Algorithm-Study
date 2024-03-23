#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
	스택 개념만 사용하면 되는 간단한 문제
	사칙 연산 계산기 구현에 비하면 엄청 간단한 문제이다.
*/
#pragma region 최초 풀이

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	string s;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int flag = true;
		stack<char> sta;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			char ch = s[j];
			if (s[j] == '(')
			{
				sta.push(s[j]);
			}
			else
			{
				if (!sta.empty())
				{
					sta.pop();
				}
				else
				{
					flag = false;
					break;
				}
			}
		}
		if (flag && sta.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}

#pragma endregion