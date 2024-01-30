#include <iostream>
#include <string>

using namespace std;

#pragma region 최초 풀이 - 오답

//int main()
//{
//	int num;
//	cin >> num;
//	string pat, str;
//	bool ret[101] = { false, };
//	cin >> pat;
//	string postfix, prefix;
//	for (int j = 0; j < pat.size(); j++)
//	{
//		if (pat[j] != '*')
//		{
//			postfix += pat[j];
//		}
//		else
//		{
//			prefix = postfix;
//			postfix.clear();
//		}
//	}
//
//	for (int i = 0; i < num; i++)
//	{
//		cin >> str;
//		size_t n = str.find(prefix, 0);
//		if (n != 0)	continue;
//		n = str.find(postfix, str.size() - postfix.size());
//		if (n != str.size() - postfix.size()) continue;
//
//		ret[i] = true;
//	}
//
//	for (int j = 0; j < num; j++)
//	{
//		if (ret[j])
//			cout << "DA" << "\n";
//		else
//			cout << "NE" << "\n";
//	}
//
//	return 0;
//}

#pragma endregion

#pragma region 최초 풀이 - 정답

int main()
{
	int num;
	cin >> num;
	string pat, str;
	bool ret[100] = { false, };
	cin >> pat;

	string postfix, prefix;
	for (size_t j = 0; j < pat.size(); j++)
	{
		if (pat[j] != '*')
		{
			postfix += pat[j];
		}
		else
		{
			prefix = postfix;
			postfix.clear();
		}
	}

	for (int i = 0; i < num; i++)
	{
		cin >> str;
		if (str.size() < prefix.size() + postfix.size())
			continue;
		size_t n = str.find(prefix, 0);
		if (n != 0)
			continue;
		n = str.find(postfix, str.size() - postfix.size());
		if (n != str.size() - postfix.size())
			continue;

		ret[i] = true;
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
