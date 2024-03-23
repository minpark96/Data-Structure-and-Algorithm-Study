#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
	���� ���丸 ����ϸ� �Ǵ� ������ ����
	��Ģ ���� ���� ������ ���ϸ� ��û ������ �����̴�.
*/
#pragma region ���� Ǯ��

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