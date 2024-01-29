#include <iostream>
#include <string>

using namespace std;

#pragma region 최초 풀이

int main()
{
	int num;
	cin >> num;
	string pat, str;
	bool ret[100];
	cin >> pat;

	for (int i = 0; i < num; i++)
	{
		cin >> str;

		for (int j = 0; j < pat.size(); j++)
		{
			if (pat[j] != '*')
			{
				if (str[0] == pat[0] && str[str.size() - 1] == pat[2])
					ret[i] = true;
				else
					ret[i] = false;

			}
			else
			{

			}

		}
	}

	for (int j = 0; j < num; j++)
	{
		if (ret[j])
			cout << "DA" << "\n";
		else
			cout << "NE" << "\n";
	}

	return 0;
}

#pragma endregion
