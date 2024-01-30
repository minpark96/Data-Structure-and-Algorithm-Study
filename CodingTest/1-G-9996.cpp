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

//int main()
//{
//	int num;
//	cin >> num;
//	string pat, str;
//	bool ret[100] = { false, };
//	cin >> pat;
//
//	string postfix, prefix;
//	for (size_t j = 0; j < pat.size(); j++)
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
//		if (str.size() < prefix.size() + postfix.size())
//			continue;
//		size_t n = str.find(prefix, 0);
//		if (n != 0)
//			continue;
//		n = str.find(postfix, str.size() - postfix.size());
//		if (n != str.size() - postfix.size())
//			continue;
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

#pragma region 개선 1 - substr() 사용

//int main()
//{
//	int num;
//	cin >> num;
//	string pat, str;
//	cin >> pat;
//	bool ret[101] = { false, };
//	size_t pos = pat.find('*');
//	string pre = pat.substr(0, pos);
//	string suf = pat.substr(pos + 1);
//
//	for (int i = 0; i < num; i++)
//	{
//		cin >> str;
//		if (str.size() < pre.size() + suf.size())
//			continue;
//		string temp = str.substr(0, pre.size());
//		if (temp != pre) continue;
//		temp.clear();
//		temp = str.substr(str.size() - suf.size(), str.size());
//		if (temp != suf) continue;
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

#pragma region 개선 2 - substr() 코드 개선

int main()
{
	int num;
	cin >> num;
	string pat, str;

	cin >> pat;
	size_t pos = pat.find('*');
	string pre = pat.substr(0, pos);
	string suf = pat.substr(pos + 1);

	for (int i = 0; i < num; i++)
	{
		cin >> str;

		if (str.size() < pre.size() + suf.size()) cout << "NE" << "\n";
		else
		{
			if (pre == str.substr(0, pre.size()) && suf == str.substr(str.size() - suf.size()))
				cout << "DA" << "\n";
			else
				cout << "NE" << "\n";
		}
	}

	return 0;
}

#pragma endregion