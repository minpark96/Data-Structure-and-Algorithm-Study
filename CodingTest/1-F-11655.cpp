#include <iostream>
#include <string>
using namespace std;

/*
	[�ذ���]
	�ƽ�Ű�ڵ带 ����ϴµ� ������ ��� �Ϳ� ���� ����ó���� �ʿ��ϴ�.
*/

#pragma region ���� Ǯ��

int main()
{
	string str;

	getline(cin, str);

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] += 13;
			if (str[i] > 90)
				str[i] -= 26;
		}
		else if (str[i] >= 97 && str[i] <= 122)
		{
			if (str[i] + 13 > 122)
				str[i] -= 13;
			else
				str[i] += 13;
		}
	}

	cout << str;

	return 0;
}

#pragma endregion
