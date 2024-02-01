#include <iostream>
#include <string>
#include <map>

using namespace std;

#pragma region 최초 풀이

string names[100001];
string answers[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	map <string, int> m_s;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		names[i + 1] = temp;
		m_s[temp] = i + 1;
	}

	for (int j = 0; j < m; j++)
	{
		cin >> answers[j];
		if (answers[j][0] < 'A')
		{
			int temp = stoi(answers[j]);
			cout << names[temp] << "\n";
		}
		else
		{
			cout << m_s[answers[j]] << "\n";
		}
	}

	return 0;
}

#pragma endregion