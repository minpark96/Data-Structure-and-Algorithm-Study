#include <iostream>
#include <string>
using namespace std;

#pragma region 최초 풀이
int main()
{
	int num;
	cin >> num;
	int cnt[26] = { 0, };
	string str;
	bool canPlaying = false;
	for (int i = 0; i < num; i++)
	{
		cin >> str;
		cnt[str[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] > 4)
		{
			cout << (char)(i + 'a');
			canPlaying = true;
		}
	}

	if (!canPlaying)
		cout << "PREDAJA";

	return 0;
}
#pragma endregion

#pragma region 개선
int main()
{
	int num;
	cin >> num;
	int cnt[26] = { 0, };
	string str, ret;
	bool canPlaying = false;
	for (int i = 0; i < num; i++)
	{
		cin >> str;
		cnt[str[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] > 4) ret += i + 'a';
	}

	if (ret.size())
		cout << ret;
	else
		cout << "PREDAJA";

	return 0;
}
#pragma endregion