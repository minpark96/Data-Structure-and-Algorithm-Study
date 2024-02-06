#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

#pragma region ���� Ǯ��

//int main()
//{
//	int alpha[26] = { 0, };
//	string str, ret;
//	cin >> str;
//
//	for (int i = 0; i < str.size(); i++)
//	{
//		alpha[str[i] - 'A']++;
//	}
//
//	for (int j = 0; j < 26; j++)
//	{
//		// ���� ����
//		for (int k = alpha[j] / 2; k > 0; k--)
//		{
//			ret += 'A' + j;
//		}
//	}
//
//	for (int j = 0; j < 26; j++)
//	{
//		// �߰��� ���� ����
//		if (alpha[j] % 2)
//		{
//			ret += 'A' + j;
//		}
//	}
//
//	for (int j = 25; j >= 0; j--)
//	{
//		// ������ ����
//		for (int k = alpha[j] / 2; k > 0; k--)
//		{
//			ret += 'A' + j;
//		}
//	}
//
//	string ret2 = ret;
//	reverse(ret2.begin(), ret2.end());
//
//	if (ret2 != ret)
//		cout << "I'm Sorry Hansoo\n";
//	else
//		cout << ret << "\n";
//
//	return 0;
//}

#pragma endregion

#pragma region ���� - �߰� ����

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int alpha[100] = { 0, };
	string str, ret;
	char mid = NULL;
	int flag = 0;
	cin >> str;

	for (char ch : str)
	{
		alpha[ch]++;
	}

	for (int i = 'Z'; i >= 'A'; i--)
	{
		if (alpha[i])
		{
			if (alpha[i] & 1) // Ȧ�� ��
			{
				mid = char(i);
				flag++;
				alpha[i]--;
			}

			if (flag == 2)
				break;

			for (int j = 0; j < alpha[i]; j += 2)
			{
				ret = char(i) + ret;
				ret += char(i);
			}
		}
	}

	if (flag == 2)
		cout << "I'm Sorry Hansoo\n";
	else
	{
		if (mid) ret.insert(ret.begin() + ret.size() / 2, mid);

		cout << ret << "\n";
	}

	return 0;
}

#pragma endregion
