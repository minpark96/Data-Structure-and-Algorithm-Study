#include <iostream>
#include <string>
using namespace std;

/*
	[해결방안]
	아스키코드를 사용하는데 범위를 벗어난 것에 대한 예외처리가 필요하다.
*/

#pragma region 최초 풀이

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
