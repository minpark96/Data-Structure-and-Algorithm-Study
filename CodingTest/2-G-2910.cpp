#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#pragma region 최초 풀이

//struct Node
//{
//	int data;
//	int num;
//};
//
//int n, c;
//vector<Node> v;
//set<int> s;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	cin >> n >> c;
//	for (int i = 0; i < n; i++)
//	{
//		int temp;
//		bool flag = true;
//		cin >> temp;
//		for (int j = 0; j < v.size(); j++)
//		{
//			if (temp == v[j].data)
//			{
//				v[j].num++;
//				flag = false;
//				break;
//			}
//		}
//		if (flag)
//			v.push_back(Node{ temp, 1 });
//	}
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		s.insert(v[i].num);
//	}
//
//	for (auto iter = s.rbegin(); iter != s.rend(); iter++)
//	{
//		for (int i = 0; i < v.size(); i++)
//		{
//			if (*iter == v[i].num)
//			{
//				for (int k = 0; k < *iter; k++)
//					cout << v[i].data << ' ';
//			}
//		}
//	}
//	cout << "\n";
//	return 0;
//}

#pragma endregion

#pragma region 개선

int n, c;
vector<pair<int, int>> v;
map<int, int> m1, m2;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
	{
		return m2[a.second] < m2[b.second];
	}
	return a.first > b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		m1[temp]++;
		if (m2[temp] == 0)
			m2[temp] = i + 1;
	}

	for (auto iter = m1.begin(); iter != m1.end(); iter++)
	{
		v.push_back({ iter->second, iter->first });
	}

	sort(v.begin(), v.end(), cmp);
	
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].first; j++)
			cout << v[i].second << ' ';
	}
	
	cout << "\n";
	return 0;
}

#pragma endregion