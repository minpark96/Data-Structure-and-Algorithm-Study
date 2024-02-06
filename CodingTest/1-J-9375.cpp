#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#pragma region 최초 풀이 - 정답 참고

//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	int tNum;
//	// 테스트 케이스 수
//	cin >> tNum;
//
//	for (int i = 0; i < tNum; i++)
//	{
//		map<string, int> m_Wears;
//		vector<string> wears;
//		pair<map<string, int>::iterator, bool> a;
//		// 의상 수
//		int nNum;
//		cin >> nNum;
//		
//		// 의상 입력
//		for (int j = 0; j < nNum; j++)
//		{
//			string str1, str2;
//			cin >> str1 >> str2;
//			a = m_Wears.insert({ str2, 1 });
//			if (!a.second)
//				a.first->second++;
//			else
//				wears.push_back(str2);
//		}
//
//		int sum = 1;
//
//		for (int k = 0; k < m_Wears.size(); k++)
//		{
//			sum *= m_Wears[wears[k]] + 1;
//		}
//
//		if (sum == 0)
//			cout << sum << "\n";
//		else
//			cout << sum - 1 << "\n";
//	}
//
//	return 0;
//}

#pragma endregion

#pragma region 개선

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tNum;
	// 테스트 케이스 수
	cin >> tNum;

	for (int i = 0; i < tNum; i++)
	{
		map<string, int> m_Wears;
		// 의상 수
		int nNum;
		cin >> nNum;

		// 의상 입력
		for (int j = 0; j < nNum; j++)
		{
			string str1, str2;
			cin >> str1 >> str2;
			m_Wears[str2]++;
		}

		long long sum = 1;

		for (auto n : m_Wears)
		{
			sum *= (long long)n.second + 1;
		}

		sum--;
		cout << sum << "\n";
	}

	return 0;
}

#pragma endregion