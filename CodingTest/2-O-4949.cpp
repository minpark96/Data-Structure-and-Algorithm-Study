#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
	이전 문제에서 조건 한두개만 더 붙이면 되는 간단한 문제
*/
#pragma region 최초 풀이

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	while (true)
	{
		string s;
		int flag = true;
		stack<char> sta;
		getline(cin, s);
		if (s == ".") break;
		for (int j = 0; j < s.size(); j++)
		{
			char ch = s[j];
			if (s[j] == '(' || s[j] == '[')
			{
				sta.push(s[j]);
			}
			else if (s[j] == ')' || s[j] == ']')
			{
				if (!sta.empty())
				{
					char temp = sta.top();
					sta.pop();
					if ((temp == '[' && s[j] == ')') || (temp == '(' && s[j] == ']'))
					{
						flag = false;
						break;
					}
				}
				else
				{
					flag = false;
					break;
				}
			}
		}
		if (flag && sta.empty())
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}

#pragma endregion