#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 1. A�� B�� ������ Ȧ���� �ȵ�
// 2. A�� �̰� ���� ���� B�� �������� �� B�� ��Ī�Ǳ����� A�� ������ �ȵ�
#pragma region ���� Ǯ��

//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//	int cnt, ret = 0;
//
//	cin >> cnt;
//	while (cnt > 0)
//	{
//		string str;
//		stack<char> sta;
//		cin >> str;
//		for (char ch : str)
//		{
//			char temp = NULL;
//			if (!sta.empty())
//				temp = sta.top();
//			if (temp == ch)
//				sta.pop();
//			else
//				sta.push(ch);
//		}
//
//		if (sta.empty())
//			ret++;
//		cnt--;
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

#pragma endregion

#pragma region ����

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int cnt, ret = 0;

	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		string str;
		stack<char> sta;
		cin >> str;
		for (char ch : str)
		{
			if (!sta.empty() && sta.top() == ch)
				sta.pop();
			else
				sta.push(ch);
		}

		if (sta.empty())
			ret++;
	}

	cout << ret << "\n";

	return 0;
}

#pragma endregion