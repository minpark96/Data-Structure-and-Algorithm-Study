#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 1. A�� B�� ������ Ȧ���� �ȵ�
// 2. A�� �̰� ���� ���� B�� �������� �� B�� ��Ī�Ǳ����� A�� ������ �ȵ�

int main()
{
	int cnt, ret = 0;

	cin >> cnt;
	while (cnt > 0)
	{
		string str;
		stack<char> sta;
		cin >> str;
		for (char ch : str)
		{
			if (!sta.empty())
			{
				char temp = sta.top();
				if (temp == ch)
					sta.pop();
				else
					sta.push(ch);
			}
		}

		if (sta.empty())
			ret++;
	}

	cout << ret << "\n";

	return 0;
}