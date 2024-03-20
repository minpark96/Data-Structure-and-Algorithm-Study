#include <iostream>
#include <string>
using namespace std;

#pragma region 최초 풀이

char vowel[] = { 'a', 'e', 'i', 'o', 'u' };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string end = "end";

	while (true)
	{
		string str;
		bool hasV = false, isC = false, wasV = false, isAcc = true;
		char prev = NULL;
		cin >> str;
		if (str == end) break;

		for (int i = 0; i < str.length(); i++)
		{
			bool isV = false;
			for (int j = 0; j < 5; j++)
			{
				if (str[i] == vowel[j])
				{
					hasV = true;
					isV = true;
					break;
				}
			}
			
			if (prev == str[i])
			{
				if (prev != 'e' && prev != 'o')
				{
					isAcc = false;
					break;
				}
			}

			if (isV && wasV && isC)
			{
				isAcc = false;
				break;
			}
			else if (!isV && !wasV && isC)
			{
				isAcc = false;
				break;
			}
			else if (isV && wasV && i != 0)
				isC = true;
			else if (!isV && !wasV && i != 0)
				isC = true;
			else
				isC = false;
			
			wasV = isV;
			prev = str[i];
		}

		if (isAcc && hasV)
		{
			cout << '<' << str << "> is acceptable." << "\n";
			continue;
		}

		cout << '<' << str << "> is not acceptable." << "\n";
	}

	return 0;
}

#pragma endregion