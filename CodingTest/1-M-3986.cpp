#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 1. A나 B의 개수가 홀수면 안됨
// 2. A를 뽑고 다음 것이 B가 나왔으면 그 B가 매칭되기전에 A가 나오면 안됨
#pragma region 최초 풀이

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

#pragma region 개선

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