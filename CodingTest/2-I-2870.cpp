#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
	���ڰ� 100�ڸ� ���� �����ϹǷ� int Ÿ������ ó���ϴ� ���� �Ұ��� �Ͽ���.
*/

#pragma region ���� Ǯ��

bool cmp(string a, string b)
{
	if (a.size() == b.size())
	{
		return a < b;
	}
	return a.size() < b.size();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	vector<string> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s, temp;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] >= '0' && s[j] <= '9')
			{
				temp += s[j];
			}
			else if (!temp.empty())
			{
				v.push_back(temp);
				temp.clear();
			}
		}
		
		if (!temp.empty())
			v.push_back(temp);
	}

	for (int i = 0; i < v.size(); i++)
	{
		int pos = 0;
		for (int j = 0; j < v[i].size() - 1; j++)
		{
			if (v[i][j] == '0')
				pos = j + 1;
			else
				break;
		}
		v[i].erase(0, pos);
	}

	sort(v.begin(), v.end(), cmp);
	for (string i : v)
		cout << i << "\n";

	return 0;
}

#pragma endregion