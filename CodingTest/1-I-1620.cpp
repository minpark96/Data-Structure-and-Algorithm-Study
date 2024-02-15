#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
	[해결방법]
	탐색 시간 때문에 map을 사용해야한다.
	map의 탐색 시간복잡도는 O(logN)이다
	입력을 정수도 문자열로 받기 때문에 문자열->정수처리가 필요하다.
	atoi, c_str을 사용하는데 stoi하나만 사용해도 될 것 같다.
*/

#pragma region 최초 풀이 - 정답 참고

//string names[100001];
//string answers[100001];
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//	map <string, int> m_s;
//	int n, m;
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++)
//	{
//		string temp;
//		cin >> temp;
//		names[i + 1] = temp;
//		m_s[temp] = i + 1;
//	}
//
//	for (int j = 0; j < m; j++)
//	{
//		cin >> answers[j];
//		if (answers[j][0] < 'A')
//		{
//			int temp = stoi(answers[j]);
//			cout << names[temp] << "\n";
//		}
//		else
//		{
//			cout << m_s[answers[j]] << "\n";
//		}
//	}
//
//	return 0;
//}

#pragma endregion

#pragma region 개선 - atoi(), c_str() 사용

string str;
string names[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	map <string, int> m_s;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		names[i + 1] = str;
		m_s[str] = i + 1;
	}

	for (int j = 0; j < m; j++)
	{
		cin >> str;
		if (atoi(str.c_str()) == 0)
		{
			cout << m_s[str] << "\n";
		}
		else
		{
			int temp = atoi(str.c_str());
			cout << names[temp] << "\n";
		}
	}

	return 0;
}

#pragma endregion